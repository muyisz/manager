#include "widget.h"

#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w;
    return a.exec();
}
