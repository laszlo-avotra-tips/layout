#ifndef FORMSTART_H
#define FORMSTART_H

#include <QWidget>

namespace Ui {
class FormStart;
}

class FormStart : public QWidget
{
    Q_OBJECT

public:
    explicit FormStart(QWidget *parent = nullptr);
    ~FormStart();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormStart *ui;
};

#endif // FORMSTART_H
