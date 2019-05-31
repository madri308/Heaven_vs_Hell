#-------------------------------------------------
#
# Project created by QtCreator 2019-05-12T16:50:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = progra2
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
-DJSON_MultipleHeaders=ON

SOURCES += \
    avltree.cpp \
    hash.cpp \
    heaventree.cpp \
        main.cpp \
    jsonparser.cpp \
    human.cpp \
    doublelist.cpp \
    nodocielo.cpp \
    world.cpp \
    node.cpp \
    worldwindow.cpp \
    demon.cpp \
    hell.cpp \
    heaven.cpp \
    binarysearchtree.cpp \
    demonwindow.cpp \
    famsinswindow.cpp \
    minheap.cpp

HEADERS += \
    avltree.h \
    hash.h \
    heaventree.h \
    jsonparser.h \
    json.hpp \
    human.h \
    doublelist.h \
    nodocielo.h \
    world.h \
    node.h \
    worldwindow.h \
    demon.h \
    hell.h \
    heaven.h \
    binarysearchtree.h \
    demonwindow.h \
    famsinswindow.h \
    minheap.h

FORMS += \
    worldwindow.ui \
    demonwindow.ui \
    famsinswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
# Sets the default installation prefix to the build directory.
# This is the same default that Qt's configuration process uses.
!defined(PREFIX,var): PREFIX = $$OUT_PWD

MY_RESOURCES = \
  data.json \

OTHER_SOURCES += $$MY_RESOURCES

# Object describing the resources to install
my_resources.path = $$PREFIX/share/myproject
my_resources.files = $$MY_RESOURCES

# The automatically generated object describing the target.
target.path = $$PREFIX/bin/myproject

# Declare my_resources and target objects to be installed.
INSTALLS += my_resources target

DISTFILES +=

RESOURCES += \
    resources.qrc

