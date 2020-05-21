#include "formstart.h"
#include "ui_formstart.h"
#include "widgetcontainer.h"

FormStart::FormStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStart)
{
    ui->setupUi(this);
}

FormStart::~FormStart()
{
    delete ui;
}

void FormStart::on_pushButton_clicked()
{
    WidgetContainer::instance()->gotoPage("mainWindow");
}
