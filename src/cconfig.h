#ifndef CCONFIG_H
#define CCONFIG_H

#include <QSettings>
#include "csingleton.h"

class CConfig : public QSettings, public CSingleton<CConfig>
{
    Q_OBJECT
    friend class CSingleton<CConfig>;
protected:
    explicit CConfig(QObject *parent = 0);

signals:

public slots:

};

#endif // CCONFIG_H
