/*
 * parse.h
 *
 * Created on: July 6, 2025
 * Author: [Your Name]
 * Description: Header for the recursive descent parser.
 */

#ifndef PARSE_H_
#define PARSE_H_

#include <string>
#include "expression.h"

using namespace std;

// The main function of our new parser
Expression* parse(const string& text);

#endif /* PARSE_H_ */