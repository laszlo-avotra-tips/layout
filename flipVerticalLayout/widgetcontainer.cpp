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

    return index >= 0;
}

void WidgetContainer::setStackedWidget(QStackedWidget *sw)
{
    sw->removeWidget(sw->widget(0));
    sw->removeWidget(sw->widget(0));

    m_stackedWidget = sw;
}

bool WidgetContainer::gotoPage(const QString &name)
{
    bool success{false};
    auto it = m_container.find(name);
    if(it != m_container.end()){
        m_stackedWidget->setCurrentWidget(it->second);
    }

    return success;
}

WidgetContainer::WidgetContainer()
{

}
