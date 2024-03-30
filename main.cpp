#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(370, 100);
    w.setMaximumSize(370, 100);
    w.show();
    return a.exec();
}
