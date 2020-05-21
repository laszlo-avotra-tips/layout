#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetcontainer.h"
#include "pagefactory.h"

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
    const int w{getSceneSize()};
    const int h{w * m_widthHeight.second / m_widthHeight.first};

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
    QLayout* tl = layout();
    std::vector<QLayoutItem*> current{tl->itemAt(0),tl->itemAt(1),tl->itemAt(2)};

    tl->removeItem(current[2]);
    tl->removeItem(current[1]);
    tl->removeItem(current[0]);
    tl->addItem(current[2]);
    tl->addItem(current[1]);
    tl->addItem(current[0]);
    tl->update();
}

void MainWindow::on_pushButtonPage1_clicked()
{

}

void MainWindow::on_pushButtonPage2_clicked()
{
}

void MainWindow::on_pushButtonExitL_clicked()
{
    WidgetContainer::instance()->gotoPage("startPage");
}

int MainWindow::getSceneSize() const
{
    return m_sceneSize;
}
