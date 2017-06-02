#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <math.h>
#include <QDebug>

static const int MouseCount = 1;

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
}
