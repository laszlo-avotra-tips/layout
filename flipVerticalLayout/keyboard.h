#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>

namespace Ui {
class keyboard;
}

class keyboard : public QDialog
{
    Q_OBJECT

public:
    explicit keyboard(QWidget *parent = nullptr);
    ~keyboard();
    QString name();

private slots:
    void on_pushButtona_clicked();

private:
    Ui::keyboard *ui;
};

#endif // KEYBOARD_H