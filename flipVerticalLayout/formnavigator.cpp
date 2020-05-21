#include "formnavigator.h"
#include "ui_formnavigator.h"
#include "widgetcontainer.h"
#include "pagefactory.h"
#include <QDebug>

FormNavigator::FormNavigator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormNavigator)
{
    ui->setupUi(this);

    auto* stack = ui->stackedWidget;

    auto* widgets = WidgetContainer::instance();

    widgets->setStackedWidget(stack);
    PageFactory pf;

    int count = stack->count();

    qDebug() << "page count = " << count;

//    ui->stackedWidget->setCurrentIndex(count - 1);
    widgets->gotoPage("startPage");
}

FormNavigator::~FormNavigator()
{
    delete ui;
}
