#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ТЕСТ-ПОСЫЛКА НА ТРЕНАЖЕР.");
    w.show();   
    return a.exec();
}
