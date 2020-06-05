#include "dialogfactory.h"

#include "dialog.h"
#include "dialog2.h"
#include "keyboard.h"

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
        dialog->move(parent->x() - 1000, parent->y() + y);
    }
    return dialog;
}
