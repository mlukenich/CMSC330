#pragma once
#include "expression.h"

/**
 * File: unaryexpression.h
 * Name: Matt Lukenich
 * CMSC330 Project 2
 * Header file for a unary expression
 */
class UnaryExpression : public Expression {
public:
    explicit UnaryExpression(Expression* expr) : expr(expr) {}
    ~UnaryExpression() override { delete expr; }
protected:
    Expression* expr;
};

class Negate : public UnaryExpression {
public:
    explicit Negate(Expression* expr) : UnaryExpression(expr) {}
    double evaluate() override { return -expr->evaluate(); }
};