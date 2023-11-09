#pragma once
#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string>
#include <stack>

class ExpressionManager {
public:
    std::string infixToPostfix(const std::string& infix);
    bool checkBalancedParentheses(const std::string& expression);

private:
    int getPrecedence(char op);
    bool isOperator(char c);
};

#endif // EXPRESSION_MANAGER_H
