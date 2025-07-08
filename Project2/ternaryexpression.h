#pragma once
#include "expression.h"

/**
 * File: ternaryexpression.h
 * Name: Matt Lukenich
 * CMSC330 Project 2
 * Header file for a ternary expression
 */
class TernaryExpression : public Expression {
public:
    TernaryExpression(Expression* first, Expression* second, Expression* third)
        : first(first), second(second), third(third) {}
    ~TernaryExpression() override {
        delete first;
        delete second;
        delete third;
    }
protected:
    Expression *first, *second, *third;
};

class Conditional : public TernaryExpression {
public:
    Conditional(Expression* cond, Expression* true_expr, Expression* false_expr)
        : TernaryExpression(cond, true_expr, false_expr) {}
    double evaluate() override {
        return first->evaluate() != 0 ? second->evaluate() : third->evaluate();
    }
};