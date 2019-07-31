/*语音识别（从文件）*/
#include "service_3_f.h"
#include "ui_service_3_f.h"
#include "service_3.h"

#include <QString>
#include <string>
#include <QTextCodec>
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

#define FRAME_LEN	640
#define	BUFFER_SIZE	4096
#define MAX_LEN 102
#define HINTS_SIZE  100

int key = 0;

service_3_F::service_3_F(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::service_3_F)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

	ui->textBrowser->resize(400, 40);
	ui->textBrowser->move(150, 75);

	ui->wavAddress->resize(250, 50);
	ui->wavAddress->move(150, 160);

	ui->input_OK->resize(100, 50);
	ui->input_OK->move(450, 160);

	ui->output->resize(400, 40);
	ui->output->move(150, 245);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));

	int	ret = MSP_SUCCESS;
	const char* login_params = "appid = 5afaf149, work_dir = ."; // 登录参数，appid与msc库绑定,请勿随意改动

	int aud_src = 0;
	double accuracy_rate = 0.0;
	int flag = 0;

	/* 用户登录 */
	ret = MSPLogin(nullptr, nullptr, login_params); //第一个参数是用户名，第二个参数是密码，均传nullptr即可，第三个参数是登录参数
	if (MSP_SUCCESS != ret) {
		printf("MSPLogin failed , Error code %d.\n", ret);
		//登录失败，退出登录
		flag = 1;
		MSPLogout();
		quitS3_F();
	}
}

service_3_F::~service_3_F()
{
    delete ui;
}

void service_3_F::quitS3_F()
{
	this->close();
}

void service_3_F::on_input_OK_clicked()
{
	QString Text;
	std::string temp;
	const char* audio_file;

	Text = ui->wavAddress->text();
	temp = Text.toStdString();
	audio_file = temp.c_str();

	const char* session_begin_params = "sub = iat, domain = iat, language = zh_cn, accent = mandarin, sample_rate = 16000, result_type = plain, result_encoding = gb2312";
	
	//运行语音听写
	const char* session_id = NULL;
	char			rec_result[BUFFER_SIZE] = { NULL };
	char			hints[HINTS_SIZE] = { NULL }; //hints为结束本次会话的原因描述，由用户自定义
	unsigned int	total_len = 0;
	int				aud_stat = MSP_AUDIO_SAMPLE_CONTINUE;		//音频状态
	int				ep_stat = MSP_EP_LOOKING_FOR_SPEECH;		//端点检测
	int				rec_stat = MSP_REC_STATUS_SUCCESS;			//识别状态
	int				errcode = MSP_SUCCESS;

	FILE* f_pcm = NULL;
	char* p_pcm = NULL;
	errno_t err = NULL;
	long			pcm_count = 0;
	long			pcm_size = 0;
	long			read_size = 0;


	if (NULL == audio_file)
	{
		goto iat_exit;
	}

	//f_pcm = fopen(audio_file, "rb");
	err = fopen_s(&f_pcm, audio_file, "rb");//把音频文件里的内容打开到f_pcm中
	if (NULL == f_pcm)
	{
		printf("\nopen [%s] failed! \n", audio_file);
		goto iat_exit;
	}

	fseek(f_pcm, 0, SEEK_END);
	pcm_size = ftell(f_pcm); //获取音频文件大小
	fseek(f_pcm, 0, SEEK_SET);

	p_pcm = (char*)malloc(pcm_size);
	if (NULL == p_pcm)
	{
		printf("\nout of memory! \n");
		goto iat_exit;
	}

	read_size = fread((void*)p_pcm, 1, pcm_size, f_pcm); //读取音频文件内容
	if (read_size != pcm_size)
	{
		printf("\nread [%s] error!\n", audio_file);
		goto iat_exit;
	}

	printf("\n开始语音听写 ...\n");
	session_id = QISRSessionBegin(NULL, session_begin_params, &errcode); //听写不需要语法，第一个参数为nullptr，第二个参数是听写性质的各个参数
	if (MSP_SUCCESS != errcode)
	{
		printf("\nQISRSessionBegin failed! error code:%d\n", errcode);
		goto iat_exit;
	}

	while (1)
	{
		unsigned int len = 10 * FRAME_LEN; // 每次写入200ms音频(16k，16bit)：1帧音频20ms，10帧=200ms。16k采样率的16位音频，一帧的大小为640Byte
		int ret = 0;

		if (pcm_size < 2 * len)
			len = pcm_size;
		if (len <= 0)
			break;

		aud_stat = MSP_AUDIO_SAMPLE_CONTINUE;//音频状态
		if (0 == pcm_count)
			aud_stat = MSP_AUDIO_SAMPLE_FIRST;

		//printf(">");
		ret = QISRAudioWrite(session_id, (const void*)& p_pcm[pcm_count], len, aud_stat, &ep_stat, &rec_stat);//写入本次实别的音频
		if (MSP_SUCCESS != ret)
		{
			printf("\nQISRAudioWrite failed! error code:%d\n", ret);
			goto iat_exit;
		}

		pcm_count += (long)len;
		pcm_size -= (long)len;

		if (MSP_REC_STATUS_SUCCESS == rec_stat) //已经有部分听写结果
		{
			const char* rslt = QISRGetResult(session_id, &rec_stat, 0, &errcode);
			if (MSP_SUCCESS != errcode)
			{
				printf("\nQISRGetResult failed! error code: %d\n", errcode);
				goto iat_exit;
			}
			if (nullptr != rslt)
			{
				unsigned int rslt_len = strlen(rslt);
				total_len += rslt_len;
				if (total_len >= BUFFER_SIZE)
				{
					printf("\nno enough buffer for rec_result !\n");
					goto iat_exit;
				}
				strncat_s(rec_result, strlen(rec_result), rslt, rslt_len);
			}
		}

		if (MSP_EP_AFTER_SPEECH == ep_stat)
			break;
		Sleep(200); //模拟人说话时间间隙。200ms对应10帧的音频
	}
	errcode = QISRAudioWrite(session_id, nullptr, 0, MSP_AUDIO_SAMPLE_LAST, &ep_stat, &rec_stat);
	if (MSP_SUCCESS != errcode)
	{
		printf("\nQISRAudioWrite failed! error code:%d \n", errcode);
		goto iat_exit;
	}

	while (MSP_REC_STATUS_COMPLETE != rec_stat)
	{
		const char* rslt = QISRGetResult(session_id, &rec_stat, 0, &errcode);
		if (MSP_SUCCESS != errcode)
		{
			printf("\nQISRGetResult failed, error code: %d\n", errcode);
			goto iat_exit;
		}
		if (nullptr != rslt)
		{
			unsigned int rslt_len = strlen(rslt);
			total_len += rslt_len;
			if (total_len >= BUFFER_SIZE)
			{
				printf("\nno enough buffer for rec_result !\n");
				goto iat_exit;
			}
			strncat_s(rec_result, sizeof(rec_result), rslt, rslt_len);
		}
		Sleep(150); //防止频繁占用CPU
	}
	{
		printf("\n语音听写结束\n");

		//const QString q_result = QString(QLatin1String(rec_result));
		//QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
		ui->output->insertPlainText(QString::fromLocal8Bit(rec_result));
		//printf("%s\n", rec_result);
	}

iat_exit:
	if (nullptr != f_pcm)
	{
		fclose(f_pcm);
		f_pcm = nullptr;
	}
	if (nullptr != p_pcm)
	{
		free(p_pcm);
		p_pcm = nullptr;
	}

	QISRSessionEnd(session_id, hints);

	_getch();
	MSPLogout();
}

void service_3_F::back_func()
{
	Service_3* s = new Service_3;
	s->resize(700, 350);
	s->show();
	this->close();
}