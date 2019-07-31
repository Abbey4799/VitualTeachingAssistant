/********************************************************************************
** Form generated from reading UI file 'service_4.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_4_H
#define UI_SERVICE_4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Service_4
{
public:
    QPushButton *PoetryCorrection;
    QPushButton *EnglishCorrection;
    QTextBrowser *textBrowser;
    QPushButton *Back;

    void setupUi(QWidget *Service_4)
    {
        if (Service_4->objectName().isEmpty())
            Service_4->setObjectName(QString::fromUtf8("Service_4"));
        Service_4->resize(400, 300);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(245, 255, 250, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Service_4->setPalette(palette);
        PoetryCorrection = new QPushButton(Service_4);
        PoetryCorrection->setObjectName(QString::fromUtf8("PoetryCorrection"));
        PoetryCorrection->setGeometry(QRect(140, 80, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font.setPointSize(13);
        PoetryCorrection->setFont(font);
        PoetryCorrection->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        EnglishCorrection = new QPushButton(Service_4);
        EnglishCorrection->setObjectName(QString::fromUtf8("EnglishCorrection"));
        EnglishCorrection->setGeometry(QRect(140, 120, 131, 31));
        EnglishCorrection->setFont(font);
        EnglishCorrection->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        textBrowser = new QTextBrowser(Service_4);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 30, 231, 31));
        QPalette palette1;
        QBrush brush2(QColor(107, 142, 35, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        QBrush brush3(QColor(240, 240, 240, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        textBrowser->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font1.setPointSize(14);
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(1);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Back = new QPushButton(Service_4);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(10, 10, 61, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));

        retranslateUi(Service_4);

        QMetaObject::connectSlotsByName(Service_4);
    } // setupUi

    void retranslateUi(QWidget *Service_4)
    {
        Service_4->setWindowTitle(QCoreApplication::translate("Service_4", "\350\267\237\350\257\273\346\240\241\345\207\206", nullptr));
        PoetryCorrection->setText(QCoreApplication::translate("Service_4", "\345\217\244\350\257\227\350\257\215\346\234\227\350\257\265\346\240\241\345\207\206", nullptr));
        EnglishCorrection->setText(QCoreApplication::translate("Service_4", "\350\213\261\350\257\255\350\267\237\350\257\273\346\240\241\345\207\206", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Service_4", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\271\346\255\243\345\247\232\344\275\223'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\350\257\267\351\200\211\346\213\251\350\256\255\347\273\203\346\250\241\345\274\217</span></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("Service_4", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Service_4: public Ui_Service_4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_4_H
