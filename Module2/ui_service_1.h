/********************************************************************************
** Form generated from reading UI file 'service_1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_1_H
#define UI_SERVICE_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Service_1
{
public:
    QPushButton *chooseChinese;
    QPushButton *chooseEnglish;
    QTextBrowser *textBrowser;
    QPushButton *Back;

    void setupUi(QWidget *Service_1)
    {
        if (Service_1->objectName().isEmpty())
            Service_1->setObjectName(QString::fromUtf8("Service_1"));
        Service_1->resize(370, 210);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 230, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 205, 66, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        Service_1->setPalette(palette);
        chooseChinese = new QPushButton(Service_1);
        chooseChinese->setObjectName(QString::fromUtf8("chooseChinese"));
        chooseChinese->setGeometry(QRect(140, 90, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font.setPointSize(13);
        chooseChinese->setFont(font);
        chooseChinese->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        chooseEnglish = new QPushButton(Service_1);
        chooseEnglish->setObjectName(QString::fromUtf8("chooseEnglish"));
        chooseEnglish->setGeometry(QRect(140, 140, 101, 31));
        chooseEnglish->setFont(font);
        chooseEnglish->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        textBrowser = new QTextBrowser(Service_1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 40, 191, 31));
        QPalette palette1;
        QBrush brush3(QColor(107, 142, 35, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(177, 212, 225, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        textBrowser->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font1.setPointSize(14);
        textBrowser->setFont(font1);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(1);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Back = new QPushButton(Service_1);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(300, 10, 61, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));

        retranslateUi(Service_1);

        QMetaObject::connectSlotsByName(Service_1);
    } // setupUi

    void retranslateUi(QWidget *Service_1)
    {
        Service_1->setWindowTitle(QCoreApplication::translate("Service_1", "\350\257\255\351\237\263\345\220\210\346\210\220", nullptr));
        chooseChinese->setText(QCoreApplication::translate("Service_1", "\346\261\211\350\257\255", nullptr));
        chooseEnglish->setText(QCoreApplication::translate("Service_1", "\350\213\261\350\257\255", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Service_1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\271\346\255\243\345\247\232\344\275\223'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\350\257\267\351\200\211\346\213\251\350\257\255\350\250\200</span></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("Service_1", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Service_1: public Ui_Service_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_1_H
