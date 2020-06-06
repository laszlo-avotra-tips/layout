#include "widgetcontainer.h"
#include "formnavigator.h"
#include "dialog.h"
#include "octkeyboard.h"

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

QDialog *WidgetContainer::getDialog(const QString &name, QWidget* parent)
{
    return m_dialogFactory.createDialog(name,parent);
}

std::pair<QDialog*, int> WidgetContainer::openDialog(QWidget *parent, const QString &name)
{
    int result{-1};
    QDialog* dialog = getDialog(name,parent);

    if(dialog){
        dialog->show();
        result = dialog->exec();
    }
    return std::pair<QDialog*,int>{dialog, result};
}

QString WidgetContainer::openKeyboard(QWidget *parent, const std::vector<QString>& param, int yOffset)
{
    QString retVal;
    OctKeyboard* okb = new OctKeyboard(param, parent);
    auto pw = parent->width();
    auto dw = okb->width();
    int x = parent->x() + pw/2 - dw/2;

    okb->move(x, parent->y() + yOffset);
    okb->show();

    if(okb->exec() == QDialog::Accepted){
        retVal = okb->value();
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

//WidgetContainer::WidgetContainer()
//{

//}

bool WidgetContainer::isFullScreen() const
{
    return m_isFullScreen;
}

void WidgetContainer::setIsFullScreen(bool isFullScreen)
{
    m_isFullScreen = isFullScreen;
}
