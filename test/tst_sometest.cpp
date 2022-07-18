#include <catch.hpp>
#include <QString>

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
}

TEST_CASE( "adding two numbers", "[addition]" ) {
    REQUIRE( 1+3 == 4 );
    REQUIRE( 6+2 == 8 );
    REQUIRE( 3+0 == 3 );
}

TEST_CASE("operations", "[arithmetic]") {
    int a =2, b=2;
    REQUIRE(a + b == 4);
}
