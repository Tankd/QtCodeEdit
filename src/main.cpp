#include "cmainwindow.h"
#include <QApplication>

#include <QTextStream>
#include <QSettings>
#include <QDebug>

void createShellEntry()
{
    QSettings *settings = new QSettings("HKEY_CLASSES_ROOT\\*\\shell", QSettings::NativeFormat);
    settings->beginGroup("Open with QCodeEdit");
    settings->beginGroup("command");
    settings->setValue("Open with QCodeEdit/command/gg", qApp->applicationFilePath() + " %1");
    delete settings;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    createShellEntry();

    CMainWindow w;
    w.show();

    return a.exec();
}
