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
 * Description: Corrected parsing logic to fix segmentation fault.
 */

// Forward declaration for the main recursive parser
Expression* parseExpression(std::stringstream& in);

// This function now ONLY parses a base unit: a literal, a variable,
// or a fully-enclosed parenthesized sub-expression.
Expression* parseOperand(std::stringstream& in) {
    // Regex for variable: starts with a letter, followed by letters, numbers, or underscores.
    static const std::regex var_regex("[a-zA-Z][a-zA-Z0-9_]*");
    // Regex for literal: matches integers and floating-point numbers.
    static const std::regex literal_regex("[0-9]+(\\.[0-9]+)?");
    
    // Peek at the next non-whitespace character
    in >> std::ws;
    char c = in.peek();

    if (isdigit(c) || c == '.') {
        std::string temp;
        in >> temp;
        // Simple check to avoid misinterpreting parts of floats as separate tokens
        if (temp.find('(') != std::string::npos || temp.find(')') != std::string::npos) {
             in.seekg(-(long)temp.length(), std::ios_base::cur);
        } else if (std::regex_match(temp, literal_regex)) {
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
    return nullptr; // Should not happen with syntactically correct input
}


// This is the main parser for the content INSIDE parentheses.
// It handles all expression types: unary, binary, ternary, and quaternary.
Expression* parseExpression(std::stringstream& in) {
    Expression* left = parseOperand(in);

    in >> std::ws;
    char op = in.peek();

    // If there's no operator, it's just a single expression
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
    Expression* right = parseOperand(in); // <--- THE FIX IS HERE
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
    return nullptr; // Should not be reached
}


void parseAssignments(std::stringstream& in) {
    // Regex for variable: starts with a letter, followed by letters, numbers, or underscores.
    static const std::regex var_regex("[a-zA-Z][a-zA-Z0-9_]*");
    
    char p, eq;
    std::string var;
    double val;
    std::vector<std::string> defined_vars;

    do {
        in >> var;
        std::string temp_var;

        size_t eq_pos = var.find('=');
        if (eq_pos != std::string::npos) {
            temp_var = var.substr(0, eq_pos);
            in.seekg(-(long)(var.length() - eq_pos), std::ios_base::cur);
        } else {
            temp_var = var;
        }

        if (!std::regex_match(temp_var, var_regex)) continue;

        // Check for duplicate definition
        for(const auto& defined : defined_vars) {
            if (defined == temp_var) {
                throw DuplicateVariable(temp_var);
            }
        }
        defined_vars.push_back(temp_var);
        
        in >> eq >> val;
        symbolTable.insert(temp_var, val);

        in >> std::ws;
        p = in.peek();
        if (p == ',') {
            in.get(); // consume comma
        }

    } while (p == ',');
}