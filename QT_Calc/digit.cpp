#include "QDebug"
#include "digit.h"

#include <iostream>
using namespace std;


string labelText(string lText, string bText)

{


    if(lText == "0")
    {
       return bText;

    }
    else
    {
        string s3 = lText.append(bText);
        return s3;

    }
}
