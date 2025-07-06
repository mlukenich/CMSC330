#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "expression.h"
#include "symboltable.h"
#include "customerrors.h"

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Main driver. Updated to call the corrected top-level parser.
 */

SymbolTable symbolTable;

// Forward declarations for functions now in parse.cpp
Expression* parseExpression(std::stringstream& in);
void parseAssignments(std::stringstream& in);

int main() {
    Expression* expression;
    std::ifstream A_IN_FILE("input.txt");
    if (!A_IN_FILE) {
        std::cerr << "Could not open input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(A_IN_FILE, line)) {
        // Clear symbol table for each new line/statement
        symbolTable.clear();

        if (line.empty() || line[0] == '#') continue;

        std::stringstream in(line, std::ios_base::in);
        char comma;

        try {
            // Call the corrected top-level parser
            expression = parseExpression(in);
            
            in >> std::ws;
            if (in.peek() == ',') {
                in.get(); // Consume comma
                parseAssignments(in);
            }

            double result = expression->evaluate();
            std::cout << "Value = " << result << std::endl;
        } catch (const SemanticError& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    A_IN_FILE.close();
    return 0;
}