#include "symboltable.h"
#include "customerrors.h" // Include for UninitializedVariable

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Implementation for the modified SymbolTable.
 */

void SymbolTable::insert(const std::string& variable, double value) {
    symbolTable[variable] = value;
}

double SymbolTable::lookUp(const std::string& variable) const {
    auto it = symbolTable.find(variable);
    if (it == symbolTable.end()) {
        // Throw exception if variable is not found
        throw UninitializedVariable(variable);
    }
    return it->second;
}

void SymbolTable::clear() {
    symbolTable.clear();
}

