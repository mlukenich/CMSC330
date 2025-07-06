#pragma once
#include "expression.h"

class QuaternaryExpression : public Expression {
public:
    QuaternaryExpression(Expression* first, Expression* second, Expression* third, Expression* fourth)
        : first(first), second(second), third(third), fourth(fourth) {}
    ~QuaternaryExpression() override {
        delete first;
        delete second;
        delete third;
        delete fourth;
    }
protected:
    Expression *first, *second, *third, *fourth;
};

class ComplexConditional : public QuaternaryExpression {
public:
    ComplexConditional(Expression* cond, Expression* less_expr, Expression* equal_expr, Expression* greater_expr)
        : QuaternaryExpression(cond, less_expr, equal_expr, greater_expr) {}
    double evaluate() override {
        double cond_val = first->evaluate();
        if (cond_val < 0) return second->evaluate();
        if (cond_val == 0) return third->evaluate();
        return fourth->evaluate();
    }
};