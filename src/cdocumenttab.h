#ifndef CDOCUMENTTAB_H
#define CDOCUMENTTAB_H

#include <QTabWidget>

class CDocumentTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit CDocumentTab(QWidget *parent = 0);

signals:

protected slots:
    void closeTab(int index);

};

#endif // CDOCUMENTTAB_H
