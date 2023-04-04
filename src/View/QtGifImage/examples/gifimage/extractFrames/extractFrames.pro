QT       += gifimage

TARGET = extractFrames
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cc

DEFINES += SRCDIR=\\\"$$PWD/\\\"
