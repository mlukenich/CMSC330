/*
 * File: parse.cpp
 * Name: Matt Lukenich
 * CMSC330 Project2
 * A recursive descent parser that builds an Expression AST
 */

#include <string>
#include <vector>
#include <stdexcept>
#include "parse.h"

using namespace std;

// a structure to hold tokens
struct Token {
    enum Type { LPAREN, RPAREN, OP, LITERAL, VAR, END };
    Type type;
    string text;
};

// parser function
Expression* parse_expression(vector<Token>& tokens, int& pos);


// tokenizer
vector<Token> tokenize(const string& text) {
    vector<Token> tokens;
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (isspace(c)) continue;

        if (c == '(') tokens.push_back({Token::LPAREN, "("});
        else if (c == ')') tokens.push_back({Token::RPAREN, ")"});
        else if (string("+-*/%^<>&?#~").find(c) != string::npos) {
             tokens.push_back({Token::OP, string(1, c)});
        }
        else if (isdigit(c) || c == '.') {
            string num_str;
            while (i < text.length() && (isdigit(text[i]) || text[i] == '.')) {
                num_str += text[i];
                i++;
            }
            i--;
            tokens.push_back({Token::LITERAL, num_str});
        }
        else if (isalpha(c)) {
            string var_str;
            while (i < text.length() && (isalnum(text[i]) || text[i] == '_')) {
                var_str += text[i];
                i++;
            }
            i--;
            tokens.push_back({Token::VAR, var_str});
        } else {
            throw runtime_error("Syntax Error: Invalid character in expression: " + string(1, c));
        }
    }
    tokens.push_back({Token::END, ""});
    return tokens;
}

// main entry point for the parser
Expression* parse(const string& text) {
    vector<Token> tokens = tokenize(text);
    int pos = 0;
    Expression* result = parse_expression(tokens, pos);
    if (tokens[pos].type != Token::END) {
        throw runtime_error("Syntax Error: Extra characters at end of expression.");
    }
    return result;
}

// Parses any expression.
// literals, variables, or () groups
Expression* parse_expression(vector<Token>& tokens, int& pos) {
    if (tokens[pos].type == Token::LITERAL) {
        return new Literal(stod(tokens[pos++].text));
    }
    if (tokens[pos].type == Token::VAR) {
        return new Variable(tokens[pos++].text);
    }
    if (tokens[pos].type == Token::LPAREN) {
        pos++; 

        // core recursive structure
        Expression* first = parse_expression(tokens, pos);

        // check what comes after the first expression
        Token op_token = tokens[pos++];

        if (op_token.type != Token::OP) throw runtime_error("Syntax Error: Expected operator.");
        
        char op_char = op_token.text[0];

        // Handle different expression types based on the operator
        if (op_char == '~') { // Postfix Unary
            if (tokens[pos++].type != Token::RPAREN) throw runtime_error("Syntax Error: Expected ')' after unary expression.");
            return new UnaryExpression(first);
        }
        if (string("+-*/%^<>&").find(op_char) != string::npos) { // Binary
            Expression* second = parse_expression(tokens, pos);
            if (tokens[pos++].type != Token::RPAREN) throw runtime_error("Syntax Error: Expected ')' after binary expression.");
            return new BinaryExpression(first, op_char, second);
        }
        if (op_char == '?') { // Ternary
            Expression* second = parse_expression(tokens, pos);
            Expression* third = parse_expression(tokens, pos);
            if (tokens[pos++].type != Token::RPAREN) throw runtime_error("Syntax Error: Expected ')' after ternary expression.");
            return new TernaryExpression(first, second, third);
        }
        if (op_char == '#') { // quaternary
            Expression* second = parse_expression(tokens, pos);
            Expression* third = parse_expression(tokens, pos);
            Expression* fourth = parse_expression(tokens, pos);
            if (tokens[pos++].type != Token::RPAREN) throw runtime_error("Syntax Error: Expected ')' after quaternary expression.");
            return new QuaternaryExpression(first, second, third, fourth);
        }
        
        throw runtime_error("Syntax Error: Unknown operator " + op_token.text);
    }
    
    throw runtime_error("Syntax Error: Unexpected token " + tokens[pos].text);
}