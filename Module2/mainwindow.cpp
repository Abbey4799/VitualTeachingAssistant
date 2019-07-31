#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service_1.h"
#include "service_2.h"
#include "service_3.h"
#include "service_4.h"
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    //设置控件位置与大小
    ui->textBrowser->resize(400,40);
    ui->textBrowser->move(150,50);

    ui->pushButton_1->resize(200,60);
    ui->pushButton_1->move(250,130);

    ui->pushButton_2->resize(200,60);
    ui->pushButton_2->move(250,220);

    ui->pushButton_3->resize(200,60);
    ui->pushButton_3->move(250,310);

    ui->pushButton_4->resize(200,60);
    ui->pushButton_4->move(250,400);

    //建立信号槽
    connect(ui->pushButton_1,SIGNAL(clicked(bool)),this,SLOT(service1_func()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(service2_func()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(service3_func()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(service4_func()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::service1_func()
{
    Service_1 *s1=new Service_1;
    s1->resize(700,350);
    s1->show();
    this->close();
}

void MainWindow::service2_func()
{
    Service_2 *s2=new Service_2;
    s2->resize(700,300);
    s2->show();
    this->close();
}

void MainWindow::service3_func()
{
    Service_3 *s3=new Service_3;
    s3->resize(700,350);
    s3->show();
    this->close();
}

void MainWindow::service4_func()
{
    Service_4 *s4=new Service_4;
    s4->resize(700,350);
    s4->show();
    this->close();
}
