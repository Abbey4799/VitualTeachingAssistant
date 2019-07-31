#include "service_1.h"
#include "ui_service_1.h"
#include "iat_record_sample.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "service_1_c.h"
#include "service_1_e.h"
#include "mainwindow.h"

#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <errno.h>
#include <process.h>
#include <time.h>
#include <assert.h>
#include <iostream>


Service_1::Service_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service_1)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    ui->textBrowser->resize(400,40);
    ui->textBrowser->move(150,65);

    ui->chooseChinese->resize(200,50);
    ui->chooseChinese->move(250,150);

    ui->chooseEnglish->resize(200,50);
    ui->chooseEnglish->move(250,225);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

    connect(ui->chooseChinese,SIGNAL(clicked(bool)),this,SLOT(chooseChinese_func()));
    connect(ui->chooseEnglish,SIGNAL(clicked(bool)),this,SLOT(chooseEnglish_func()));
	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));
}

void Service_1::chooseChinese_func()
{
    service_1_C *s1=new service_1_C;
    s1->resize(700,300);
    s1->show();
    this->close();
}

void Service_1::chooseEnglish_func()
{
    service_1_E *s2=new service_1_E;
    s2->resize(700,300);
    s2->show();
    this->close();
}

Service_1::~Service_1()
{
    delete ui;
}

void Service_1::back_func()
{
	MainWindow* s = new MainWindow;
	s->resize(700, 550);
	s->show();
	this->close();
}