#include <string>

enum EVALUATE_OPTION
{
    PRE_FIX = 0,
    POS_FIX = 1,
};

// Assumptions:
// operators : +, -, *, / , %
// operands  : single digit integer

// infix string convert to prefix string
void InfixToPrefix(std::string *pInfix, std::string *pPrefix);

// infix string convert to postfic string
void InfixToPostfix(std::string *pInfix, std::string *pPostfix);

// precedence(priority)
int Precedence(char c);

// prefix string evaluation
int PrefixEvaluation(std::string *pPrefix);

// postfix string evaluation
int PostfixEvaluation(std::string *pPostfix);

// string evaluation
int StrEvaluation(std::string *str, EVALUATE_OPTION option);
