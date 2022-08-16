#include"support.h"
#include<stack>
#include<cmath>

std::string scanNum(int &i,std::string str){
   std::string value;
   value = str[i++];
   while(str[i]!=' ' && i<str.length()){
       value+=str[i++];
   }
   return value;
}

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string infixToPostfix(std::string s) {
    std::stack<char> st;
        std::string result;

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c==' ')continue;

            else if(c >= '0' && c <= '9'){
                result +=scanNum(i,s);
                result +=" ";
            }

            else if(c == '(')
                st.push('(');

             else if(c == ')') {
                while(st.top() != '(')
                {
                    result += st.top();
                    result +=" ";
                    st.pop();
                }
                st.pop();
            }

            else {
                while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                    result += st.top();
                    result +=" ";
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()) {
                result += st.top();
                result +=" ";
                st.pop();
            }

            return result ;
        }

        int isOperator(char ch){
           if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
              return 1;
           else return 0;
        }

        int isOperand(char ch){
              if(ch >= '0' && ch <= '9')
                 return 1;
              else return 0;
        }
        long long operation(long long a, long long b, char op){
              if(op == '+')
                 return b+a;
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

        long long postfixEval(std::string postfix){
           long long a, b;
           std::stack<long long> stk;
           int i;
           for(i=0; i<postfix.length(); i++){
              if(isOperator(postfix[i]) == 1){
                 a = stk.top();
                 stk.pop();
                 b = stk.top();
                 stk.pop();
                 stk.push(operation(a, b, postfix[i]));
              }else if(isOperand(postfix[i]) == 1){
                 stk.push(stoi(scanNum(i,postfix)));
              }
           }
           return stk.top();
        }

        long long evaluate(std::string str){
            std::string temp=infixToPostfix(str);
            return postfixEval(temp);
        }
