#define CATCH_CONFIG_MAIN
#include <catch.hpp>
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
     return Catch::Session().run(argc,argv);
}
