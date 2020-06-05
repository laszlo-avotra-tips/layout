#include "formnavigator.h"
#include "pagefactory.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QApplication a(argc, argv);
    FormNavigator navigator;
    navigator.display(); //navigator.showFullScreen();
    return a.exec();
}
