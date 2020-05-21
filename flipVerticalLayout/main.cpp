#include "mainwindow.h"
#include "formnavigator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
////    w.showFullScreen();
//    w.show();
    FormNavigator navigator;
    navigator.show();
    return a.exec();
}
