#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class myLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    myLineEdit(QWidget* parent = nullptr);
    void mousePressEvent(QMouseEvent * e) override;

signals:
    void mousePressed();

};

#endif // MYLINEEDIT_H
