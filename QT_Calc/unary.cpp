#include "unary.h"

#include <iostream>
#include <math.h>

using namespace std;


string dotOperation(string lText, string bText)
{
    if(bText == ".")
    {
       string s = lText+".";
       return s;
    }

}

double allUnaryOperation(double lText, string bText)
{
    if(bText == "+/-")
    {
        double d = lText * (-1);
        return d;
    }
    else if(bText == "%")
    {
        double d = lText * (0.01) ;
        return d;
    }

    else if(bText == "1/𝔁")
    {
        double d = 1/lText ;
        return d;
    }
    else if(bText == "𝔁²")
    {
        double d = lText * lText;
        return d;
    }
    else if(bText == "²√")
    {
        double d = sqrt(lText);
        return d;
    }
    else if(bText == "𝔁/2")
    {
        double d = lText * (0.5);
        return d;
    }
}
