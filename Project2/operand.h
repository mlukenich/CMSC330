#pragma once
#include "expression.h"
#include "symboltable.h"
#include <string>

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Defines literal and variable operands. Parsing logic moved to parse.cpp.
 */

extern SymbolTable symbolTable;

class Operand : public Expression {
    // The static parse method has been removed from the class
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
