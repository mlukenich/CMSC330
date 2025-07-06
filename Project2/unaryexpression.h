#pragma once
#include "expression.h"

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