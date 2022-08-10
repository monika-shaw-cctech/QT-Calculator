#include <iostream>
#include <math.h>
#include "unaryOperation.h"
using namespace std;
double all_unary_operation(string exp,string op)
{
    if(op == "≈")
    {
     double d = stod(exp);
     double result = round(d);
     return result;
    }

    else if(op == "%")
    {
     double d = stod(exp);
     double result = d * (0.01);
     return result;
    }

    else if(op == "𝔁²")
    {
     double d = stod(exp);
     double result = d * d;
     return result;
    }

    else if(op == "²√")
        {
         double d = stod(exp);
         double result = sqrt(d);
         return result;
        }
    else if(op == "1/𝔁")
        {
         double d = stod(exp);
         double result = 1/d ;
         return result;
        }
  else
        {
         double d = stod(exp);
         double result = d * (0.5);
         return result;
        }
}
