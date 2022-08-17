#ifndef SUPPORT_H
#define SUPPORT_H
#include <string>

std::string scanNum(int &i,std::string str);

int prec(char c) ;

std::string infixToPostfix(std::string s) ;

double isOperator(char ch);

double isOperand(char ch);

double operation(double a, double b, char op);

double postfixEval(std::string postfix);

double evaluate(std::string str);

#endif
