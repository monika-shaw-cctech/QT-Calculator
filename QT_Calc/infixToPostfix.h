#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <string>
using namespace std;

//function to return specific substring start from specific position unil reaching next " "
string scanNum(int &i,string str);

//Function to return precedence of operators
int prec(char c) ;

// function to convert infix expression to postfix expression
string infixToPostfix(string s) ;

//function to detect if the char is operator or not
int isOperator(char ch);

//function to detect if the char is operand or not
int isOperand(char ch);

long long operation(long long a, long long b, char op);

//function to return value from postifix expression
long long postfixEval(string postfix);

//final function that get infix expression and evaluate it by convert it to Postfix
long long evaluate(string str);


#endif // INFIXTOPOSTFIX_H
