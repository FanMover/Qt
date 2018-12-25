#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.load("/home/top/Desktop/2.jpg");
    w.save("/home/top/Desktop/4.jpg");
    w.show();

    return a.exec();
}
