/*
 * symboltable.cpp
 *
 * Created on: July 6, 2025
 * Author: [Your Name]
 * Description: Implements the SymbolTable class functions.
 */

#include <string>
#include <map>
#include <stdexcept>
#include "symboltable.h"

using namespace std;

void SymbolTable::insert(string variable, double value) {
    variableMap[variable] = value;
}

double SymbolTable::lookUp(string variable) const {
    if (variableMap.find(variable) == variableMap.end()) {
        // This will be caught later to handle uninitialized variable errors
        throw runtime_error("Error: Variable '" + variable + "' not found.");
    }
    return variableMap.at(variable);
}

bool SymbolTable::exists(string variable) const {
    return variableMap.find(variable) != variableMap.end();
}

void SymbolTable::clear() {
    variableMap.clear();
}

