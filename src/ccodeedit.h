#ifndef CCODEEDIT_H
#define CCODEEDIT_H

#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>


class CCodeEdit : public QPlainTextEdit
 {
     Q_OBJECT

 public:
     CCodeEdit(QWidget *parent = 0);

     void lineNumberAreaPaintEvent(QPaintEvent *event);
     int lineNumberAreaWidth();

 protected:
     void resizeEvent(QResizeEvent *event);

 private slots:
     void updateLineNumberAreaWidth(int newBlockCount);     
     void updateLineNumberArea(const QRect &, int);

 private:
     QWidget *lineNumberArea;
 };

class LineNumberArea : public QWidget
 {
 public:
     LineNumberArea(CCodeEdit *editor) : QWidget(editor) {
         codeEditor = editor;
     }

     QSize sizeHint() const {
         return QSize(codeEditor->lineNumberAreaWidth(), 0);
     }

 protected:
     void paintEvent(QPaintEvent *event) {
         codeEditor->lineNumberAreaPaintEvent(event);
     }

 private:
     CCodeEdit *codeEditor;
 };

#endif // CCODEEDIT_H
