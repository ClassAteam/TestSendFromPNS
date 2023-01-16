#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Dispether/displ410.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int TICK_timer{20};//ms
    int countForPrint{0};
    DispL410* disp;
//    int coint_2 {0};
//    int coint_5 {0};
//    int coint_10{0};
//    int coint_50{0};

private:
    void   Print_manager();
    //-------------------------------
    Ui::MainWindow *ui;
    QTimer *timer;

private slots:
    void slotTimerAlarm();
};
#endif // MAINWINDOW_H
