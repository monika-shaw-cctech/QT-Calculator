#include<stack>
#include<cmath>

#include"infixToPostfix.h"


long long infixToPostfixEvaluate(string str)
{
    string temp = infixToPostfix(str);
    return postfixEval(temp);
}

string infixToPostfix(string s)
{

    stack<char> st;
    string result;

    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(c ==' ')continue;


        else if (c >= '0' && c <= '9')
        {
            result += findNum(i,s);
            result += " ";
        }

        else if (c == '(')
            st.push('(');


        else if (c == ')')
        {
            while(st.top() != '(')
            {
                result += st.top();
                result += " ";
                st.pop();
            }
            st.pop();
        }


        else
        {
            while (!st.empty() && precofOperator(s[i]) <= precofOperator(st.top()))
            {
                result += st.top();
                result += " ";
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        result +=" ";
        st.pop();
    }

    return result ;
}


string findNum(int &i,string str)
{
   string value;
   value = str[i++];
   while (str[i] !=' ' && i < str.length())
   {
       value += str[i++];
   }
   return value;
}

long long postfixEval(string postfix)
{
   long long a, b;
   stack<long long> stk;
   int i;
   for(i = 0; i < postfix.length(); i++)
   {
      if(isOperator(postfix[i]) == 1)
      {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, postfix[i]));
      }else if(isOperand(postfix[i]) == 1)
      {
         stk.push(stoi(findNum(i,postfix)));
      }
   }
   return stk.top();
}


int precofOperator(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch=='*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}


int isOperator(char ch)
{
   if (ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;
   else return 0;
}


int isOperand(char ch)
{
      if(ch >= '0' && ch <= '9')
         return 1;
      else return 0;
}

long long operation(long long num1, long long num2, char op)
{
      if (op == '+')
         return num1+num2;
      else if (op == '-')
         return num1-num2;
      else if (op == '*')
         return num1*num2;
      else if (op == '/')
         return num1/num2;
      else if (op == '^')
         return (long long)pow(num2,num1);
      else
         return INT_MIN;
}





