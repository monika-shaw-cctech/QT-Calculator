#include"infixToPostfix.h"
#include<stack>
#include<cmath>

//function to return specific substring start from specific position unil reaching next " "
string scanNum(int &i,string str){
   string value;
   value = str[i++];
   while(str[i]!=' ' && i<str.length()){
       value+=str[i++];
   }
   return value;
}


//Function to return precedence of operators
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

// function to convert infix expression to postfix expression
string infixToPostfix(string s) {

    stack<char> st; //For stack operations
    string result;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c==' ')continue;

        // If the character is an operand, add it to output string.
        else if(c >= '0' && c <= '9'){
            result +=scanNum(i,s);
            result +=" ";
        }
        // If the scanned character is ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');

        // If the scanned character is an ‘)’, Pop and to output string from the stack until reaching ‘(‘
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                result +=" ";
                st.pop();
            }
            st.pop();
        }

        //If an operator is scanned
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                result +=" ";
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        result += st.top();
        result +=" ";
        st.pop();
    }

    return result ;
}


//function to detect if the char is operator or not
int isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;
   else return 0;
}

//function to detect if the char is operand or not
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

//function to return value from postifix expression
long long postfixEval(string postfix){
   long long a, b;
   stack<long long> stk;
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

//final function that get infix expression and evaluate it by convert it to Postfix
long long evaluate(string str){
    string temp=infixToPostfix(str);
    return postfixEval(temp);
}
