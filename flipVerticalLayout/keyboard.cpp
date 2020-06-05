#include "keyboard.h"
#include "ui_keyboard.h"

keyboard::keyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyboard)
{
    ui->setupUi(this);
}

keyboard::~keyboard()
{
    delete ui;
}

QString keyboard::name()
{
    return ui->lineEditParam->text();
}
