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

    const QSize sizeMiddle{h,h};
    const QSize sizeSide{(w-h)/2,h};

    ui->frameM->setMaximumSize(sizeMiddle);
    ui->frameM->setMinimumSize(sizeMiddle);

    ui->frameL->setMaximumSize(sizeSide);
    ui->frameL->setMinimumSize(sizeSide);
    ui->frameR->setMaximumSize(sizeSide);
    ui->frameR->setMinimumSize(sizeSide);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonFlip_clicked()
{
    flipColumns();
}


void MainWindow::on_pushButtonMenu_clicked()
{
    if(!ui->frameButtons->isVisible()){
        ui->frameButtons->show();
        ui->pushButtonFlip->show();
        ui->pushButtonMenu->setText("Hide Menu");
    } else {
        ui->frameButtons->hide();
        ui->pushButtonFlip->hide();
        ui->pushButtonMenu->setText("Show Menu");
    }
}

void MainWindow::flipColumns()
{
    QLayout* tl = this->layout();
    std::vector<QLayoutItem*> current{tl->itemAt(0),tl->itemAt(1),tl->itemAt(2)};

    tl->removeItem(current[2]);
    tl->removeItem(current[1]);
    tl->removeItem(current[0]);
    tl->addItem(current[2]);
    tl->addItem(current[1]);
    tl->addItem(current[0]);
    tl->update();
}
