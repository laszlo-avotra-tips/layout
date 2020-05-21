#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <map>
#include <QString>
#include <QWidget>

class QStackedWidget;
class FormNavigator;

class WidgetContainer
{
public:
    static WidgetContainer* instance();
    bool registerWidget(const QString& name, QWidget* wid);
    void setStackedWidget(QStackedWidget* sw);
    bool gotoPage(const QString& name);
    void close();
    void setNavigator(FormNavigator* n);

private:
    WidgetContainer();

private:
    static WidgetContainer* m_instance;
    QStackedWidget* m_stackedWidget{nullptr};
    FormNavigator* m_navigator{nullptr};

    std::map<QString, QWidget*> m_container;
};

#endif // WIDGETCONTAINER_H
