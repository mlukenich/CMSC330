/*
 * main.cpp
 *
 * Created on: July 6, 2025
 * Author: [Your Name]
 * Description: Main entry point for the expression evaluator. Reads statements
 * from a file and uses the Statement class to evaluate them.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "statement.h" // Include our new class

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file 'input.txt'." << endl;
        return 1;
    }

    cout << "Reading expressions from input.txt:" << endl;
    cout << "------------------------------------" << endl;

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        try {
            // Create a Statement object for each line
            Statement statement(line);
            // Evaluate it and print the result
            double result = statement.evaluate();
            cout << "Expression: " << line << endl;
            cout << "Answer: " << result << endl;
        } catch (const runtime_error& e) {
            // Catch and report any errors during parsing or evaluation
            cerr << "Error in statement: \"" << line << "\"" << endl;
            cerr << "  " << e.what() << endl;
        }
        cout << "------------------------------------" << endl;
    }

    inputFile.close();
    return 0;
}