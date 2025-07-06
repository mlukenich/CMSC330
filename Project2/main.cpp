#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "expression.h"
#include "operand.h"
#include "symboltable.h"
#include "customerrors.h"

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Main driver. Updated to handle exceptions and clear the symbol table.
 */

SymbolTable symbolTable;

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

        if (line.empty()) continue;

        std::stringstream in(line, std::ios_base::in);
        char comma;

        try {
            expression = Operand::parse(in);
            in >> comma;
            parseAssignments(in);
            double result = expression->evaluate();
            std::cout << "Value = " << result << std::endl;
        } catch (const SemanticError& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    A_IN_FILE.close();
    return 0;
}