#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QMenuBar>

class CMenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit CMenuBar(QWidget *parent = 0);
    virtual ~CMenuBar();

    QMenu *contextMenu() const;

signals:

protected slots:
    void menuClicked(bool checked);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);


private:

    bool _moving;
    QPoint _mousePos;

    QMenu *_contextMenu;
};

#endif // CMENUBAR_H
