#include "binary.h"
#include <iostream>
#include <math.h>

using namespace std;

string binaryOperation(string lText, string bText)
{
    if(bText == "+" || bText == "-" || bText == "x" ||bText == "/"|| bText == "^" )
    {
      string s = lText+' '+bText;
      return s;
    }
}
