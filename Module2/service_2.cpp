/*本地WAV文件上传与播放*/
#include "service_2.h"
#include "ui_service_2.h"
#include "iat_record_sample.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "mainwindow.h"

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

Service_2::Service_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service_2)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    ui->textBrowser->resize(500,40);
    ui->textBrowser->move(125,75);

	ui->wavAddress->resize(250, 50);
	ui->wavAddress->move(150, 165);

	ui->input_OK->resize(100, 50);
	ui->input_OK->move(450, 165);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));
}

Service_2::~Service_2()
{
    delete ui;
}

void Service_2::on_input_OK_clicked()
{
	wchar_t wText[100] = { 0 };
	QString Text;
	std::string temp;

    Text = ui->wavAddress->text();
	temp = Text.toStdString();

    MByteToWChar(temp.c_str(), wText, sizeof(wText) / sizeof(wText[0]));
    PlaySound(wText, nullptr, SND_FILENAME | SND_SYNC);
}

void Service_2::back_func()
{
	MainWindow* s = new MainWindow;
	s->resize(700, 550);
	s->show();
	this->close();
}
