#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QWidget;
class SelectDialog;

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
    void openKeyboard();
    void on_pushButtonDown_clicked();

private:
    void setDefaultSelection();
    bool isFieldEmpty() const;

private:
    Ui::Dialog *ui;
    QWidget* m_parent{nullptr};
    SelectDialog* m_selectDialog{nullptr};
};

#endif // DIALOG_H
