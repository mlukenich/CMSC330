#pragma once
#include <stdexcept>
#include <string>

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Defines custom exception classes for semantic errors.
 */

class SemanticError : public std::runtime_error {
public:
    explicit SemanticError(const std::string& message) : std::runtime_error(message) {}
};

class UninitializedVariable : public SemanticError {
public:
    explicit UninitializedVariable(const std::string& variableName)
        : SemanticError("Error: Uninitialized variable '" + variableName + "' was used.") {}
};

class DuplicateVariable : public SemanticError {
public:
    explicit DuplicateVariable(const std::string& variableName)
        : SemanticError("Error: Variable '" + variableName + "' was initialized more than once.") {}
};