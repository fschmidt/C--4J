#-------------------------------------------------
#
# Project created by QtCreator 2012-07-03T17:38:53
#
#-------------------------------------------------

QT       += core gui sql

TARGET = Haushaltsbuch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    posting.cpp \
    category.cpp \
    config_reader.cpp \
    addcategorydialog.cpp \
    deletecategorydialog.cpp

HEADERS  += mainwindow.h \
    databaseconection.h \
    posting.h \
    category.h \
    config_reader.h \
    addcategorydialog.h \
    deletecategorydialog.h

FORMS    += mainwindow.ui \
    addcategorydialog.ui \
    deletecategorydialog.ui

OTHER_FILES += \
    config.ini
