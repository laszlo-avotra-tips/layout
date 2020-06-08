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

    connect(ui->lineEditField, &myLineEdit::mousePressed, this, &Dialog::openKeyboard);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::openKeyboard()
{
    QString paramName = ui->labelField->text();
    const ParameterType param{{paramName}, {ui->lineEditField}};
    auto text = WidgetContainer::instance()->openKeyboard(this, param, 200);
    ui->lineEditField->setText(text);
}
