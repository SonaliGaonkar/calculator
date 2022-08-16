#ifndef SUPPORT_H
#define SUPPORT_H
#include <string>

std::string scanNum(int &i,std::string str);

int prec(char c) ;

std::string infixToPostfix(std::string s) ;

int isOperator(char ch);

int isOperand(char ch);

long long operation(long long a, long long b, char op);

long long postfixEval(std::string postfix);

long long evaluate(std::string str);

#endif
