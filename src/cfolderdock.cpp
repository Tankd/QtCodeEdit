#include "cfolderdock.h"
#include "ui_cfolderdock.h"

#include <QDebug>

#include "cconfig.h"

CFolderDock::CFolderDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::CFolderDock),_model(0)
{
    ui->setupUi(this);

    _model = new QFileSystemModel(this);
    _model->setRootPath(QDir::currentPath());
    ui->folderView->setModel( _model);

    ui->folderView->hideColumn(1);
    ui->folderView->hideColumn(2);
    ui->folderView->hideColumn(3);
    ui->folderView->hideColumn(4);

}

CFolderDock::~CFolderDock()
{
    delete _model;
    delete ui;
}
QString CFolderDock::currentFolder() const
{
    return _currentFolder;
}

void CFolderDock::setCurrentFolder(const QString &currentFolder)
{
    _currentFolder = currentFolder;
    _model->setRootPath(_currentFolder);
    ui->folderView->setRootIndex(_model->index(_currentFolder));

    CConfig::instance()->setValue("folderView/path", _currentFolder);
}


void CFolderDock::on_folderView_doubleClicked(const QModelIndex &index)
{
    emit open(_model->filePath(index));
}
