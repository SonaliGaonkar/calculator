#include <catch.hpp>
#include <QString>
#include <cmath>
#include <support.h>

TEST_CASE( "precedence checking", "[prec]" ) {

    REQUIRE(prec('^') == 3 );
    REQUIRE(prec('/') == 2 );
    REQUIRE(prec('*') == 2 );
    REQUIRE(prec('+') == 1 );
    REQUIRE(prec('-') == 1 );
    REQUIRE(prec('k') == -1);
}

TEST_CASE( "operator checking", "[operator]" ) {

      REQUIRE(isOperator('+')  == 1 );
      REQUIRE(isOperator('-')  == 1 );
      REQUIRE(isOperator('*')  == 1 );
      REQUIRE(isOperator('/')  == 1 );
      REQUIRE(isOperator('^')  == 1 );
      REQUIRE(isOperator('&')  == 0 );
}

TEST_CASE( "operand checking", "[operand]" ) {

    REQUIRE(isOperand('0')  == 1 );
    REQUIRE(isOperand('1')  == 1 );
    REQUIRE(isOperand('2')  == 1 );
    REQUIRE(isOperand('3')  == 1 );
    REQUIRE(isOperand('4')  == 1 );
    REQUIRE(isOperand('5')  == 1 );
    REQUIRE(isOperand('6')  == 1 );
    REQUIRE(isOperand('7')  == 1 );
    REQUIRE(isOperand('8')  == 1 );
    REQUIRE(isOperand('9')  == 1 );

}

TEST_CASE( "checking of all operations", "[Add,subtract,multiply,divide,exponent]" ) {

    REQUIRE( operation(3,6,'+') == 9 );
    REQUIRE( operation(3,6,'-') == 3 );
    REQUIRE( operation(3,6,'*') == 18 );
    REQUIRE( operation(3,6,'/') == 2 );
    REQUIRE( operation(3,6,'^') == 216 );
}
