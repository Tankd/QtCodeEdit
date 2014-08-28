#include "cdocument.h"

#include <QFile>
#include <QFileDialog>
#include <QTextCodec>
#include <QDebug>




CDocument::CDocument(QWidget *parent) :
    CCodeEdit (parent), _codec(0)
{    
    _codec = QTextCodec::codecForName("UTF-8");
}

CDocument::~CDocument()
{

}
QString CDocument::fileName() const
{
    return _fileName;
}

void CDocument::setFileName(const QString &fileName)
{
    _fileName = fileName;

    QString t = _fileName;
    t.remove( 0, t.lastIndexOf("/")+1);
    setTitle(t);
}

void CDocument::open(const QString& fileName)
{
    QString str = fileName;

    if( str.isEmpty())
    {
        str = QFileDialog::getOpenFileName(this, "Open document");
    }
    if(str.isEmpty()) return;

    setFileName(str);

    QFile in(_fileName);
    in.open( QFile::ReadOnly | QFile::Text);
    if(in.isOpen() == false)
        return;

    QByteArray data = in.readAll();
    _codec = QTextCodec::codecForUtfText(data);

    this->setPlainText( _codec->toUnicode(data).toLocal8Bit());

    in.close();
}

void CDocument::save()
{
    if( _fileName.isEmpty())
        return;

    QFile out( _fileName);

    out.open(QFile::WriteOnly  | QFile::Truncate);
    if(out.isOpen() == false)
        return;

    out.write( this->toPlainText().toLocal8Bit());
    out.close();

}

void CDocument::saveAs()
{
    QString str = QFileDialog::getSaveFileName(this, "Save document as");
    if(str.isEmpty()) return;
    setFileName(str);

    save();
}
QString CDocument::title() const
{
    return _title;
}

void CDocument::setTitle(const QString &title)
{
    _title = title;
    emit titleChanged( _title);
}



