#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include "widgetcontainer.h"
#include "consoleKeyboard.h"
#include "selectDialog.h"
#include "physicianNameModel.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_parent(parent)
{
    ui->setupUi(this);

    connect(ui->lineEditField, &myLineEdit::mousePressed, this, &Dialog::openKeyboard);
    setDefaultSelection();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::openKeyboard()
{
    if(!isFieldEmpty()){
        QString paramName = ui->labelField->text();
        const ParameterType param{paramName, ui->lineEditField->text(), "UPDATE"};
        auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
        ui->lineEditField->setText(text);
    }
}

void Dialog::on_pushButtonDown_clicked()
{
    auto* parent = this;
    m_selectDialog = new SelectDialog(parent);
    auto pw = parent->width();
    auto dw = m_selectDialog->width();
    int xVal = x() + pw/2 - dw/2 + 200;

    m_selectDialog->move(xVal, y() + 200);
    m_selectDialog->show();

    m_selectDialog->update(PhysicianNameModel::instance()->physicianNames());

    if(m_selectDialog->exec() == QDialog::Accepted){
        ui->lineEditField->setText(PhysicianNameModel::instance()->selectedPysicianName());
        ui->lineEditField->setStyleSheet("");
    } else {
        QString paramName = ui->labelField->text();
        const ParameterType param{paramName, "", "ADD NEW"};
        auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
        ui->lineEditField->setText(text);
    }
}

void Dialog::setDefaultSelection()
{
    auto defaultName = PhysicianNameModel::instance()->defaultPysicianName();
    if(!defaultName.isEmpty()){
        ui->lineEditField->setStyleSheet("");
        ui->lineEditField->setText(defaultName);
    }
}

bool Dialog::isFieldEmpty() const
{
    return ui->lineEditField->text() == QString("Required Field");
}
