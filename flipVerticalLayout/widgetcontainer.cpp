#include "widgetcontainer.h"

#include <QStackedWidget>

WidgetContainer* WidgetContainer::m_instance{nullptr};

WidgetContainer *WidgetContainer::instance()
{
    if(!m_instance){
        m_instance = new WidgetContainer();
    }
    return m_instance;
}

bool WidgetContainer::registerWidget(const QString &name, QWidget *wid)
{
    m_container[name] = wid;
    int index = m_stackedWidget->addWidget(wid);
    m_pages[index] = wid;

    return index > 0;
}

const std::map<QString, QWidget *> &WidgetContainer::getContainer() const
{
    return m_container;
}

void WidgetContainer::setStackedWidget(QStackedWidget *sw)
{
    m_stackedWidget = sw;
}

bool WidgetContainer::gotoPage(const QString &name)
{
    bool success{false};

    return success;
}

WidgetContainer::WidgetContainer()
{

}
