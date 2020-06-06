#include "keyboard.h"
#include "ui_keyboard.h"

keyboard::keyboard(const vector<QString> &param, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyboard)
{
    ui->setupUi(this);

    auto paramLabel = ui->labelParam;
    auto paramLineEdit = ui->lineEditParam;

    paramLabel->setText(param[0]);
    paramLineEdit->setText(param[1]);

    auto* enterButton = ui->pushButton_enter;
    connect(enterButton, &QPushButton::clicked, this, &QDialog::accept);
}

keyboard::~keyboard()
{
    delete ui;
}

QString keyboard::editResult()
{
    return ui->lineEditParam->text();
}
