/********************************************************************************
** Form generated from reading UI file 'service_3.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_3_H
#define UI_SERVICE_3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Service_3
{
public:
    QPushButton *fromFile;
    QPushButton *fromMIC;
    QTextBrowser *textBrowser;
    QPushButton *Back;

    void setupUi(QWidget *Service_3)
    {
        if (Service_3->objectName().isEmpty())
            Service_3->setObjectName(QString::fromUtf8("Service_3"));
        Service_3->resize(400, 300);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 230, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Service_3->setPalette(palette);
        fromFile = new QPushButton(Service_3);
        fromFile->setObjectName(QString::fromUtf8("fromFile"));
        fromFile->setGeometry(QRect(150, 79, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font.setPointSize(12);
        fromFile->setFont(font);
        fromFile->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        fromMIC = new QPushButton(Service_3);
        fromMIC->setObjectName(QString::fromUtf8("fromMIC"));
        fromMIC->setGeometry(QRect(150, 120, 101, 31));
        fromMIC->setFont(font);
        fromMIC->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        textBrowser = new QTextBrowser(Service_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 40, 231, 31));
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
        Back = new QPushButton(Service_3);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 0, 61, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));

        retranslateUi(Service_3);

        QMetaObject::connectSlotsByName(Service_3);
    } // setupUi

    void retranslateUi(QWidget *Service_3)
    {
        Service_3->setWindowTitle(QCoreApplication::translate("Service_3", "\350\257\255\351\237\263\345\220\254\345\206\231", nullptr));
        fromFile->setText(QCoreApplication::translate("Service_3", "\344\273\216\346\226\207\344\273\266\350\276\223\345\205\245", nullptr));
        fromMIC->setText(QCoreApplication::translate("Service_3", "\344\273\216MIC\350\276\223\345\205\245", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Service_3", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\271\346\255\243\345\247\232\344\275\223'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\350\257\267\351\200\211\346\213\251\351\237\263\351\242\221\350\276\223\345\205\245\346\226\271\345\274\217</span></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("Service_3", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Service_3: public Ui_Service_3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_3_H
