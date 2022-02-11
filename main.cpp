#include "calculators.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculators w;
    w.show();
    return a.exec();
}
