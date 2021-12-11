#include "CGH_QtWidget_Calculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CGH_QtWidget_Calculator w;
    w.show();
    return a.exec();
}
