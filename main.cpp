#include <iostream>
#include "expression_manager.h"
#include "queue.h"

int main() {
    ExpressionManager em;
    Queue<std::string> expressionQueue; // Using Queue to store expressions

    while (true) {
        std::cout << "Enter an infix expression (or type 'exit' to quit): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "exit") {
            break; // Exit the loop, thus ending the program
        }

        // Enqueue the expression for processing
        expressionQueue.enqueue(input);

        while (!expressionQueue.isEmpty()) {
            // Dequeue the next expression
            std::string infixExpression = expressionQueue.dequeue();

           
            try {
                if (em.checkBalancedParentheses(infixExpression)) {
                    std::string postfixExpression = em.infixToPostfix(infixExpression);
                    std::cout << "Postfix Expression: " << postfixExpression << std::endl;
                }
                else {
                    std::cout << "Invalid expression: Unbalanced parentheses." << std::endl;
                }
            }
            catch (const std::exception& e) {
                std::cout << "An error occurred: " << e.what() << std::endl;
            }
        }
    }

    return 0;
}
