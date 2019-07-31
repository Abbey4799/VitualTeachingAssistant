#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <errno.h>
#include <process.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include "qisr.h"
#include "qtts.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "speech_recognizer.h"
#include "iat_record_sample.h"

#ifdef _WIN64
#pragma comment(lib,"C:/msc_x64.lib")//x64
#else
#pragma comment(lib,"C:/msc.lib")//x86
#endif

#include <QDebug>
#define printf qDebug
using namespace std;

/* wav音频头部格式 */
typedef struct _wave_pcm_hdr
{
	char            riff[4];                // = "RIFF"
	int				size_8;                 // = FileSize - 8
	char            wave[4];                // = "WAVE"
	char            fmt[4];                 // = "fmt "
	int				fmt_size;				// = 下一个结构体的大小 : 16

	short int       format_tag;             // = PCM : 1
	short int       channels;               // = 通道数 : 1
	int				samples_per_sec;        // = 采样率 : 8000 | 6000 | 11025 | 16000
	int				avg_bytes_per_sec;      // = 每秒字节数 : samples_per_sec * bits_per_sample / 8
	short int       block_align;            // = 每采样点字节数 : wBitsPerSample / 8
	short int       bits_per_sample;        // = 量化比特数: 8 | 16

	char            data[4];                // = "data";
	int				data_size;              // = 纯数据长度 : FileSize - 44
} wave_pcm_hdr;

/* 默认wav音频头部数据 */
wave_pcm_hdr default_wav_hdr =
{
	{ 'R', 'I', 'F', 'F' },
	0,
	{'W', 'A', 'V', 'E'},
	{'f', 'm', 't', ' '},
	16,
	1,
	1,
	16000,
	32000,
	2,
	16,
	{'d', 'a', 't', 'a'},
	0
};

static COORD begin_pos = { 0, 0 };
static COORD last_pos = { 0, 0 };

BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)
{
    // Get the required size of the buffer that receives the Unicode
    // string.
    DWORD dwMinSize;
    dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, nullptr, 0);
    assert(dwSize >= dwMinSize);

    // Convert headers from ASCII to Unicode.
    MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);
    return TRUE;
}
/* 文本合成 */
int text_to_speech(const char* src_text, const char* des_path, const char* params)
{
    int          ret = -1;
    FILE* fp = nullptr;
    const char* sessionID = nullptr;
    unsigned int audio_len = 0;
    wave_pcm_hdr wav_hdr = default_wav_hdr;
    int          synth_status = MSP_TTS_FLAG_STILL_HAVE_DATA;

    if (nullptr == src_text || nullptr == des_path)
    {
        printf("params is error!\n");
        return ret;
    }
    //fp = fopen(des_path, "wb");
    errno_t err = fopen_s(&fp, des_path, "wb");
    if (nullptr == fp)
    {
        printf("open %s error.\n", des_path);
        return ret;
    }
    /* 开始合成 */
    sessionID = QTTSSessionBegin(params, &ret);
    if (MSP_SUCCESS != ret)
    {
        printf("QTTSSessionBegin failed, error code: %d.\n", ret);
        fclose(fp);
        return ret;
    }
    ret = QTTSTextPut(sessionID, src_text, (unsigned int)strlen(src_text), nullptr);
    if (MSP_SUCCESS != ret)
    {
        printf("QTTSTextPut failed, error code: %d.\n", ret);
        QTTSSessionEnd(sessionID, "TextPutError");
        fclose(fp);
        return ret;
    }
    printf("正在合成 ...\n");
    fwrite(&wav_hdr, sizeof(wav_hdr), 1, fp); //添加wav音频头，使用采样率为16000
    while (1)
    {
        /* 获取合成音频 */
        const void* data = QTTSAudioGet(sessionID, &audio_len, &synth_status, &ret);
        if (MSP_SUCCESS != ret)
            break;
        if (nullptr != data)
        {
            fwrite(data, audio_len, 1, fp);
            wav_hdr.data_size += audio_len; //计算data_size大小
        }
        if (MSP_TTS_FLAG_DATA_END == synth_status)
            break;
    }
    printf("\n");
    if (MSP_SUCCESS != ret)
    {
        printf("QTTSAudioGet failed, error code: %d.\n", ret);
        QTTSSessionEnd(sessionID, "AudioGetError");
        fclose(fp);
        return ret;
    }
    /* 修正wav文件头数据的大小 */
    wav_hdr.size_8 += wav_hdr.data_size + (sizeof(wav_hdr) - 8);

    /* 将修正过的数据写回文件头部,音频文件为wav格式 */
    fseek(fp, 4, 0);
    fwrite(&wav_hdr.size_8, sizeof(wav_hdr.size_8), 1, fp); //写入size_8的值
    fseek(fp, 40, 0); //将文件指针偏移到存储data_size值的位置
    fwrite(&wav_hdr.data_size, sizeof(wav_hdr.data_size), 1, fp); //写入data_size的值
    fclose(fp);
    fp = nullptr;
    /* 合成完毕 */
    ret = QTTSSessionEnd(sessionID, "Normal");
    if (MSP_SUCCESS != ret)
    {
        printf("QTTSSessionEnd failed, error code: %d.\n", ret);
    }

    return ret;
}

/* 从控制台输出【语音识别】结果
static void show_result(char* string, char is_over)
{
    COORD current;
    CONSOLE_SCREEN_BUFFER_INFO info;			// 控制台窗口信息结构体
    HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);	// 获得输入、输出/错误的屏幕缓冲区的句柄。
    GetConsoleScreenBufferInfo(w, &info);
    current = info.dwCursorPosition;

    if (current.X == last_pos.X && current.Y == last_pos.Y) {
        SetConsoleCursorPosition(w, begin_pos);
    }
    else {
        // changed by other routines, use the new pos as start 
        begin_pos = current;
    }
    if (is_over)
        SetConsoleTextAttribute(w, FOREGROUND_GREEN);	// 设置颜色
    printf("Result: [ %s ]\n", string);
    if (is_over)
        SetConsoleTextAttribute(w, info.wAttributes);

    GetConsoleScreenBufferInfo(w, &info);
    last_pos = info.dwCursorPosition;
}*/