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

TEST_CASE( "infix to postfix", "[string]" ) {

    REQUIRE(infixToPostfix("9 + 5 - 3") == "9 5 + 3 - ");
    REQUIRE(infixToPostfix("18 + 96 - 33 + 85") == "18 96 + 33 - 85 + ");
    REQUIRE(infixToPostfix("300 - 40 / 10 * 61") == "300 40 10 / 61 * - ");
    REQUIRE(infixToPostfix("100 / 100 - 10 + 40 * 89") == "100 100 / 10 - 40 89 * + ");
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
    REQUIRE(isOperand('50')  == 1 );
    REQUIRE(isOperand('600')  == 1 );
    REQUIRE(isOperand('457')  == 1 );
    REQUIRE(isOperand('8563')  == 1 );
    REQUIRE(isOperand('921304')  == 1 );
}

TEST_CASE( "checking of all operations", "[Add,subtract,multiply,divide,exponent]" ) {

    REQUIRE( operation(3,6,'+') == 9 );
    REQUIRE( operation(3,6,'-') == 3 );
    REQUIRE( operation(3,6,'*') == 18 );
    REQUIRE( operation(3,6,'/') == 2 );
    REQUIRE( operation(3,6,'^') == 216 );
}

TEST_CASE( "postfixEval", "[infix to postfix string]" ) {

    REQUIRE( postfixEval("9 5 + 3 - ") == 11 );
    REQUIRE( postfixEval("18 96 + 33 - 85 + ") == 166 );
    REQUIRE( postfixEval("300 40 10 / 61 * - ") == 56 );
    REQUIRE( postfixEval("100 100 / 10 - 40 89 * + ") == 3551 );
}

TEST_CASE( "evaluate", "[postfix evaluation]" ) {

    REQUIRE( evaluate("9 + 5 - 3") == 11 );
    REQUIRE( evaluate("18 + 96 - 33 + 85") == 166 );
    REQUIRE( evaluate("300 - 40 / 10 * 61") == 56 );
    REQUIRE( evaluate("100 / 100 - 10 + 40 * 89") == 3551 );
}
