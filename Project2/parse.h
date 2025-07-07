/*
 * File: parse.h
 * Name: Matt Lukencih
 * header for the recursive descent parser
 */

#ifndef PARSE_H_
#define PARSE_H_

#include <string>
#include "expression.h"

using namespace std;

Expression* parse(const string& text);

#endif 