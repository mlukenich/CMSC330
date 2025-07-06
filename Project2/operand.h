#pragma once
#include "expression.h"
#include "symboltable.h"
#include <string>
#include <iostream>

extern SymbolTable symbolTable;

class Operand : public Expression {};

class Literal : public Operand {
public:
    explicit Literal(double value) : value(value) {}
    double evaluate() override {
        std::cout << "DEBUG: EVALUATE Literal -> " << value << std::endl;
        return value;
    }
private:
    double value;
};

class Variable : public Operand {
public:
    explicit Variable(std::string name) : name(std::move(name)) {}
    double evaluate() override {
        std::cout << "DEBUG: EVALUATE Variable '" << name << "'" << std::endl;
        return symbolTable.lookUp(name);
    }
private:
    std::string name;
};
