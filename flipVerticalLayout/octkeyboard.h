#ifndef OCTKEYBOARD_H
#define OCTKEYBOARD_H

#include <QDialog>
#include <QString>
#include <vector>

using std::vector;
class QPushButton;

using ButtonContainer = std::vector<QPushButton*>;

namespace Ui {
class OctKeyboard;
}

class OctKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit OctKeyboard(const vector<QString>& param, QWidget *parent = nullptr);
    ~OctKeyboard();
    QString editResult();

private slots:
    void handleDelete();

private:
    void initButtonContainers();

private:
    Ui::OctKeyboard *ui;

    ButtonContainer m_leterButtons;
    ButtonContainer m_numberButtons;
};

#endif // KEYBOARD_H
