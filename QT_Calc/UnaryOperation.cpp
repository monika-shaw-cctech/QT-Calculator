#include <iostream>
#include <math.h>

#include "unaryOperation.h"

using namespace std;

double all_unary_operation(string exp,string op)
{
    double value;

    if(op == "≈")
    {
        value = stod(exp);
        return round(value);
    }

    else if(op == "%")
    {
        value = stod(exp);
        return value * (0.01);
    }

    else if(op == "𝔁²")
    {
        value = stod(exp);
        return value * value;
    }

    else if(op == "²√")
    {
        value= stod(exp);
        return sqrt(value);
    }
    else if(op == "1/𝔁")
    {
        value = stod(exp);
        return 1/value;
    }
    else if(op == "c")
    {

        return 0;
    }
    else
    {
        value = stod(exp);
        return  value * (0.5);
    }
}
