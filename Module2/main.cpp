#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iat_record_sample.h"
#include <QApplication>
#include <QPushButton>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));//设置中文为gbk格式
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(700,550);
    w.show();

    return a.exec();
}
