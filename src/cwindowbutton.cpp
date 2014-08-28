#include "cwindowbutton.h"
#include <QHBoxLayout>
#include <QToolButton>

#include <QMainWindow>

CWindowButton::CWindowButton(QWidget *parent) :
    QWidget(parent)
{
    QSize size = QSize(32, 24);

    this->setMinimumSize(size.width()*3+4, size.height());
    this->setMaximumSize(size.width()*3+4, size.height());

    QHBoxLayout* layout = new QHBoxLayout(this);
    QToolButton* button;

    button = new QToolButton();
    button->setText("_ ");
    button->setMinimumSize(size);
    button->setMaximumSize(size);
    layout->addWidget( button);
    connect(button, &QToolButton::clicked, parentWidget(), &QMainWindow::showMinimized);

    button = new QToolButton();
    button->setText("O");
    button->setMinimumSize(size);
    button->setMaximumSize(size);
    layout->addWidget( button);
        connect(button, &QToolButton::clicked, this, &CWindowButton::maximized);

    button = new QToolButton();
    button->setText("X");
    button->setMinimumSize(size);
    button->setMaximumSize(size);
    layout->addWidget( button);
    connect(button, &QToolButton::clicked, parentWidget(), &QMainWindow::close);


    layout->setContentsMargins(2, 2, 2, 2);

    this->setLayout(layout);

}

void CWindowButton::maximized()
{
    parentWidget()->isMaximized() ? parentWidget()->showNormal(): parentWidget()->showMaximized();
}
