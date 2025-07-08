/*
 * File: symboltable.cpp
 * Name: Matt Lukenich
 * CMSC330 Project 2
 * Implements the SymbolTable class functions
 */

#include <string>
#include <map>
#include <stdexcept>
#include "symboltable.h"

using namespace std;

//insert variable into map
void SymbolTable::insert(string variable, double value) {
    variableMap[variable] = value;
}

//lookup variable
double SymbolTable::lookUp(string variable) const {
    if (variableMap.find(variable) == variableMap.end()) {
        // This will be caught later to handle uninitialized variable errors
        throw runtime_error("Error: Variable '" + variable + "' not found.");
    }
    return variableMap.at(variable);
}

// t/f does variable exist in map
bool SymbolTable::exists(string variable) const {
    return variableMap.find(variable) != variableMap.end();
}

// clear variable map
void SymbolTable::clear() {
    variableMap.clear();
}

