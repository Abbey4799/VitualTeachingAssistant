/*英语文本合成*/
#include "service_1_e.h"
#include "ui_service_1_e.h"
#include "iat_record_sample.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "service_1_e.h"
#include "service_1.h"

#include <QString>
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
#include <QSound>

#include <QDebug>
#define printf qDebug

service_1_E::service_1_E(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::service_1_E)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

	ui->textBrowser->resize(400, 40);
	ui->textBrowser->move(150, 75);

	ui->input_E->resize(250, 50);
	ui->input_E->move(150, 165);

	ui->input_OK->resize(100, 50);
	ui->input_OK->move(450, 165);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));
}

service_1_E::~service_1_E()
{
    delete ui;
}

void service_1_E::quitS1_E()
{
    this->close();
}

void service_1_E::on_input_OK_clicked()
{
    int	ret = MSP_SUCCESS;
    const char* login_params = "appid = 5afaf149, work_dir = ."; // 登录参数，appid与msc库绑定,请勿随意改动

	int aud_src = 0;
    double accuracy_rate = 0.0;
    int flag=0;

    /* 用户登录 */
    ret = MSPLogin(nullptr, nullptr, login_params); //第一个参数是用户名，第二个参数是密码，均传nullptr即可，第三个参数是登录参数
    if (MSP_SUCCESS != ret) {
        printf("MSPLogin failed , Error code %d.\n", ret);
        //登录失败，退出登录
        flag=1;
        MSPLogout();
        quitS1_E();
    }
    //英语TTS
    if(flag!=1)
    {
        const char* session_begin_params = "voice_name = xiaoyan, text_encoding = GB2312, tts_res_path = fo|res\\tts\\xiaoyan.jet;fo|res\\tts\\common.jet, sample_rate = 16000, speed = 50, volume = 50, pitch = 50, rdn = 2";
        const char* filename = "sample.wav"; //合成的语音文件名称
        std::string s = "sample.wav";
        wchar_t wText[30] = { 0 };
		const char* ttep;
		char text[5000] = { 0 };
        QString Text;
		std::string temp;

		Text = ui->input_E->text();
		temp = Text.toStdString();
		ttep = temp.c_str();
		strcpy(text, ttep);

		ret = text_to_speech(text, filename, session_begin_params);
		if (MSP_SUCCESS != ret)
		{
			printf("text_to_speech failed, error code: %d.\n", ret);
		}

		MByteToWChar(s.c_str(), wText, sizeof(wText) / sizeof(wText[0]));
		PlaySound(wText, nullptr, SND_FILENAME | SND_SYNC);
		
		_getch();
		MSPLogout();
    }
}

void service_1_E::back_func()
{
	Service_1* s = new Service_1;
	s->resize(700, 350);
	s->show();
	this->close();
}