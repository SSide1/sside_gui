#include "mainwindow.h"
#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette pal = a.palette();
    pal.setColor(QPalette::Window, Qt::white);
    pal.setColor(QPalette::Text, Qt::black);
    a.setPalette(pal);
    w.resize(800,600);
    w.show();

    return a.exec();
}
