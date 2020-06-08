#include "dialog2.h"
#include "ui_dialog2.h"
#include "widgetcontainer.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &myLineEdit::mousePressed, this, &Dialog2::openKeyboard);
    connect(ui->lineEdit_2, &myLineEdit::mousePressed, this, &Dialog2::openKeyboard2);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::openKeyboard()
{
    QString paramName = ui->label->text();
    auto* paramValue = ui->lineEdit;

    const ParameterType param{{paramName}, {paramValue}};
    auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
    paramValue->setText(text);
}

void Dialog2::openKeyboard2()
{
    QString paramName = ui->label_2->text();
    myLineEdit* paramValue = ui->lineEdit_2;

    const ParameterType param{{paramName}, {paramValue}};
    auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
    paramValue->setText(text);
}
