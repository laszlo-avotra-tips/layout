#include "widgetcontainer.h"
#include "formnavigator.h"
#include "dialog.h"

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
    wid->setStyleSheet(m_stackedWidget->styleSheet());

    return index >= 0;
}

void WidgetContainer::setStackedWidget(QStackedWidget *sw)
{
    while(sw->count()){
        sw->removeWidget(sw->widget(0));
    }

    m_stackedWidget = sw;
}

bool WidgetContainer::gotoPage(const QString &name)
{
    bool success{false};
    auto it = m_container.find(name);
    if(it != m_container.end()){
        if(m_currentWidget){
            m_currentWidget->hide();
        }
        m_currentWidget = it->second;
        m_stackedWidget->setCurrentWidget(m_currentWidget);
        m_currentWidget->show();
    }

    return success;
}

QDialog *WidgetContainer::getDialog(const QString &name)
{
    QDialog* retVal{nullptr};
    auto it = m_container.find(name);
    if(it != m_container.end()){
        retVal = dynamic_cast<QDialog*>(it->second);
    }
    return retVal;
}

void WidgetContainer::close()
{
    m_navigator->close();
}

void WidgetContainer::setNavigator(FormNavigator *n)
{
    m_navigator = n;
}

WidgetContainer::WidgetContainer()
{

}

bool WidgetContainer::isFullScreen() const
{
    return m_isFullScreen;
}

void WidgetContainer::setIsFullScreen(bool isFullScreen)
{
    m_isFullScreen = isFullScreen;
}
