/*古诗词朗读校准*/
#include "service_4_c.h"
#include "ui_service_4_c.h"
#include "service_4.h"

#include <QtGUI/QKeyEvent>
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
#include "winrec.h"

#include <QDebug>
#define printf qDebug

#define FRAME_LEN	640
#define	BUFFER_SIZE	4096
#define MAX_LEN 102
#define HINTS_SIZE  100

static char* g_result = NULL;
static unsigned int g_buffersize = BUFFER_SIZE;

service_4_C* service_4_C::static_Self;
char* get_result_c = NULL;
char* Material_c = NULL;
double accuracy_rate_c = 0.0;
int times_c = 0;

service_4_C::service_4_C(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::service_4_C)
{
	ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

	static_Self = this;

	ui->label->resize(180, 80);
	ui->label->move(265, 25);

	ui->label_2->resize(110, 55);
	ui->label_2->move(470, 225);

	ui->material->resize(400, 125);
	ui->material->move(150, 95);

	ui->textBrowser->resize(270, 80);
	ui->textBrowser->move(150, 240);

	ui->score->resize(90, 40);
	ui->score->move(460, 280);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));

	int	ret = MSP_SUCCESS;
	const char* login_params = "appid = 5afaf149, work_dir = ."; // 登录参数，appid与msc库绑定,请勿随意改动

	int aud_src = 0;
	int flag = 0;

	/* 用户登录 */
	ret = MSPLogin(nullptr, nullptr, login_params); 
	if (MSP_SUCCESS != ret) {
		printf("MSPLogin failed , Error code %d.\n", ret);
		//登录失败，退出登录
		flag = 1;
		MSPLogout();
		quitS4_C();
	}
	const char* session_begin_params = "sub = iat, domain = iat, language = zh_cn, accent = mandarin, sample_rate = 16000, result_type = plain, result_encoding = gb2312";

	struct speech_rec_notifier recnotifier = {
		on_result,
		on_speech_begin,
		on_speech_end
	};

	_iErrcode = sr_init(&_iat, session_begin_params, SR_MIC, DEFAULT_INPUT_DEVID, &recnotifier);
	if (_iErrcode) {
		printf("speech recognizer init failed\n");
		return;
	}

	Material_c = print_material();
}

service_4_C::~service_4_C()
{
	sr_uninit(&_iat);
	delete ui;
}

void service_4_C::quitS4_C()
{
	this->close();
}

int service_4_C::Tmin(int a, int b, int c) {
	a = min(a, b);
	return min(a, c);
}

void StringReplace(std::string& strBase, std::string strSrc, std::string strDes)
{
	std::string::size_type pos = 0;
	std::string::size_type srcLen = strSrc.size();
	std::string::size_type desLen = strDes.size();
	pos = strBase.find(strSrc, pos);
	while ((pos != std::string::npos))
	{
		strBase.replace(pos, srcLen, strDes);
		pos = strBase.find(strSrc, (pos + desLen));
	}
}

// 动态规划计算字符串距离
double service_4_C::compare_result(char* string1, char* material) {
	std::string talk(string1);
	std::string standard(material);
	std::string delete1 = "。";
	std::string delete2 = "，";
	std::string replace = "";
	int strLen = talk.length();
	int matLen = standard.length();
	double matLen_d = matLen;
	StringReplace(talk, delete1, replace);
	StringReplace(standard, delete1, replace);
	StringReplace(talk, delete2, replace);
	StringReplace(standard, delete2, replace);
	standard.erase(remove(standard.begin(), standard.end(), '\r'), standard.end());
	standard.erase(remove(standard.begin(), standard.end(), '\n'), standard.end());

	if (!(matLen < MAX_LEN && strLen < MAX_LEN)) {
		printf("out of length!\n");
		return -1;
	}

	int dp[MAX_LEN][MAX_LEN];//d[i][j]表示字符串s的前i字符和t的前j个字符的莱文斯坦距离
	for (int i = 0; i <= strLen; i++) dp[i][0] = i;//源字符串s到空字符串t只要删除每个字符
	for (int j = 1; j <= matLen; j++) dp[0][j] = j;//从空字符s到目标字符t只要添加每个字符
	for (int j = 0; j < matLen; j++) {
		for (int i = 0; i < strLen; i++) {
			if (string1[i] == material[j])dp[i + 1][j + 1] = dp[i][j];//无任何操作
			else dp[i + 1][j + 1] = Tmin(dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 1);
			//分别为删除、添加、替换操作
		}
	}
	double mark = 0;
	mark = (matLen_d - dp[strLen][matLen]) / matLen_d;
	return mark;
}

char* service_4_C::print_material() {
	char* material = NULL;
	size_t len = 0;
	size_t read_len = 0;
	FILE* fp = NULL;
	int ret = -1;
	errno_t err = fopen_s(&fp, "material_c.txt", "rb");
	if (NULL == fp) {
		printf("\nopen [material_c.txt] failed! \n");
		goto print_exit;
	}

	fseek(fp, 0, SEEK_END);		// 移动文件流的读写位置
	len = ftell(fp); //获取文件大小
	fseek(fp, 0, SEEK_SET);

	material = (char*)malloc(len + 1);
	if (NULL == material)
	{
		printf("\nout of memory! \n");
		goto print_exit;
	}

	read_len = fread(material, 1, len, fp); //读取阅读材料内容
	if (read_len != len)
	{
		printf("\nread [userwords.txt] failed!\n");
		goto print_exit;
	}
	material[len] = '\0';

	ui->material->insertPlainText(QString::fromUtf8(material));

	return material;

print_exit:
	if (NULL != fp)
	{
		fclose(fp);
		fp = NULL;
	}
	if (NULL != material)
	{
		free(material);
		material = NULL;
	}

	return (char*)ret;
}

//以点击键盘相应按钮为信号，开始与中断录音操作
void service_4_C::keyPressEvent(QKeyEvent* e)
{
	int is_quit = 0;
	char cKey = e->key();
	if (times_c != 0)
		quitS4_C();
	switch (cKey)
	{
	case 'R':
	case 'r':
		if (_iErrcode = sr_start_listening(&_iat)) {
			printf("start listen failed %d\n", _iErrcode);
		}
		break;
	case 'S':
	case 's':
		if (_iErrcode = sr_stop_listening(&_iat)) {
			printf("stop listening failed %d\n", _iErrcode);
		}
		is_quit = 1;
		break;
	case 'Q':
	case 'q':
		quitS4_C();
	default:
		break;
	}
	if (is_quit == 1)
	{
		QString q_result = QString::fromLocal8Bit(get_result_c);
		accuracy_rate_c = compare_result(q_result.toUtf8().data(), Material_c);
		ui->score->setText(QString::number(100 * accuracy_rate_c, 10, 3));
		times_c++;
	}
}

void service_4_C::on_result(const char* result, char is_last)
{
	if (result) {
		size_t left = g_buffersize - 1 - strlen(g_result);
		size_t size = strlen(result);
		if (left < size) {
			g_result = (char*)realloc(g_result, g_buffersize + BUFFER_SIZE);
			if (g_result)
				g_buffersize += BUFFER_SIZE;
			else {
				printf("mem alloc failed\n");
				return;
			}
		}
		strncat(g_result, result, size);
		get_result_c = const_cast<char*>(g_result);
	}
}

void service_4_C::on_speech_begin()
{
	if (g_result)
	{
		free(g_result);
	}
	g_result = (char*)malloc(BUFFER_SIZE);
	g_buffersize = BUFFER_SIZE;
	memset(g_result, 0, g_buffersize);

	printf("Start Listening...\n");
}

void service_4_C::on_speech_end(int reason)
{
	if (reason == END_REASON_VAD_DETECT)
		printf("\nSpeaking done \n");
	else
		printf("\nRecognizer error %d\n", reason);
}

void service_4_C::back_func()
{
	Service_4* s = new Service_4;
	s->resize(700, 350);
	s->show();
	this->close();
}