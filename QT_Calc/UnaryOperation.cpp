#include <iostream>

#include "unaryOperation.h"
using namespace std;
double all_unary_operation(string exp)
{
     double d = stod(exp);
     double result = d * (0.5);
     return result;
}
