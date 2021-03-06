#include "dialogfactory.h"

#include "dialog.h"
#include "dialog2.h"
#include "selectDialog.h"
#include <QDebug>

DialogFactory::DialogFactory()
{

}

QDialog *DialogFactory::createDialog(const QString &name, QWidget *parent)
{
    QDialog* dialog{nullptr};

    if(name == "mainWindowDialog"){
        dialog = new Dialog(parent);
    }
    if(name == "greenDialog"){
        dialog = new Dialog2(parent);
    }
    if(name == "selectDialog"){
        dialog = new SelectDialog(parent);
    }
    return dialog;
}
