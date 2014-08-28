#ifndef CWINDOWBUTTON_H
#define CWINDOWBUTTON_H

#include <QWidget>

class CWindowButton : public QWidget
{
    Q_OBJECT
public:
    explicit CWindowButton(QWidget *parent = 0);


protected slots:
    void maximized();

};

#endif // CWINDOWBUTTON_H
