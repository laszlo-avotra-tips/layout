#include "formnavigator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormNavigator navigator;
    navigator.show(); //navigator.showFullScreen();
    return a.exec();
}
