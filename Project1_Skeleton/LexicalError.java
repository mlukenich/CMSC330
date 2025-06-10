// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

/**
 * Class for a Lexical Error
 */
class LexicalError extends Exception
{
    /**
     * Constructor that creates a lexical error object given the line number and error
     * @param line
     * @param description
     */
    public LexicalError(int line, String description)    {
        super("Lexical Error on Line: " + line + " " + description);
    }
}