#include "pagefactory.h"
#include "formstart.h"
#include "widgetcontainer.h"
#include "mainwindow.h"

PageFactory::PageFactory()
{
    MainWindow* mainWindow = new MainWindow();
    WidgetContainer::instance()->registerWidget("mainWindow", mainWindow);

    FormStart* formStart = new FormStart();
    WidgetContainer::instance()->registerWidget("pageStart", formStart);
}
