#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <vector>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonFlipL_clicked();

    void on_pushButtonFlipR_clicked();

    void on_pushButtonShowButtonsL_clicked();

    void on_pushButtonShowButtonsR_clicked();

private:
    Ui::MainWindow *ui;
    const std::pair<int,int> m_widthHeight{3,2};
    const int m_sceneSize{800};

};
#endif // MAINWINDOW_H
