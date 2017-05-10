#include "String.h"
#include <string>

// simple string matching
// m = text->size(), n = pattern->size()
// time complexity:O(m*n)
int StringMatch(std::string *text, std::string *pattern)
{
    int i, j;
    bool match = true;
    for (i = 0; i < text->size(); i++)
    {
        //  pattern size can not exceed text size
        if (i + pattern->size() > text->size())
        {
            return -1;
        }

        match = true;
        // match each character in pattern and text successively
        for (j = 0; j < pattern->size(); j++)
        {
            if (pattern->at(j) != text->at(i+j))
            {
                match = false;
                break;
            }
        }

        // find matching pattern in text
        if (match)
        {
            return i;
        }
    }

    return -1;
}

// Knuth - Morris - Pratt(KMP) Algorithm
// m = text->size(), n = pattern->size()
// time complexity:O(m+n)
int KMP(std::string *text, std::string *pattern)
{
    int i, j, retIndex = -1;
    int *failure = new int[pattern->size()];
    memset(failure, 0, sizeof(int)*pattern->size());

    // 1.failure function(or prefix function)
    for (i = 1, j = 0; i < pattern->size(); i++)
    {
        while (j>0 && pattern->at(j) != pattern->at(i))
        {
            j = failure[j-1];
        }

        if (pattern->at(j) == pattern->at(i))
        {
            j++;
        }
        failure[i] = j;
    }

    // 2.string matching
    for (i = 0, j = 0; i < text->size(); i++)
    {
        while (j>0 && pattern->at(j) != text->at(i))
        {
            j = failure[j-1];
        }

        if (pattern->at(j) == text->at(i))
        {
            j++;
        }
        if (j == pattern->size())
        {
            retIndex = i - pattern->size() + 1;
            break;
        }
    }

    if (failure)
    {
        delete[]failure;
        failure = NULL;
    }
    return retIndex;
}