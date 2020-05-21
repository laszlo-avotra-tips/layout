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
    m_pages[wid] = index;

    return index > 0;
}

const std::map<QString, QWidget *> &WidgetContainer::getContainer() const
{
    return m_container;
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
        auto itt = m_pages.find(it->second);
        if(itt != m_pages.end()){
             m_stackedWidget->setCurrentIndex(itt->second);
             success = true;
        }
    }

    return success;
}

WidgetContainer::WidgetContainer()
{

}
