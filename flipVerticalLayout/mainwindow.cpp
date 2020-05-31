#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetcontainer.h"
#include "pagefactory.h"
#include "dialog.h"

#include <QDebug>
#include <QLayoutItem>
#include <QLayout>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButtonFlip->hide();

    ui->frameButtons->hide();
    const int h{1024/getSceneSize()};
    double dw = h * 1.5;
    const int w{ int(dw) };

    qDebug() << "w = " << w << ", h = " << h << ", w/h = " << float(w)/float(h);
    const QSize sizeMiddle{h,h};
    const QSize sizeSide{(w-h)/2,h};

    ui->frameM->setMaximumSize(sizeMiddle);
    ui->frameM->setMinimumSize(sizeMiddle);

    ui->frameL->setMaximumSize(sizeSide);
    ui->frameL->setMinimumSize(sizeSide);
    ui->frameR->setMaximumSize(sizeSide);
    ui->frameR->setMinimumSize(sizeSide);

    auto* buttonLayout = ui->frameButtons->layout();
    const int bc = buttonLayout->count();
    if(bc){
        buttonLayout->setSpacing(h/bc);
    }
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

void MainWindow::popDialog()
{
    QDialog* dialog = new Dialog(this); //WidgetContainer::instance()->getDialog("mainWindowDialog");
//    if(m_dialog){
//        m_dialog->setParent(this);
//    }
    if(dialog){
        dialog->setModal(true);
        dialog->show();
        auto result = dialog->exec();
        if( result == QDialog::Accepted){
            qDebug() << "Accepted";
        } else {
            qDebug() << "Cancelled";
            WidgetContainer::instance()->gotoPage("startPage");
        }
    }
    qDebug() << "Next";
}

void MainWindow::on_pushButtonPage1_clicked()
{
    popDialog();
}

void MainWindow::on_pushButtonPage2_clicked()
{
}

void MainWindow::on_pushButtonExitL_clicked()
{
    WidgetContainer::instance()->gotoPage("startPage");
}

int MainWindow::getSceneSize()
{
    int retVal = m_sceneSize;
    QString fn("/Avinger_System/screen.dat");
    QFile sf(fn);
    if(sf.open(QIODevice::ReadOnly)){
        qDebug() << fn << " open ok";
        QTextStream ts(&sf);
        int size;
        int isFullScreen;
        ts >> size >> isFullScreen;
        qDebug() << fn << " open ok. size = " << size << ", isFullScreen " << isFullScreen;
        WidgetContainer::instance()->setIsFullScreen(isFullScreen);
        retVal = size;
        sf.close();
    }

    return retVal;
}

void MainWindow::showEvent(QShowEvent *se)
{
    QWidget::showEvent( se );
    qDebug() << __FUNCTION__;
    QTimer::singleShot(100,this, &MainWindow::popDialog);
}

void MainWindow::hideEvent(QHideEvent *he)
{
    QWidget::hideEvent( he );
    qDebug() << __FUNCTION__;

}
