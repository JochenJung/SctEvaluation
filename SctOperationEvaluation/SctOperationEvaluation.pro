CONFIG   += c++17
QT       -= core gui
TARGET    = SctEvaluationApp
TEMPLATE  = app
VERSION   = 0.1


CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src-test/SctOperationEvaluationUnit.cpp \
	src-test/StatechartTest.cc \
	src-test/sc_runner.cpp

HEADERS += \
    src-test/SctOperationEvaluationUnit.h \
	src-test/sc_runner.h

INCLUDEPATH += src-gen/ src-lib/

LIBS += -lgtest -lgtest_main
