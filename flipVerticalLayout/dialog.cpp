#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include "widgetcontainer.h"
#include "keyboard.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_parent(parent)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonName_clicked()
{
    qDebug() << __FUNCTION__;
    auto result = WidgetContainer::instance()->openDialog(this,"keyboard",100);
    if( result.second == QDialog::Accepted){
        qDebug() << "Accepted";
        keyboard* kb = dynamic_cast<keyboard*>(result.first);
        if(kb){
            ui->pushButtonName->setText(kb->name());
        }
    } else {
        qDebug() << "Cancelled";
    }
}
