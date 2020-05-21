#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <map>
#include <QString>
#include <QWidget>

class QStackedWidget;

class WidgetContainer
{
public:
    static WidgetContainer* instance();
    bool registerWidget(const QString& name, QWidget* wid);
    const std::map<QString, QWidget*>& getContainer() const;
    void setStackedWidget(QStackedWidget* sw);
    bool gotoPage(const QString& name);

private:
    WidgetContainer();

private:
    static WidgetContainer* m_instance;
    QStackedWidget* m_stackedWidget{nullptr};

    std::map<QString, QWidget*> m_container;
    std::map<int,QWidget*> m_pages;
};

#endif // WIDGETCONTAINER_H
