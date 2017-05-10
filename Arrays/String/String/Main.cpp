#include "String.h"
#include <iostream>

void main()
{
    std::string text("aabzabzabcz"), pattern("abzabc");
    //int index = KMP(&text, &pattern);
    int index = StringMatch(&text, &pattern);
    if (index >= 0)
    {
        std::cout << "the first pattern occur in the text is starting at index: " << index << std::endl;
    }
    else
    {
        std::cout << "there is no pattern occur int the text!" << std::endl;
    }
}