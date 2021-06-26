#include "widget.h"
#include "system.h"
#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    loadData();
    QApplication a(argc, argv);
    Controller w;
    int state = a.exec();
    writeData();
    return state;
}
