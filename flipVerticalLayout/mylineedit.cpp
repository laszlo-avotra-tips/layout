#include <QDebug>
#include <QMouseEvent>

#include "mylineedit.h"

myLineEdit::myLineEdit(QWidget *parent):QLineEdit(parent)
{

}

void myLineEdit::mousePressEvent(QMouseEvent *e)
{
    auto bt = e->buttons();
    if(bt == Qt::LeftButton){
        qDebug() << __FUNCTION__ << " left";
        e->accept();
        emit mousePressed();
    }else if(bt == Qt::RightButton){
        qDebug() << __FUNCTION__ << " right";
        e->accept();
    }else{
        qDebug() << __FUNCTION__ << " pass";
        e->ignore();
    }
}
