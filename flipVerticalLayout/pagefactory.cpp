#include "pagefactory.h"
#include "formstart.h"
#include "widgetcontainer.h"

PageFactory::PageFactory()
{
    FormStart* formStart = new FormStart();
    WidgetContainer::instance()->registerWidget("pageStart", formStart);
}
