#-------------------------------------------------
#
# Project created by QtCreator 2012-01-19T22:49:33
#
#-------------------------------------------------

QT       += core gui network xml

TARGET = homemoney
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    account.cpp \
    currency.cpp \
    accountlistparser.cpp \
    group.cpp \
    parseditem.cpp \
    balancelistparser.cpp \
    xmlparser.cpp \
    configmanager.cpp \
    simplecrypt.cpp \
    connectionmanager.cpp \
    customaction.cpp \
    transactiondialog.cpp \
    category.cpp \
    categorylistparser.cpp

HEADERS  += mainwindow.h \
    account.h \
    currency.h \
    accountlistparser.h \
    group.h \
    parseditem.h \
    balancelistparser.h \
    xmlparser.h \
    configmanager.h \
    simplecrypt.h \
    connectionmanager.h \
    customaction.h \
    transactiondialog.h \
    category.h \
    categorylistparser.h

FORMS    += mainwindow.ui \
    transactiondialog.ui

RESOURCES += \
    res.qrc



























