QT       += core gui openglwidgets concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(QtGifImage/src/gifimage/qtgifimage.pri) # подключение бибы для работы с gif

SOURCES += \
    ../main.cc \
    ../Model/Parser/parser.cc \
    ../Model/Affine/affine.cc \
    ../Controller/controller.cc \
    StrategyActions/strategyActions.cc \
    Command/command.cc \
    mainwindow.cc

HEADERS += \
    ../Model/model.h \
    ../Model/Parser/parser.h \
    ../Model/Affine/affine.h \
    ../Controller/controller.h \
    StrategyActions/strategyActions.h \
    Command/command.h \
    mainwindow.h
FORMS += \
    mainwindow.ui

ICON = icon.icns
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
