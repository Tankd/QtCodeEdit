#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QLabel>
#include "cfolderdock.h"


#include "cdocumenttab.h"


class CWindowButton;



class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();


private slots:
    void on_action_New_triggered();
    void on_action_Open_triggered();
    void on_action_Save_triggered();
    void on_action_Save_As_triggered();
    void on_action_Close_triggered();

    void on_action_open_Folder_triggered();    
    void on_action_FullScreen_triggered();

    void on_action_Quit_triggered();


    void folderDockOpenLast();
    void folderDockOpen(QString path);





protected:
    virtual void resizeEvent(QResizeEvent* event);

private:


    CDocumentTab *_tab;
    CFolderDock *_folderDock;
    CWindowButton* _windowButton;


    QLabel *_lineLabel;
    QLabel *_codecLabel;    
};

#endif // CMAINWINDOW_H
