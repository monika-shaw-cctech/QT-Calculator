#include <iostream>
#include <math.h>

#include "digit.h"

using namespace std;

string all_num(string labelText,string btn)
{
    size_t length = labelText.length();
    if(labelText == "0")
    {
        return btn;
    }

    else if(labelText[length-1]=='+'||labelText[length-1]=='*'||labelText[length-1]=='-'||labelText[length-1]=='/' ||labelText[length-1]=='^'|| labelText[length-1]=='(')
    {
        return labelText+' '+btn;
    }

    else
    {
        return labelText+btn;
    }
}
