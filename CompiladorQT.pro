#-------------------------------------------------
#
# Project created by QtCreator 2015-09-03T20:28:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = CompiladorQT
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    AnalizadorLexico.cpp \
    EntradaTS.cpp \
    TabladeSimbolos.cpp \
    y.tab.c \
    Parser.cpp \
    GeneradorDeCodigo.cpp

HEADERS += \
    AnalizadorLexico.h \
    EntradaTS.h \
    TabladeSimbolos.h \
    y.tab.h \
    Parser.h \
    GeneradorDeCodigo.h

OTHER_FILES += \
    y.output
