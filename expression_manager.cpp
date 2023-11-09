#include "expression_manager.h"
#include <stack>
#include <cctype>
#include <stdexcept>

int ExpressionManager::getPrecedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return -1;
    }
}

bool ExpressionManager::isOperator(char c) {
    return std::string("+-*/%").find(c) != std::string::npos;
}

bool ExpressionManager::checkBalancedParentheses(const std::string& expression) {
    std::stack<char> stack;
    for (char c : expression) {
        switch (c) {
        case '{':
        case '(':
        case '[':
            stack.push(c);
            break;
        case '}':
            if (stack.empty() || stack.top() != '{') return false;
            stack.pop();
            break;
        case ')':
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
            break;
        case ']':
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
            break;
        default:
            // ignore non-parenthesis characters
            break;
        }
    }
    return stack.empty();
}

std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    if (!checkBalancedParentheses(infix)) {
        throw std::runtime_error("Invalid expression: unbalanced parentheses");
    }

    std::stack<char> opStack;
    std::string postfix;
    for (char c : infix) {
        if (std::isspace(c)) continue; // Skip whitespace
        else if (std::isdigit(c) || std::isalpha(c)) {
            postfix += c; 
        }
        else if (c == '(' || c == '{' || c == '[') {
            opStack.push(c); // Push opening parentheses onto stack
        }
        else if (c == ')' || c == '}' || c == ']') {
            // Pop from stack to output until the matching '(', '{', or '[' is removed
            char match = (c == ')') ? '(' : (c == '}') ? '{' : '[';
            while (!opStack.empty() && opStack.top() != match) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove the matching '('
        }
        else if (isOperator(c)) {
            while (!opStack.empty() && getPrecedence(c) <= getPrecedence(opStack.top())) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c); // Push current operator onto stack
        }
    }

    // Pop remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}
