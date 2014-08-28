#include "cconfig.h"
#include <QStandardPaths>

CConfig::CConfig(QObject *parent) :
    QSettings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/QCodeEdit.ini", QSettings::IniFormat)
{

}
