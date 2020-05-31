#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <vector>
#include <map>
#include <QEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QTimer>

class QDialog;

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
    void on_pushButtonFlip_clicked();

    void on_pushButtonMenu_clicked();

    void on_pushButtonPage1_clicked();

    void on_pushButtonPage2_clicked();

    void on_pushButtonExitL_clicked();

    int getSceneSize();
    void popDialog();

private:
    void showEvent(QShowEvent* se) override;
    void hideEvent(QHideEvent* he) override;
    void flipColumns();

private:
    Ui::MainWindow *ui;
    const std::pair<int,int> m_widthHeight{3,2};
    const int m_sceneSize{2160};
    QDialog* m_dialog{nullptr};

};
#endif // MAINWINDOW_H
