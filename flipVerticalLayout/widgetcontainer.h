#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <vector>
#include <map>
#include <QString>
#include "dialogfactory.h"

class QStackedWidget;
class FormNavigator;
class QDialog;

class WidgetContainer
{
public:
    static WidgetContainer* instance();
    bool registerWidget(const QString& name, QWidget* wid);
    void setStackedWidget(QStackedWidget* sw);
    bool gotoPage(const QString& name);
    QDialog* getDialog(const QString& name, QWidget* parent);
    std::pair<QDialog *, int> openDialog(QWidget* parent, const QString& name);
    QString openKeyboard(QWidget* parent, const std::vector<QString>& param, int yOffset = 0);
    void close();
    void setNavigator(FormNavigator* n);

    bool isFullScreen() const;
    void setIsFullScreen(bool isFullScreen);

private:

private:
    static WidgetContainer* m_instance;
    WidgetContainer() = default;

    DialogFactory m_dialogFactory;
    QStackedWidget* m_stackedWidget{nullptr};
    FormNavigator* m_navigator{nullptr};

    std::map<QString, QWidget*> m_widgetContainer;
    std::map<QString, QDialog*> m_dialogContainer;

    bool m_isFullScreen{true};
    QWidget* m_currentWidget{nullptr};
};

#endif // WIDGETCONTAINER_H
