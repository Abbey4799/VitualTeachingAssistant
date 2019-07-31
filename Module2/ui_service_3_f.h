/********************************************************************************
** Form generated from reading UI file 'service_3_f.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_3_F_H
#define UI_SERVICE_3_F_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service_3_F
{
public:
    QLineEdit *wavAddress;
    QTextBrowser *output;
    QTextBrowser *textBrowser;
    QPushButton *input_OK;
    QPushButton *Back;

    void setupUi(QWidget *service_3_F)
    {
        if (service_3_F->objectName().isEmpty())
            service_3_F->setObjectName(QString::fromUtf8("service_3_F"));
        service_3_F->resize(400, 210);
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
        service_3_F->setPalette(palette);
        wavAddress = new QLineEdit(service_3_F);
        wavAddress->setObjectName(QString::fromUtf8("wavAddress"));
        wavAddress->setGeometry(QRect(60, 90, 141, 20));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        wavAddress->setPalette(palette1);
        output = new QTextBrowser(service_3_F);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(60, 120, 256, 31));
        QPalette palette2;
        QBrush brush3(QColor(255, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        QBrush brush4(QColor(189, 171, 165, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        output->setPalette(palette2);
        output->setStyleSheet(QString::fromUtf8(""));
        textBrowser = new QTextBrowser(service_3_F);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(70, 40, 231, 31));
        QPalette palette3;
        QBrush brush5(QColor(107, 142, 35, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QBrush brush6(QColor(240, 240, 240, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        textBrowser->setPalette(palette3);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font.setPointSize(14);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(1);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        input_OK = new QPushButton(service_3_F);
        input_OK->setObjectName(QString::fromUtf8("input_OK"));
        input_OK->setGeometry(QRect(240, 90, 80, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(13);
        input_OK->setFont(font1);
        input_OK->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        Back = new QPushButton(service_3_F);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(10, 10, 61, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));

        retranslateUi(service_3_F);

        QMetaObject::connectSlotsByName(service_3_F);
    } // setupUi

    void retranslateUi(QWidget *service_3_F)
    {
        service_3_F->setWindowTitle(QCoreApplication::translate("service_3_F", "\350\257\255\351\237\263\345\220\254\345\206\231_\344\273\216\346\226\207\344\273\266", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("service_3_F", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\271\346\255\243\345\247\232\344\275\223'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\350\257\267\350\276\223\345\205\245\346\234\254\345\234\260WAV\346\226\207\344\273\266\345\234\260\345\235\200</span></p></body></html>", nullptr));
        input_OK->setText(QCoreApplication::translate("service_3_F", "\347\241\256\350\256\244", nullptr));
        Back->setText(QCoreApplication::translate("service_3_F", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class service_3_F: public Ui_service_3_F {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_3_F_H
