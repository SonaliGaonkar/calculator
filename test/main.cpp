#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <QtGui/QGuiApplication>
#define UNIT_TEST_ENABLED
int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    return Catch::Session().run(argc, argv);
}
