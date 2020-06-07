#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class myLineEdit : public QLineEdit
{
public:
    myLineEdit(QWidget* parent = nullptr);
    void mousePressEvent(QMouseEvent * e) override;
};

#endif // MYLINEEDIT_H
