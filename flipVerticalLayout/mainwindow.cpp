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
    ui->pushButtonFlip->hide();

    ui->frameButtons->hide();
    const int w{m_sceneSize};
    const int h{m_sceneSize * m_widthHeight.second / m_widthHeight.first};
    resize(w,h+40);
    ui->frameM->setMaximumSize(h,h);
    ui->frameM->setMinimumSize(h,h);
    ui->frameL->setMaximumSize((w-h)/2,h+40);
    ui->frameL->setMinimumSize((w-h)/2,h+40);
    ui->frameR->setMaximumSize((w-h)/2,h+40);
    ui->frameR->setMinimumSize((w-h)/2,h+40);

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
//    ui->pushButton->hide();
//    ui->pushButtonL->hide();
//    ui->pushButtonExitL->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonFlip_clicked()
{
}


void MainWindow::on_pushButtonShow_clicked()
{
    if(!ui->frameButtons->isVisible()){
        ui->frameButtons->show();
        ui->pushButtonFlip->show();
    } else {
        ui->frameButtons->hide();
        ui->pushButtonFlip->hide();
    }
}

void MainWindow::on_pushButtonTest_clicked()
{
    QLayout* tl = this->layout();
    qDebug() << tl->count();
    std::vector<QLayoutItem*> current{tl->itemAt(0),tl->itemAt(1),tl->itemAt(2)};
    std::vector<QLayoutItem*> flipped{tl->itemAt(2),tl->itemAt(1),tl->itemAt(0)};

    tl->removeItem(current[2]);
    tl->removeItem(current[1]);
    tl->removeItem(current[0]);
    tl->addItem(current[2]);
    tl->addItem(current[1]);
    tl->addItem(current[0]);
    tl->update();
}
