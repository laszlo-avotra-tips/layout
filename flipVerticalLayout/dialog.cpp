#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include "widgetcontainer.h"
#include "octkeyboard.h"

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
    QString paramName = ui->labelField->text();
    QString paramValue = ui->pushButtonField->text();

    const std::vector<QString> param{paramName, paramValue};
    auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
    ui->pushButtonField->setText(text);
}
