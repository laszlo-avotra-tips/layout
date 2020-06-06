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

void Dialog::on_pushButtonField_clicked()
{
    const std::vector<QString> param{"ParamName", "Value"};
    auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
    ui->pushButtonField->setText(text);
}
