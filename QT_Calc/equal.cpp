#include "equal.h"
#include<QDebug>
#include <math.h>
#include <iostream>
using namespace std;

double equalOperation(double num1, double num2, bool plus, bool minus, bool multiply, bool divide)
{
   if(plus == true)
   {
       return num1+num2;
       plus = false;
   }
   else if(minus == true)
   {
       return num1-num2;
   }
   else if(multiply == true)
   {
       return num1*num2;
   }
   else if(divide == true)
   {
       return num1/num2;
   }
   else
   {
       return pow(num1,num2);
   }
}
