#define CATCH_CONFIG_MAIN
#include "calculators.h"
#include<QApplication>
#include<QFile>
#include<QStack>

#define UNIT_TEST_ENABLED

int main(int argc, char *argv[])
{
 QApplication a (argc, argv);

  class calculators w;
    w.show();
     return a.exec();



}
