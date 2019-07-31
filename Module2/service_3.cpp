#include "service_3.h"
#include "ui_service_3.h"
#include "service_3_f.h"
#include "service_3_m.h"
#include "mainwindow.h"

Service_3::Service_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service_3)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    ui->textBrowser->resize(400,40);
    ui->textBrowser->move(150,75);

    ui->fromFile->resize(200,50);
    ui->fromFile->move(250,150);

    ui->fromMIC->resize(200,50);
    ui->fromMIC->move(250,225);

	ui->Back->move(20, 15);
	ui->Back->resize(100, 30);

	connect(ui->Back, SIGNAL(clicked(bool)), this, SLOT(back_func()));
    connect(ui->fromFile,SIGNAL(clicked(bool)),this,SLOT(fromFile_func()));
    connect(ui->fromMIC,SIGNAL(clicked(bool)),this,SLOT(fromMIC_func()));
}

void Service_3::fromFile_func()
{
    service_3_F *s1=new service_3_F;
    s1->resize(700,350);
    s1->show();
    this->close();
}

void Service_3::fromMIC_func()
{
    service_3_M *s2=new service_3_M;
    s2->resize(700,315);
    s2->show();
    this->close();
}

Service_3::~Service_3()
{
    delete ui;
}

void Service_3::back_func()
{
	MainWindow* s = new MainWindow;
	s->resize(700, 550);
	s->show();
	this->close();
}