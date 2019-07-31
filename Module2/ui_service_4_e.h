/********************************************************************************
** Form generated from reading UI file 'service_4_e.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_4_E_H
#define UI_SERVICE_4_E_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service_4_E
{
public:
    QTextBrowser *material;
    QLabel *label;
    QTextBrowser *score;
    QPushButton *Back;
    QLabel *label_2;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *service_4_E)
    {
        if (service_4_E->objectName().isEmpty())
            service_4_E->setObjectName(QString::fromUtf8("service_4_E"));
        service_4_E->resize(400, 300);
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
        service_4_E->setPalette(palette);
        material = new QTextBrowser(service_4_E);
        material->setObjectName(QString::fromUtf8("material"));
        material->setGeometry(QRect(70, 70, 251, 81));
        QPalette palette1;
        QBrush brush2(QColor(143, 188, 139, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        QBrush brush3(QColor(189, 171, 165, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        material->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ink Free"));
        font.setPointSize(14);
        material->setFont(font);
        material->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        label = new QLabel(service_4_E);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 40, 141, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font1.setPointSize(12);
        label->setFont(font1);
        score = new QTextBrowser(service_4_E);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(260, 190, 81, 31));
        QPalette palette2;
        QBrush brush4(QColor(255, 255, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        score->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ink Free"));
        font2.setPointSize(11);
        score->setFont(font2);
        score->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        Back = new QPushButton(service_4_E);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(20, 20, 61, 28));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Impact"));
        Back->setFont(font3);
        Back->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(85, 107, 47); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(42, 53, 23); }"));
        label_2 = new QLabel(service_4_E);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 160, 141, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font4.setPointSize(10);
        label_2->setFont(font4);
        textBrowser = new QTextBrowser(service_4_E);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(70, 160, 171, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        textBrowser->setPalette(palette3);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ink Free"));
        font5.setPointSize(13);
        textBrowser->setFont(font5);
        textBrowser->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        retranslateUi(service_4_E);

        QMetaObject::connectSlotsByName(service_4_E);
    } // setupUi

    void retranslateUi(QWidget *service_4_E)
    {
        service_4_E->setWindowTitle(QCoreApplication::translate("service_4_E", "\350\267\237\350\257\273\346\240\241\345\207\206_\350\213\261\346\226\207\346\235\220\346\226\231", nullptr));
        material->setHtml(QCoreApplication::translate("service_4_E", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ink Free'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("service_4_E", "\346\202\250\346\234\254\346\254\241\347\232\204\346\265\213\350\257\225\346\235\220\346\226\231", nullptr));
        score->setHtml(QCoreApplication::translate("service_4_E", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ink Free'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\344\273\277\345\256\213';\"><br /></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("service_4_E", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("service_4_E", "\346\265\213\350\257\225\345\276\227\345\210\206", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("service_4_E", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ink Free'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Press </span><span style=\" font-size:11pt; font-weight:600;\">r </span><span style=\" font-size:11pt;\">to </span><span style=\" font-size:11pt; font-weight:600;\">start</span><span style=\" font-size:11pt;\"> speaking.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Press </span><span style=\" font-size:11pt; font-weight:600;\">s</span><span style=\" font-size:11pt;\"> to </s"
                        "pan><span style=\" font-size:11pt; font-weight:600;\">end</span><span style=\" font-size:11pt;\"> speaking.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Press</span><span style=\" font-size:11pt; font-weight:600;\"> q </span><span style=\" font-size:11pt;\">to </span><span style=\" font-size:11pt; font-weight:600;\">quit</span><span style=\" font-size:11pt;\">.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class service_4_E: public Ui_service_4_E {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_4_E_H
