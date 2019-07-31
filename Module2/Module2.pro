#-------------------------------------------------
#
# Project created by QtCreator 2019-06-06T07:34:00
#
#-------------------------------------------------

QT       += widgets
QT       += core gui

QT       += multimedia

msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8
msvc:QMAKE_CXXFLAGS += -source-charset:utf-8

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Module2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        iat_record_sample.cpp \
        main.cpp \
        mainwindow.cpp \
        service_1.cpp \
        service_1_c.cpp \
        service_1_e.cpp \
        service_2.cpp \
        service_3.cpp \
        service_3_f.cpp \
        service_3_m.cpp \
        service_4.cpp \
        speech_recognizer.cpp \
        winrec.cpp

HEADERS += \
        iat_record_sample.h \
        mainwindow.h \
        msp_cmn.h \
        msp_errors.h \
        msp_types.h \
        qisr.h \
        qtts.h \
        service_1.h \
        service_1_c.h \
        service_1_e.h \
        service_2.h \
        service_3.h \
        service_3_f.h \
        service_3_m.h \
        service_4.h \
        speech_recognizer.h \
        winrec.h

FORMS += \
        mainwindow.ui \
        service_1.ui \
        service_1_c.ui \
        service_1_e.ui \
        service_2.ui \
        service_3.ui \
        service_3_f.ui \
        service_3_m.ui \
        service_4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
