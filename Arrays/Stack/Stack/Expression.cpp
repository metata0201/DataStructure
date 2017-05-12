#include "Expression.h"
#include "MyStack.h"
#include <iostream>

// infix string convert to prefix string
void InfixToPrefix(std::string *pInfix, std::string *pPrefix)
{
    if (pInfix->size() == 0)
    {
        std::cout << "infix string can't be empty!" << std::endl;
        return;
    }

    MyStack<char> stack;    // store operator
    MyStack<char> prefixStack(pInfix->size());

    // scan infix string from right to left
    for (int i = pInfix->size()-1; i >= 0; i--)
    {
        switch (pInfix->at(i))
        {
        case ')':
            stack.Push(pInfix->at(i));
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while (!stack.IsEmpty() && (Precedence(stack.TopVal()) <  Precedence(pInfix->at(i)))) // in-stack precedence is higher than in coming precedence
            {
                prefixStack.Push(stack.Pop());
            }
            stack.Push(pInfix->at(i));
            break;
        case '(':
            while (stack.TopVal() != ')')
            {
                prefixStack.Push(stack.Pop());
            }
            stack.Pop();    // pop ')'
            break;
        default:    // operand
            prefixStack.Push(pInfix->at(i));
            break;
        }
    }

    // pop the remaining operators to prefix string
    while (!stack.IsEmpty())
    {
        prefixStack.Push(stack.Pop());
    }

    // pop the token in 'prefixStack'
    while (!prefixStack.IsEmpty())
    {
        pPrefix->push_back(prefixStack.Pop());
    }
}

// infix string convert to postfix string
void InfixToPostfix(std::string *pInfix, std::string *pPostfix)
{
    if (pInfix->size() == 0)
    {
        std::cout << "infix string can't be empty!" << std::endl;
        return;
    }

    MyStack<char> stack;    // store operator
    // scan infix string from left to right
    for (int i = 0; i < pInfix->size(); i++)
    {
        switch (pInfix->at(i))
        {
        case '(':
            stack.Push(pInfix->at(i));
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while (!stack.IsEmpty() && (Precedence(stack.TopVal()) <= Precedence(pInfix->at(i))))  // in-stack precedence is higher than or equal to the incoming precedence
            {
                pPostfix->push_back(stack.Pop());
            }
            stack.Push(pInfix->at(i));
            break;
        case ')':
            while (stack.TopVal() != '(')
            {
                pPostfix->push_back(stack.Pop());
            }
            stack.Pop();    // pop '('
            break;
        default:// operand
            pPostfix->push_back(pInfix->at(i));
            break;
        }
    }

    // pop the remaining operators to postfix string.
    while (!stack.IsEmpty())
    {
        pPostfix->push_back(stack.Pop());
    }
}

// precedence(or priority)
int Precedence(char c)
{
    int ret = -1;
    switch (c)
    {
    case '*':
    case '/':
    case '%':
        ret = 1;
        break;
    case '+':
    case '-':
        ret = 2;
        break;
    case '(':
    case ')':
        ret = 3;
        break;
    default:
        break;
    }

    return ret;
}

// prefix string evaluation
int PrefixEvaluation(std::string *pPrefix)
{
    if (pPrefix->size() == 0)
    {
        std::cout << "prefix string can't be empty!" << std::endl;
        return -1;
    }

    int result = -1, operand1, operand2;
    MyStack<int> stack(pPrefix->size());
    for (int i = pPrefix->size()-1; i >= 0; i--)
    {
        if (pPrefix->at(i) == '+' || pPrefix->at(i) == '-' || pPrefix->at(i) == '*' ||
            pPrefix->at(i) == '/' || pPrefix->at(i) == '%')
        {
            operand1 = stack.Pop();
            operand2 = stack.Pop();
            switch (pPrefix->at(i))
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            default:
                break;
            }
        }
        else
        {
            result = pPrefix->at(i) - '0';
        }
        stack.Push(result);
    }

    return stack.Pop();
}

// postfix string evaluation
int PostfixEvaluation(std::string *pPostfix)
{
    if (pPostfix->size() == 0)
    {
        std::cout << "postfix string can't be empty!" << std::endl;
        return -1;
    }

    int result = -1, operand1, operand2;
    MyStack<int> stack(pPostfix->size());
    for (int i = 0; i < pPostfix->size(); i++)
    {
        if (pPostfix->at(i) == '+' || pPostfix->at(i) == '-' || pPostfix->at(i) == '*' ||
            pPostfix->at(i) == '/' || pPostfix->at(i) == '%')
        {
            operand2 = stack.Pop();
            operand1 = stack.Pop();
            switch (pPostfix->at(i))
            {
            case '+':                
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            default:
                break;
            }
        }
        else
        {
            result = pPostfix->at(i) - '0';
        }
        stack.Push(result);
    }

    return stack.Pop();
}

// string evaluation
int StrEvaluation(std::string *str, EVALUATE_OPTION option)
{
    int result = -1;
    std::string dstStr;
    switch (option)
    {
    case PRE_FIX:
        InfixToPrefix(str, &dstStr);
        std::cout << "prefix: " << dstStr << std::endl;
        result = PrefixEvaluation(&dstStr);
        break;
    case POS_FIX:
        InfixToPostfix(str, &dstStr);
        std::cout << "postfix: " << dstStr << std::endl;
        result = PostfixEvaluation(&dstStr);
        break;
    default:
        break;
    }
    return result;
}