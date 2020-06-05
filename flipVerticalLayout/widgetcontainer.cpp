#include "widgetcontainer.h"
#include "formnavigator.h"
#include "dialog.h"

#include <QStackedWidget>
#include <QDebug>
#include <QWidget>

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
    m_widgetContainer[name] = wid;
    int index = m_stackedWidget->addWidget(wid);

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
    auto it = m_widgetContainer.find(name);
    if(it != m_widgetContainer.end()){
        if(m_currentWidget){
            m_currentWidget->hide();
        }
        m_currentWidget = it->second;
        m_stackedWidget->setCurrentWidget(m_currentWidget);
        m_currentWidget->show();
    }

    return success;
}

QDialog *WidgetContainer::getDialog(const QString &name, QWidget* parent, int y)
{
//    QDialog* retVal{nullptr};
//    auto it = m_dialogContainer.find(name);
//    if(it != m_dialogContainer.end())
//    {
//        retVal = it->second;
//        qDebug() << name << " found";
//    } else
//    {
//        retVal = m_dialogFactory.createDialog(name,parent);
//        m_dialogContainer[name] = retVal;
        qDebug() << name << " created";
//    }
//    return retVal;
    return m_dialogFactory.createDialog(name,parent,y);
}

std::pair<QDialog*, int> WidgetContainer::openDialog(QWidget *parent, const QString &name, int y)
{
    int result{-1};
    QDialog* dialog = getDialog(name,parent,y);

    if(dialog){
//        QVariant varY(y);
//        dialog->setProperty("Y",varY);
//        dialog->move(parent->geometry().x(), parent->geometry().y() + y);
        qDebug() << "X = " << dialog->x() << "Y = " << dialog->y();
        qDebug() << "parent.X = " << parent->x() << "parent.Y = " << parent->y();

        dialog->show();
        result = dialog->exec();
    }
    return std::pair<QDialog*,int>{dialog, result};
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
