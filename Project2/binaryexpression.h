#pragma once
#include "expression.h"
#include <cmath> // For pow
#include <algorithm>

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

class Add : public BinaryExpression {
public:
    Add(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() + right->evaluate(); }
};

class Sub : public BinaryExpression {
public:
    Sub(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() - right->evaluate(); }
};

class Mul : public BinaryExpression {
public:
    Mul(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() * right->evaluate(); }
};

class Div : public BinaryExpression {
public:
    Div(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return left->evaluate() / right->evaluate(); }
};

class Rem : public BinaryExpression {
public:
    Rem(Expression* left, Expression* right) : BinaryExpression(left, right) {}
    double evaluate() override { return fmod(left->evaluate(), right->evaluate()); }
};

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