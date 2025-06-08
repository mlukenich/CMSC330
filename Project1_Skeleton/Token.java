// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Modified to include new tokens for additional shapes and attributes.

// Enumerated type that defines the list of tokens

// MODIFICATION START
enum Token {AT, COLOR, END, HEIGHT, RECTANGLE, RIGHT_TRIANGLE, SCENE, WIDTH, COMMA, SEMICOLON, PERIOD, LEFT_PAREN,
    RIGHT_PAREN, IDENTIFIER, NUMBER, EOF,

    // New tokens for the expanded grammar
    ISOSCELES, PARALLELOGRAM, REGULAR_POLYGON, TEXT,
    OFFSET, RADIUS, SIDES, STRING}
// MODIFICATION END
