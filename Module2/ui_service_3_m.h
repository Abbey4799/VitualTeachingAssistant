/********************************************************************************
** Form generated from reading UI file 'service_3_m.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_3_M_H
#define UI_SERVICE_3_M_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service_3_M
{
public:
    QTextBrowser *output;
    QTextBrowser *textBrowser;
    QPushButton *Back;

    void setupUi(QWidget *service_3_M)
    {
        if (service_3_M->objectName().isEmpty())
            service_3_M->setObjectName(QString::fromUtf8("service_3_M"));
        service_3_M->resize(400, 300);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(143, 188, 139, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        service_3_M->setPalette(palette);
        output = new QTextBrowser(service_3_M);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(70, 90, 261, 31));
        QPalette palette1;
        QBrush brush2(QColor(245, 255, 250, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        QBrush brush3(QColor(189, 171, 165, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        output->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ink Free"));
        font.setPointSize(12);
        output->setFont(font);
        textBrowser = new QTextBrowser(service_3_M);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(70, 30, 256, 51));
        QPalette palette2;
        QBrush brush4(QColor(255, 255, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        textBrowser->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ink Free"));
        font1.setPointSize(13);
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Back = new QPushButton(service_3_M);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 10, 61, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));

        retranslateUi(service_3_M);

        QMetaObject::connectSlotsByName(service_3_M);
    } // setupUi

    void retranslateUi(QWidget *service_3_M)
    {
        service_3_M->setWindowTitle(QCoreApplication::translate("service_3_M", "\350\257\255\351\237\263\345\220\254\345\206\231_\344\273\216MIC", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("service_3_M", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ink Free'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Press</span><span style=\" font-size:12pt; font-weight:600;\"> r </span><span style=\" font-size:12pt;\">to</span><span style=\" font-size:12pt; font-weight:600;\"> start </span><span style=\" font-size:12pt;\">speaking.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Press</span><span style=\" font-size:12pt; font-weight:600;\"> s </span><span style=\" font-size:12pt;\">to</sp"
                        "an><span style=\" font-size:12pt; font-weight:600;\"> end </span><span style=\" font-size:12pt;\">speaking.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Press</span><span style=\" font-size:12pt; font-weight:600;\"> q </span><span style=\" font-size:12pt;\">to</span><span style=\" font-size:12pt; font-weight:600;\"> quit</span><span style=\" font-size:12pt;\">.</span></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("service_3_M", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class service_3_M: public Ui_service_3_M {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_3_M_H
