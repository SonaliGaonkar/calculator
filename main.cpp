#define CATCH_CONFIG_RUNNER
#include <QApplication>
#include <catch.hpp>
#include <calculators.h>

#define UNIT_TEST_ENABLED
int main(int argc, char *argv[])
{
 QApplication a (argc, argv);
     class calculators w;
     w.show();
     Catch::Session().run(argc,argv);
     return a.exec();
}
