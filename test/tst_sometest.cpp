#include <catch.hpp>
#include <QString>
TEST_CASE("MCatch2", "[fancy]")
{
   SECTION("Something", "")
   {
       CHECK(QString() == QString());
       const QString someString(QLatin1String("foo"));
       CHECK(someString == QLatin1String("bar"));
   }
}
