#include "cdocumenttab.h"
#include "cdocument.h"

CDocumentTab::CDocumentTab(QWidget *parent) :
    QTabWidget(parent)
{
    this->setTabsClosable(true);
    this->setMovable(true);

    connect( this, &QTabWidget::tabCloseRequested, this, &CDocumentTab::closeTab);
}

void CDocumentTab::closeTab(int index)
{
    CDocument *doc = reinterpret_cast<CDocument*>( this->widget(index));
    removeTab( index);
    delete doc;

}
