#include <catch.hpp>
#include <QString>
#include <cmath>

int prec(char c) {

    if(c == '^' )
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
TEST_CASE( "precedence checking", "[prec]" ) {

    REQUIRE(prec('^') == 3 );
    REQUIRE(prec('/') == 2 );
    REQUIRE(prec('*') == 2 );
    REQUIRE(prec('+') == 1 );
    REQUIRE(prec('-') == 1 );
    REQUIRE(prec('k') == -1);
}

int isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^' )
      return 1;
   else return 0;
}

TEST_CASE( "operator checking", "[operator]" ) {

      REQUIRE(isOperator('+')  == 1 );
      REQUIRE(isOperator('-')  == 1 );
      REQUIRE(isOperator('*')  == 1 );
      REQUIRE(isOperator('/')  == 1 );
      REQUIRE(isOperator('^')  == 1 );
      REQUIRE(isOperator('&')  == 0 );
}

int isOperand(char ch){
      if(ch >= '0' && ch <= '9')
         return 1;
      else
          return 0;
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

long long operation(long long b, char op, long long a)
{

          if(op == '+')
         return(b+a);
      else if(op == '-')
         return b-a;
      else if(op == '*')
         return b*a;
      else if(op == '/')
         return b/a;
      else if(op == '^')
         return (long long)pow(b,a);
          else
         return INT_MIN;

}
TEST_CASE( "checking of all operations", "[Add,subtract,multiply,divide,exponent]" ) {

    REQUIRE( operation(6,'+',3) == 9 );
    REQUIRE( operation(6,'-',3) == 3 );
    REQUIRE( operation(6,'*',3) == 18 );
    REQUIRE( operation(6,'/',3) == 2 );
    REQUIRE( operation(6,'^',3) == 216 );

}

