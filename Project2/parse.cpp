#include "expression.h"
#include "operand.h"
#include "binaryexpression.h"
#include "unaryexpression.h"
#include "ternaryexpression.h"
#include "quaternaryexpression.h"
#include "customerrors.h"
#include <sstream>
#include <regex>
#include <cctype>
#include <vector>

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Final corrected parsing logic. Fixes segfault by implementing a robust parseAssignments function.
 */

// Forward declaration for the main recursive parser
Expression* parseExpression(std::stringstream& in);

// This function parses a base unit: a literal, a variable,
// or a fully-enclosed parenthesized sub-expression.
Expression* parseOperand(std::stringstream& in) {
    static const std::regex var_regex("[a-zA-Z][a-zA-Z0-9_]*");
    static const std::regex literal_regex("[0-9]+(\\.[0-9]+)?");
    
    in >> std::ws;
    char c = in.peek();

    if (isdigit(c) || c == '.') {
        std::string temp;
        in >> temp;
        if (std::regex_match(temp, literal_regex)) {
            return new Literal(stod(temp));
        }
    } else if (isalpha(c)) {
        std::string temp;
        in >> temp;
        if (std::regex_match(temp, var_regex)) {
            return new Variable(temp);
        }
    } else if (c == '(') {
        in.get(); // Consume '('
        Expression* expr = parseExpression(in);
        in >> std::ws;
        if (in.peek() == ')') {
            in.get(); // Consume ')'
        }
        return expr;
    }
    return nullptr;
}


// This is the main parser for the content INSIDE parentheses.
// It handles all expression types: unary, binary, ternary, and quaternary.
Expression* parseExpression(std::stringstream& in) {
    Expression* left = parseOperand(in);

    in >> std::ws;
    char op = in.peek();

    if (in.eof() || op == ')' || op == ',') {
        return left;
    }

    in.get(); // Consume the operator

    if (op == '~') { // Postfix Unary operator
        return new Negate(left);
    }

    if (op == '?') { // Ternary operator
        Expression* true_expr = parseOperand(in);
        Expression* false_expr = parseOperand(in);
        return new Conditional(left, true_expr, false_expr);
    }
    
    if (op == '#') { // Quaternary operator
        Expression* less_expr = parseOperand(in);
        Expression* equal_expr = parseOperand(in);
        Expression* greater_expr = parseOperand(in);
        return new ComplexConditional(left, less_expr, equal_expr, greater_expr);
    }

    // Binary operators
    Expression* right = parseOperand(in);
    switch (op) {
        case '+': return new Add(left, right);
        case '-': return new Sub(left, right);
        case '*': return new Mul(left, right);
        case '/': return new Div(left, right);
        case '%': return new Rem(left, right);
        case '^': return new Power(left, right);
        case '<': return new Min(left, right);
        case '>': return new Max(left, right);
        case '&': return new Avg(left, right);
    }
    return nullptr;
}

// **Robust implementation of parseAssignments**
// This version uses standard token extraction and avoids manual stream manipulation.
void parseAssignments(std::stringstream& in) {
    static const std::regex var_regex("[a-zA-Z][a-zA-Z0-9_]*");
    std::vector<std::string> defined_vars;
    char eq_op, comma;

    do {
        std::string variableName;
        in >> variableName; // Safely reads the next token, e.g., "x" from "x = 1"

        if (!std::regex_match(variableName, var_regex)) {
            // If the token isn't a valid variable, skip this iteration.
            // This might happen if the line ends unexpectedly.
            continue;
        }

        // Check for duplicate variable initialization in the same statement
        for(const auto& defined : defined_vars) {
            if (defined == variableName) {
                throw DuplicateVariable(variableName);
            }
        }
        defined_vars.push_back(variableName);

        double value;
        in >> eq_op >> value; // Safely reads the '=' and the numeric value
        if (eq_op == '=') {
            symbolTable.insert(variableName, value);
        }

        in >> std::ws;
        comma = in.peek(); // Peek ahead to see if a comma follows
    
    // The loop continues only if the next character is a comma.
    // The "in.get(comma)" part consumes the comma and advances the stream.
    } while (comma == ',' && in.get(comma));
}