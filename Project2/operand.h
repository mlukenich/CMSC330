#pragma once
#include "expression.h"
#include "symboltable.h"
#include <string>

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Defines literal and variable operands. Updated for doubles and error checking.
 */

extern SymbolTable symbolTable;

class Operand : public Expression {
public:
    static Expression* parse(std::stringstream& in);
};

class Literal : public Operand {
public:
    explicit Literal(double value) : value(value) {}
    double evaluate() override { return value; }
private:
    double value;
};

class Variable : public Operand {
public:
    explicit Variable(std::string name) : name(std::move(name)) {}
    double evaluate() override { return symbolTable.lookUp(name); }
private:
    std::string name;
};
