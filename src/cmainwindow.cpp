#include "cmainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QMenuBar>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QStatusBar>

#include "cdocument.h"
#include "cconfig.h"
#include "cmenubar.h"
#include "cwindowbutton.h"


CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::Window),
    _tab(0), _folderDock(0), _windowButton(0), _lineLabel(0), _codecLabel(0)
{

    _tab = new CDocumentTab();

    this->setCentralWidget( _tab);

    folderDockOpenLast();

    QMenuBar *bar = new QMenuBar();

    //QMenu *menu = bar->contextMenu();
    QMenu *menu = bar->addMenu("menu");

    QAction *action;

    action = new QAction("new", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_New_triggered);
    menu->addAction(action);

    menu->addSeparator();

    action = new QAction("open", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_Open_triggered);
    menu->addAction(action);

    action = new QAction("save", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_Save_triggered);
    menu->addAction(action);

    action = new QAction("save as", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_Save_As_triggered);
    menu->addAction(action);

    action = new QAction("close", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_Close_triggered);
    menu->addAction(action);

    menu->addSeparator();

     QMenu *subMenu = menu->addMenu("View");
    action = new QAction("open folder", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_open_Folder_triggered);
    subMenu->addAction(action);

    action = new QAction("show fullscreen", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_FullScreen_triggered);
    subMenu->addAction(action);

    menu->addSeparator();

    action = new QAction("Quit", menu);
    connect( action, &QAction::triggered, this, &CMainWindow::on_action_Quit_triggered);
    menu->addAction(action);



    this->setMenuBar( bar);

    //_windowButton = new CWindowButton(this);
    resize(800, 600);

    this->setStatusBar( new QStatusBar());
    this->statusBar()->showMessage(tr("Ready"));

    _codecLabel = new QLabel("UTF-8");
    this->statusBar()->addPermanentWidget( _codecLabel);

    _lineLabel = new QLabel("ln 0, col 0");
    this->statusBar()->addPermanentWidget( _lineLabel);




    QStringList args = qApp->arguments();
    args.removeFirst();

    if( args.isEmpty() == false)
    {
        foreach( const QString& fileName, args)
        {
            if(QFileInfo(fileName).exists() == true)
            {
                CDocument *doc = new CDocument;
                doc->open( fileName );
                _tab->setCurrentIndex( _tab->addTab( doc, doc->title()));
            }
        }
    }
    else
        on_action_New_triggered();


}
CMainWindow::~CMainWindow()
{
    delete _windowButton;
    delete _tab;
    delete _folderDock;
    delete _codecLabel;
    delete _lineLabel;
}


void CMainWindow::resizeEvent(QResizeEvent *event)
{
    if( _windowButton)
    {
        _windowButton->move(event->size().width() - _windowButton->width() -10, 0);
    }
}




void CMainWindow::on_action_New_triggered()
{
    CDocument *doc = new CDocument;

    _tab->setCurrentIndex(_tab->addTab( doc, "new"));
}

void CMainWindow::on_action_Open_triggered()
{
    CDocument *doc = new CDocument;
    doc->open( );
    _tab->setCurrentIndex( _tab->addTab( doc, doc->title()));
}

void CMainWindow::on_action_Save_triggered()
{
    if( _tab->count() == 0) return;

    CDocument* doc = reinterpret_cast<CDocument*>( _tab->currentWidget());
    if( doc)
    {
        doc->save();
    }
}

void CMainWindow::on_action_Save_As_triggered()
{
    if( _tab->count() == 0) return;

    CDocument* doc = reinterpret_cast<CDocument*>( _tab->currentWidget());
    if( doc)
    {
        doc->saveAs();
    }
}

void CMainWindow::on_action_Close_triggered()
{
    if( _tab->count() == 0) return;

    CDocument* doc = reinterpret_cast<CDocument*>( _tab->currentWidget());
    if( doc)
    {
    }
}



void CMainWindow::on_action_open_Folder_triggered()
{
    QString path = QFileDialog::getExistingDirectory(this, "open folder", CConfig::instance()->value("folderView/path").toString());
    if(path.isEmpty()) return;

    if( _folderDock == NULL)
    {
        _folderDock = new CFolderDock();
        connect( _folderDock, &CFolderDock::open, this, &CMainWindow::folderDockOpen);
    }

    _folderDock->setCurrentFolder( path);

    this->addDockWidget(Qt::LeftDockWidgetArea, _folderDock);

    _folderDock->setCurrentFolder(path);
    _folderDock->show();
}



void CMainWindow::folderDockOpenLast()
{
    QString path = CConfig::instance()->value("folderView/path").toString();

    if( _folderDock == NULL)
    {
        _folderDock = new CFolderDock();
        connect( _folderDock, &CFolderDock::open, this, &CMainWindow::folderDockOpen);
    }

    _folderDock->setCurrentFolder( path);

    this->addDockWidget(Qt::LeftDockWidgetArea, _folderDock);

    _folderDock->setCurrentFolder(path);
    _folderDock->show();
}

void CMainWindow::folderDockOpen(QString path)
{
    if(path.isEmpty())
        return;

    if( QFileInfo(path).exists() == false || QFileInfo(path).isFile() == false)
        return;

    CDocument *doc = new CDocument;
    doc->open( path);
    _tab->setCurrentIndex(_tab->addTab( doc, doc->title()));
}

void CMainWindow::on_action_FullScreen_triggered()
{

}

void CMainWindow::on_action_Quit_triggered()
{
    this->close();
}


