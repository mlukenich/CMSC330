#pragma once

/*
 * Name: [Your Name]
 * Date: [Current Date]
 * Project: CMSC 330 Project 2
 * Description: Base class for all expressions, updated to return double.
 */

class Expression {
public:
    virtual ~Expression() = default;
    virtual double evaluate() = 0;
};