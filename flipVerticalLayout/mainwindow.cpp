#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QLayoutItem>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frameBR->hide();
    ui->pushButtonShowButtonsR->hide();
    ui->pushButtonFlipR->hide();
    ui->pushButtonFlipL->hide();

    ui->frameTL->hide();
    ui->frameBL->hide();
    const int w{m_sceneSize};
    const int h{m_sceneSize * m_widthHeight.second / m_widthHeight.first};
    resize(w,h);
    ui->graphicsView->resize(w,w);

    QLayout* tl = this->layout();
    qDebug() << tl->count();
    std::vector<QLayoutItem*> menuOnTheLeft{tl->itemAt(0),tl->itemAt(1),tl->itemAt(2)};
    std::vector<QLayoutItem*> menuOnTheRight{tl->itemAt(2),tl->itemAt(1),tl->itemAt(0)};
    //takeAt
    //update
    //invalidate
    //activate
    //removeItem
    //adItem
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonFlipL_clicked()
{
    ui->frameBL->hide();
    ui->frameBR->show();
    ui->pushButtonShowButtonsL->hide();
    ui->pushButtonShowButtonsR->show();
    ui->frameTR->hide();
    ui->frameTL->show();
    ui->pushButtonFlipL->hide();
    ui->pushButtonFlipR->show();
}

void MainWindow::on_pushButtonFlipR_clicked()
{
    ui->frameBL->show();
    ui->frameBR->hide();
    ui->pushButtonShowButtonsL->show();
    ui->pushButtonShowButtonsR->hide();
    ui->frameTL->hide();
    ui->frameTR->show();
    ui->pushButtonFlipL->show();
    ui->pushButtonFlipR->hide();
}

void MainWindow::on_pushButtonShowButtonsL_clicked()
{
    if(!ui->frameBL->isVisible()){
        ui->frameBL->show();
        ui->pushButtonFlipL->show();
        ui->frameTR->show();
    } else {
        ui->frameBL->hide();
        ui->pushButtonFlipL->hide();
    }
}

void MainWindow::on_pushButtonShowButtonsR_clicked()
{
    if(!ui->frameBR->isVisible()){
        ui->frameBR->show();
        ui->pushButtonFlipR->show();
        ui->frameTL->show();
    } else {
        ui->frameBR->hide();
        ui->pushButtonFlipR->hide();
    }
}
