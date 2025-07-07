/*
 * File: statement.cpp
 *
 * Name: Matt Lukenich
 * CMSC330 Project 2
 * Implements the Statement class
 */

#include "statement.h"
#include "parse.h"     
#include "expression.h"
#include <sstream>
#include <stdexcept>

using namespace std;

// function to trim whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

Statement::Statement(const string& line) {
    // Find the terminating semicolon and remove it
    size_t semi_pos = line.find(';');
    if (semi_pos == string::npos) {
        throw runtime_error("Syntax Error: Missing semicolon at the end of the statement.");
    }
    string content = line.substr(0, semi_pos);

    // Use a stringstream to split the content by commas
    stringstream ss(content);
    string segment;
    vector<string> segments;

    while(getline(ss, segment, ',')) {
        segments.push_back(trim(segment));
    }

    if (segments.empty()) {
        throw runtime_error("Syntax Error: Statement is empty.");
    }

    // The first segment is always the expression
    expression_text = segments[0];

    // The rest of the segments are assignments
    for (size_t i = 1; i < segments.size(); ++i) {
        string assignment_str = segments[i];
        size_t eq_pos = assignment_str.find('=');
        if (eq_pos == string::npos) {
            throw runtime_error("Syntax Error: Invalid assignment '" + assignment_str + "'");
        }
        string var_name = trim(assignment_str.substr(0, eq_pos));
        string value_str = trim(assignment_str.substr(eq_pos + 1));

        // Check for duplicate assignments
        if (assignments.count(var_name)) {
            // Check for uninitialized variables and reinitialization
            string error_message = "Error: Variable '" + var_name + "' initialized more than once.";
            throw runtime_error(error_message);
        }
        assignments[var_name] = value_str;
    }
}

double Statement::evaluate() {
    SymbolTable symbols; // Create a new empty symbol table for this statement

    // Populate the symbol table
    for (const auto& pair : assignments) {
        try {
            double value = stod(pair.second);
            symbols.insert(pair.first, value);
        } catch (const invalid_argument& e) {
            throw runtime_error("Syntax Error: Invalid number in assignment for '" + pair.first + "'");
        }
    }

    // Use the new parser to build the expression tree
    Expression* expression_tree = parse(expression_text);

    // Evaluate the tree and get the result
    double result = expression_tree->evaluate(symbols);

    // Clean up the dynamically allocated tree to prevent memory leaks
    delete expression_tree;

    return result;
}