/*语音识别（从MIC）*/
#include "service_3_m.h"
#include "ui_service_3_m.h"
#include "service_3.h"

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

static char* g_result = NULL;
static unsigned int g_buffersize = BUFFER_SIZE;

service_3_M* service_3_M::static_Self;

service_3_M::service_3_M(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::service_3_M)
{
	ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
	
	static_Self = this;

	ui->textBrowser->resize(400, 90);
	ui->textBrowser->move(150, 60);

	ui->output->resize(300, 40);
	ui->output->move(200,200);

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
		quitS3_M();
	}
	const char* session_begin_params = "sub = iat, domain = iat, language = zh_cn, accent = mandarin, sample_rate = 16000, result_type = plain, result_encoding = gb2312";

	//demo_MIC. updated by 李雅琪
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
}

service_3_M::~service_3_M()
{
	sr_uninit(&_iat);
	delete ui;
}

void service_3_M::quitS3_M()
{
	this->close();
}

void service_3_M::keyPressEvent(QKeyEvent* e)
{
	char cKey = e->key();
	switch (cKey)
	{
	case 'R':
	case 'r':
		static_Self->clear();
		if (_iErrcode = sr_start_listening(&_iat)) {
			printf("start listen failed %d\n", _iErrcode);
		}
		break;
	case 'S':
	case 's':
		if (_iErrcode = sr_stop_listening(&_iat)) {
			printf("stop listening failed %d\n", _iErrcode);
		}
		break;
	case 'Q':
	case 'q':
		//sr_stop_listening(&_iat);
		quitS3_M();
	default:
		break;
	}
}

void service_3_M::on_result(const char* result, char is_last)
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

		//show_result(g_result, is_last); 
		//get_result = const_cast<char*>(result);
		static_Self->output();
		//result = nullptr;
	}
}

void service_3_M::output()
{
	ui->output->setText(QString::fromLocal8Bit(g_result));
}

void service_3_M::clear()
{
	ui->output->setText("");
}

void service_3_M::on_speech_begin()
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

void service_3_M::on_speech_end(int reason)
{
	if (reason == END_REASON_VAD_DETECT)
		printf("\nSpeaking done \n");
	else
		printf("\nRecognizer error %d\n", reason);
}

void service_3_M::back_func()
{
	Service_3* s = new Service_3;
	s->resize(700, 350);
	s->show();
	this->close();
}