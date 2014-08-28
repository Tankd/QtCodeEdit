#ifndef CDOCUMENT_H
#define CDOCUMENT_H

#include "ccodeedit.h"
class QTextCodec;

class CDocument : public CCodeEdit
{
    Q_OBJECT
signals:
    void titleChanged( QString title);
public:
    explicit CDocument(QWidget *parent = 0);
    virtual ~CDocument();

    QString fileName() const;
    void setFileName(const QString &fileName);

    QString title() const;


signals:

public slots:
    void open(const QString &fileName = QString());
    void save();
    void saveAs( );

     void setTitle(const QString &title);



protected:
    QString _fileName;
    QString _title;

    QTextCodec* _codec;


    void setupScintilla();

};

#endif // CDOCUMENT_H
