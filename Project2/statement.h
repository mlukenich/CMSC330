/*
 * File: statement.h
 * Name: Matt Lukenich
 * Defines the Statement class, which parses a full line of input
 * into an expression and a series of assignments.
 */

#ifndef STATEMENT_H_
#define STATEMENT_H_

#include <string>
#include <vector>
#include <map>
#include "symboltable.h"

using namespace std;

class Statement {
public:
    // Constructor 
    Statement(const string& line);

    // Evaluates the statement and returns the result
    double evaluate();

private:
    string expression_text;
    map<string, string> assignments;
};

#endif