/********************************************************************************
** Form generated from reading UI file 'service_1_c.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_1_C_H
#define UI_SERVICE_1_C_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service_1_C
{
public:
    QLineEdit *input_C;
    QPushButton *input_OK;
    QTextBrowser *textBrowser;
    QPushButton *Back;

    void setupUi(QWidget *service_1_C)
    {
        if (service_1_C->objectName().isEmpty())
            service_1_C->setObjectName(QString::fromUtf8("service_1_C"));
        service_1_C->resize(400, 145);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(254, 254, 239, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        service_1_C->setPalette(palette);
        input_C = new QLineEdit(service_1_C);
        input_C->setObjectName(QString::fromUtf8("input_C"));
        input_C->setGeometry(QRect(80, 70, 161, 21));
        input_OK = new QPushButton(service_1_C);
        input_OK->setObjectName(QString::fromUtf8("input_OK"));
        input_OK->setGeometry(QRect(260, 70, 80, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(13);
        input_OK->setFont(font);
        input_OK->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(143, 188, 139); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        textBrowser = new QTextBrowser(service_1_C);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(100, 30, 211, 31));
        QPalette palette1;
        QBrush brush2(QColor(107, 142, 35, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(160, 137, 128, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
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
        Back = new QPushButton(service_1_C);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 10, 61, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));

        retranslateUi(service_1_C);

        QMetaObject::connectSlotsByName(service_1_C);
    } // setupUi

    void retranslateUi(QWidget *service_1_C)
    {
        service_1_C->setWindowTitle(QCoreApplication::translate("service_1_C", "\350\257\255\351\237\263\345\220\210\346\210\220_\346\261\211\350\257\255", nullptr));
        input_OK->setText(QCoreApplication::translate("service_1_C", "\347\241\256\350\256\244", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("service_1_C", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\271\346\255\243\345\247\232\344\275\223'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\350\257\267\350\276\223\345\205\245\351\234\200\350\246\201\345\220\210\346\210\220\347\232\204\345\206\205\345\256\271</span></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("service_1_C", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class service_1_C: public Ui_service_1_C {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_1_C_H
