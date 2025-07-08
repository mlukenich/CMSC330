#pragma once
#include "expression.h"
#include <cmath>
#include <algorithm>

/*
 * File: binaryexpression.h
 * Name: Matt Lukenich
 * CMSC 330 Project 2
 * Defines several custom binary expressions.
 */
class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* left, Expression* right) : left(left), right(right) {}
    ~BinaryExpression() override {
        delete left;
        delete right;
    }
protected:
    Expression *left, *right;
};

/*
 * Add function
 */
class Add : public BinaryExpression {
public:
    Add(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() + right->evaluate(); }
};

/*
 * Subtract function
 */
class Sub : public BinaryExpression {
public:
    Sub(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() - right->evaluate(); }
};

/*
 * Mul function 
 */
class Mul : public BinaryExpression {
public:
    Mul(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() * right->evaluate(); }
};

/*
 * Division function
 */
class Div : public BinaryExpression {
public:
    Div(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() / right->evaluate(); }
};

/*
 * Provides fmod function
 */
class Rem : public BinaryExpression {
public:
    Rem(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return fmod(left->evaluate(), right->evaluate()); }
};

/*
 * Power function
*/
class Power : public BinaryExpression {
public:
    Power(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return pow(left->evaluate(), right->evaluate()); }
};

class Min : public BinaryExpression {
public:
    Min(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return std::min(left->evaluate(), right->evaluate()); }
};

class Max : public BinaryExpression {
public:
    Max(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return std::max(left->evaluate(), right->evaluate()); }
};

class Avg : public BinaryExpression {
public:
    Avg(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return (left->evaluate() + right->evaluate()) / 2.0; }
};