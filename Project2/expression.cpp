/*
 * expression.cpp
 *
 * Created on: July 6, 2025
 * Author: [Your Name]
 * Description: Implements the evaluate() methods for the Expression AST nodes.
 */

#include "expression.h"
#include "symboltable.h"
#include <cmath>       // For fmod, pow
#include <stdexcept>   // For runtime_error
#include <algorithm>   // For min, max

double Literal::evaluate(const SymbolTable& symbols) const {
    return value;
}

double Variable::evaluate(const SymbolTable& symbols) const {
    // The lookUp function will throw an error if the variable is not found
    return symbols.lookUp(name);
}

double UnaryExpression::evaluate(const SymbolTable& symbols) const {
    // Postfix negation operator '~'
    return -expr->evaluate(symbols);
}

double BinaryExpression::evaluate(const SymbolTable& symbols) const {
    double leftVal = left->evaluate(symbols);
    double rightVal = right->evaluate(symbols);

    switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        case '%': return fmod(leftVal, rightVal);
        case '^': return pow(leftVal, rightVal);
        case '<': return min(leftVal, rightVal);
        case '>': return max(leftVal, rightVal);
        case '&': return (leftVal + rightVal) / 2.0;
        default: throw runtime_error("Invalid binary operator.");
    }
}

double TernaryExpression::evaluate(const SymbolTable& symbols) const {
    // condition ? if_true : if_false
    double condition = first->evaluate(symbols);
    if (condition != 0) {
        return second->evaluate(symbols);
    } else {
        return third->evaluate(symbols);
    }
}

double QuaternaryExpression::evaluate(const SymbolTable& symbols) const {
    // condition # less_zero : equal_zero : greater_zero
    double condition = first->evaluate(symbols);
    if (condition < 0) {
        return second->evaluate(symbols);
    } else if (condition == 0) {
        return third->evaluate(symbols);
    } else {
        return fourth->evaluate(symbols);
    }
}