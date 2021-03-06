#ifndef DIALOGFACTORY_H
#define DIALOGFACTORY_H

class QWidget;
class QDialog;
class QString;

class DialogFactory
{
public:
    DialogFactory();
    QDialog* createDialog(const QString& name, QWidget* parent);
};

#endif // DIALOGFACTORY_H
