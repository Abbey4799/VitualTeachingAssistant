#include "service_4.h"
#include "ui_service_4.h"
#include "service_4_c.h"
#include "service_4_e.h"
#include "mainwindow.h"
#include <QDebug>

Service_4::Service_4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service_4)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

	ui->textBrowser->resize(400, 40);
	ui->textBrowser->move(150, 75);

    ui->PoetryCorrection->resize(260, 50);
    ui->PoetryCorrection->move(220, 150);

    ui->EnglishCorrection->resize(260, 50);
    ui->EnglishCorrection->move(220, 225);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));
    connect(ui->PoetryCorrection, SIGNAL(clicked(bool)),this,SLOT(poetry_func()));
    connect(ui->EnglishCorrection,SIGNAL(clicked(bool)),this,SLOT(english_func()));
}

void Service_4::poetry_func()
{
    service_4_C* s1 = new service_4_C;
    s1->resize(700, 350);
    s1->show();
    this->close();
}

void Service_4::english_func()
{
    service_4_E* s2 = new service_4_E;
    s2->resize(700, 350);
    s2->show();
    this->close();
}

Service_4::~Service_4()
{
    delete ui;
}

void Service_4::back_func()
{
	MainWindow* s = new MainWindow;
	s->resize(700, 550);
	s->show();
	this->close();
}
