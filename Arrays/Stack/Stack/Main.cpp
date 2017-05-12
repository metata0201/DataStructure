#include "Expression.h"
#include "MyStack.h"
#include <iostream>

using namespace std;

void main()
{
    string str("1+((2+3)*4)-5");
    cout << "infix: " << str << endl;

    int result = StrEvaluation(&str, PRE_FIX);
    cout << str << " = " << result << endl;

    result = StrEvaluation(&str, POS_FIX);
    cout << str << " = " << result << endl;
}
