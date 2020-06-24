#include "widget.h"
#include<iostream>
#include <QApplication>

using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
//    DoubleList();
    Widget w;
    w.show();
    return a.exec();
}
