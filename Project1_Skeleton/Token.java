// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Defines all tokens for the language, including new shape tokens.

// Enumerated type that defines the list of tokens
enum Token {
    // Original Tokens
    AT, COLOR, END,	HEIGHT, RECTANGLE, RIGHT_TRIANGLE, SCENE, WIDTH,
    COMMA, SEMICOLON, PERIOD, LEFT_PAREN, RIGHT_PAREN,
    IDENTIFIER, NUMBER, EOF,

    // New Tokens for Expanded Grammar
    ISOSCELES, PARALLELOGRAM, REGULAR_POLYGON, TEXT,
    OFFSET, RADIUS, SIDES, STRING
}
