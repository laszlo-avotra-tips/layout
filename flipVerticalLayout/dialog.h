#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QWidget;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButtonName_clicked();

private:
    Ui::Dialog *ui;
    QWidget* m_parent{nullptr};
};

#endif // DIALOG_H
