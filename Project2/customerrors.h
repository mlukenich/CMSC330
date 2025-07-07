#pragma once
#include <stdexcept>
#include <string>

/*
 * File: customerrors.h
 * Name: Matt Lukenich
 * CMSC 330 Project 2
 * Defines custom exception classes for semantic errors.
 */

class SemanticError : public std::runtime_error {
public:
    explicit SemanticError(const std::string& message) : std::runtime_error(message) {}
};

/*
 * Throws and error for an unitialized variable.
 */
class UninitializedVariable : public SemanticError {
public:
    explicit UninitializedVariable(const std::string& variableName)
        : SemanticError("Error: Uninitialized variable '" + variableName + "' was used.") {}
};

/*
 * Throws and error for a duplicate variable.
 */
class DuplicateVariable : public SemanticError {
public:
    explicit DuplicateVariable(const std::string& variableName)
        : SemanticError("Error: Variable '" + variableName + "' was initialized more than once.") {}
};