#ifndef CFOLDERDOCK_H
#define CFOLDERDOCK_H

#include <QDockWidget>
#include <QFileSystemModel>

namespace Ui {
class CFolderDock;
}

class CFolderDock : public QDockWidget
{
    Q_OBJECT
signals:
    void open( QString filePath);

public:
    explicit CFolderDock(QWidget *parent = 0);
    ~CFolderDock();

    QString currentFolder() const;
    void setCurrentFolder(const QString &currentFolder);

private slots:
    void on_folderView_doubleClicked(const QModelIndex &index);

private:
    Ui::CFolderDock *ui;

    QString _currentFolder;
    QFileSystemModel *_model;
};

#endif // CFOLDERDOCK_H
