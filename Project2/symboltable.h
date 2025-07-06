#pragma once
#include <string>
#include <vector>
#include <map>

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Modified SymbolTable to support double values and clearing.
 */

class SymbolTable {
public:
    SymbolTable() = default;
    void insert(const std::string& variable, double value);
    double lookUp(const std::string& variable) const;
    void clear(); // New method to clear the table for the next statement
private:
    std::map<std::string, double> symbolTable;
};


