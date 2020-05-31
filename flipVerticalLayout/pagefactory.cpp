#include "pagefactory.h"
#include "formstart.h"
#include "widgetcontainer.h"
#include "mainwindow.h"
#include "dialog.h"

PageFactory::PageFactory()
{

    MainWindow* mainWindow = new MainWindow();
    WidgetContainer::instance()->registerWidget("mainPage", mainWindow);

    Dialog* dialog = new Dialog(mainWindow);
    WidgetContainer::instance()->registerWidget("mainWindowDialog", dialog);

    FormStart* formStart = new FormStart();
    WidgetContainer::instance()->registerWidget("startPage", formStart);

}
