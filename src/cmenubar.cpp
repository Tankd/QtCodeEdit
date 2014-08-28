#include "cmenubar.h"

#include <QMouseEvent>
#include <QToolButton>
CMenuBar::CMenuBar(QWidget *parent) :
    QMenuBar(parent), _contextMenu(0)
{
    addMenu(" ");
    QToolButton *button = new QToolButton(this);
    button->setFixedSize(48, 24);
    button->setText("Menu");
    connect( button, &QToolButton::clicked, this, &CMenuBar::menuClicked);

    _contextMenu = new QMenu(this);
}

CMenuBar::~CMenuBar()
{
    delete _contextMenu;
}


void CMenuBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        _moving = true;
        _mousePos = event->pos();
        parentWidget()->setCursor(QCursor(Qt::SizeAllCursor));
    }
}

void CMenuBar::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && _moving)
    {
        parentWidget()->move(  event->globalPos() - _mousePos );
    }
}

void CMenuBar::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        _moving = false;
        parentWidget()->setCursor(QCursor(Qt::ArrowCursor));
    }
}

void CMenuBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    parentWidget()->isMaximized() ? parentWidget()->showNormal(): parentWidget()->showMaximized();
}
QMenu *CMenuBar::contextMenu() const
{
    return _contextMenu;
}

void CMenuBar::menuClicked(bool checked)
{
    QPoint p = pos();
    p.setY( p.y() + 24);
    _contextMenu->popup(this->mapToGlobal(p));
}
