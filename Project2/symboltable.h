/*
 * symboltable.h
 *
 * Created on: July 6, 2025
 * Author: [Your Name]
 * Description: Defines a symbol table for storing variable names and their floating-point values.
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <string>
#include <map>

using namespace std;

class SymbolTable {
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;
    bool exists(string variable) const;
    void clear(); // Added to reset the table for each new statement
private:
    map<string, double> variableMap;
};

#endif /* SYMBOLTABLE_H_ */

