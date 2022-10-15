#include "headers/mainwindow.h"
#include "headers/welcome.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Main w;
//    w.show();
    welcome w;
    w.show();
    return a.exec();
}
