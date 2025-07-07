/*
 * File: expression.h
 *
 * Name: Matt Lukenich
 * Defines the class hierarchy for the AST.
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include <vector>
#include "symboltable.h"

using namespace std;

// Abstract base class for all expression types
class Expression {
public:
    virtual ~Expression() {}
    virtual double evaluate(const SymbolTable& symbols) const = 0;
};

// Represents a literal numeric value
class Literal : public Expression {
public:
    Literal(double value) : value(value) {}
    double evaluate(const SymbolTable& symbols) const override;
private:
    double value;
};

// Represents a variable
class Variable : public Expression {
public:
    Variable(string name) : name(name) {}
    double evaluate(const SymbolTable& symbols) const override;
private:
    string name;
};

// Represents a unary expression
class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression* expr) : expr(expr) {}
    ~UnaryExpression() { delete expr; }
    double evaluate(const SymbolTable& symbols) const override;
private:
    Expression* expr;
};

// Represents a binary expression
class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* left, char op, Expression* right) : left(left), op(op), right(right) {}
    ~BinaryExpression() { delete left; delete right; }
    double evaluate(const SymbolTable& symbols) const override;
private:
    Expression* left;
    char op;
    Expression* right;
};

// Represents a ternary expression
class TernaryExpression : public Expression {
public:
    TernaryExpression(Expression* first, Expression* second, Expression* third)
        : first(first), second(second), third(third) {}
    ~TernaryExpression() { delete first; delete second; delete third; }
    double evaluate(const SymbolTable& symbols) const override;
private:
    Expression* first;
    Expression* second;
    Expression* third;
};

//Represents a quaternary expression
class QuaternaryExpression : public Expression {
public:
    QuaternaryExpression(Expression* first, Expression* second, Expression* third, Expression* fourth)
        : first(first), second(second), third(third), fourth(fourth) {}
    ~QuaternaryExpression() { delete first; delete second; delete third; delete fourth; }
    double evaluate(const SymbolTable& symbols) const override;
private:
    Expression* first;
    Expression* second;
    Expression* third;
    Expression* fourth;
};

#endif