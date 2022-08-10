#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <string>

using namespace std;

string findNum(int &i,string str);
int precofOperator(char ch) ;
string infixToPostfix(string s) ;
int isOperator(char ch);
int isOperand(char ch);
long long operation(long long num1, long long num2, char op);
long long postfixEval(string postfix);
long long infixToPostfixEvaluate(string str);


#endif // INFIXTOPOSTFIX_H
