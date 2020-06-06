#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <QString>
#include <vector>

using std::vector;

namespace Ui {
class keyboard;
}

class keyboard : public QDialog
{
    Q_OBJECT

public:
    explicit keyboard(const vector<QString>& param, QWidget *parent = nullptr);
    ~keyboard();
    QString editResult();

private slots:
    void handleDelete();

private:
    Ui::keyboard *ui;
};

#endif // KEYBOARD_H
