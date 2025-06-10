// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

/**
 * Class that defines a syntax error
 */
class SyntaxError extends Exception
{
    /**
     * Constructor that creates a syntax error object given the line number and error
     * @param line
     * @param description
     */
    public SyntaxError(int line, String description) {
        super("Syntax Error on Line: " + line + " " + description);
    }
}