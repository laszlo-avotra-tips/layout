#include "dialogfactory.h"

#include "dialog.h"
#include "dialog2.h"
#include "keyboard.h"
#include <QDebug>

DialogFactory::DialogFactory()
{

}

QDialog *DialogFactory::createDialog(const QString &name, QWidget *parent, int y)
{
    QDialog* dialog{nullptr};

    if(name == "mainWindowDialog"){
        dialog = new Dialog(parent);
    }
    if(name == "greenDialog"){
        dialog = new Dialog2(parent);
    }
    if(name == "keyboard"){
        dialog = new keyboard(parent);
        auto pw = parent->width();
        auto dw = dialog->width();
        int x = parent->x() + pw/2 - dw/2;
        qDebug() << __FUNCTION__ << " dialog->width()=" << dw
                 << " parent->width()=" << pw;
        dialog->move(x, parent->y() + y);
    }
    return dialog;
}
