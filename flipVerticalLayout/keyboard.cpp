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

    auto deleteButton = ui->pushButton_delete;
    connect(deleteButton, &QPushButton::clicked, this, &keyboard::handleDelete);

}

keyboard::~keyboard()
{
    delete ui;
}

QString keyboard::editResult()
{
    return ui->lineEditParam->text();
}

void keyboard::handleDelete()
{
    auto target = ui->lineEditParam;
    auto param = target->text();
    if(!param.isEmpty()){
       int lastPosition = param.size() - 1;
       target->setText(param.remove(lastPosition,1));
    }
}
