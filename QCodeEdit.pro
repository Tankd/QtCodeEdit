#-------------------------------------------------
#
# Project created by QtCreator 2014-07-10T10:12:20
#
#-------------------------------------------------

QT       += core gui widgets


DESTDIR = $$PWD/dist
TARGET = QCodeEdit
TEMPLATE = app


RC_FILE += $$PWD/img/ico.rc

QT_QPA_PLATFORMTHEME=appmenu-qt5


SOURCES += src/main.cpp\
        src/cmainwindow.cpp \
    src/cdocument.cpp \
    src/cdocumenttab.cpp \
    src/cfolderdock.cpp \
    src/cconfig.cpp \
    src/cmenubar.cpp \
    src/cwindowbutton.cpp \
    src/ccodeedit.cpp

HEADERS  += src/cmainwindow.h \
    src/cdocument.h \
    src/cdocumenttab.h \
    src/cfolderdock.h \
    src/cconfig.h \
    src/cmenubar.h \
    src/cwindowbutton.h \
    src/ccodeedit.h

FORMS    += \
    src/cfolderdock.ui

RESOURCES += \    
    img/img.qrc
