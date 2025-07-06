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

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Complete parser rewrite to support the new grammar and tokens.
 */

// Forward declaration
Expression* parseExpression(std::stringstream& in);

Expression* Operand::parse(std::stringstream& in) {
    // Regex for variable: starts with a letter, followed by letters, numbers, or underscores.
    static const std::regex var_regex("[a-zA-Z][a-zA-Z0-9_]*");
    // Regex for literal: matches integers and floating-point numbers.
    static const std::regex literal_regex("[0-9]+(\\.[0-9]+)?");

    char c;
    in >> c;

    if (isdigit(c) || c == '.') {
        in.putback(c);
        std::string temp;
        in >> temp;
        if (std::regex_match(temp, literal_regex)) {
            return new Literal(stod(temp));
        }
    } else if (isalpha(c)) {
        in.putback(c);
        std::string temp;
        in >> temp;
        if (std::regex_match(temp, var_regex)) {
            return new Variable(temp);
        }
    } else if (c == '(') {
        Expression* expr = parseExpression(in);
        in >> c; // consume ')'
        return expr;
    }
    return nullptr; // Should not happen with syntactically correct input
}

Expression* parseExpression(std::stringstream& in) {
    Expression* left = Operand::parse(in);

    char op;
    in >> op;

    if (op == '~') { // Postfix Unary operator
        return new Negate(left);
    }

    if (op == '?') { // Ternary operator
        Expression* true_expr = parseExpression(in);
        Expression* false_expr = parseExpression(in);
        return new Conditional(left, true_expr, false_expr);
    }
    
    if (op == '#') { // Quaternary operator
        Expression* less_expr = parseExpression(in);
        Expression* equal_expr = parseExpression(in);
        Expression* greater_expr = parseExpression(in);
        return new ComplexConditional(left, less_expr, equal_expr, greater_expr);
    }

    // Binary operators
    Expression* right = parseExpression(in);
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
    return nullptr; // Should not happen
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
        // Extract variable name correctly
        for(char ch : var) {
            if (ch != '=') {
                temp_var += ch;
            } else {
                break;
            }
        }
        
        // Put back '=' if it was extracted
        in.seekg(- (var.length() - temp_var.length()), std::ios_base::cur);


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
        in >> p;
    } while (p == ',');
}