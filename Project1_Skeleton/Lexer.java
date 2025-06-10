// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * This class provides the lexical analyzer for project 1
 */
class Lexer {

    /** Tokenizer for reading the input stream character by character */
    private StreamTokenizer tokenizer;

    /** Map for efficient lookup of language keywords */
    private Map<String, Token> keywords;

    /**
     * Constructs a Lexer for a given source file
     *
     * @param file The source file to be tokenized
     * @throws FileNotFoundException if the file cannot be found
     */
    public Lexer(File file) throws FileNotFoundException {
        tokenizer = new StreamTokenizer(new FileReader(file));
        tokenizer.ordinaryChar('.');
        tokenizer.quoteChar('"');

        keywords = new HashMap<>();
        keywords.put("SCENE", Token.SCENE);
        keywords.put("END", Token.END);
        keywords.put("COLOR", Token.COLOR);
        keywords.put("AT", Token.AT);
        keywords.put("HEIGHT", Token.HEIGHT);
        keywords.put("WIDTH", Token.WIDTH);
        keywords.put("RIGHTTRIANGLE", Token.RIGHT_TRIANGLE);
        keywords.put("RECTANGLE", Token.RECTANGLE);
        keywords.put("ISOSCELES", Token.ISOSCELES);
        keywords.put("PARALLELOGRAM", Token.PARALLELOGRAM);
        keywords.put("REGULARPOLYGON", Token.REGULAR_POLYGON);
        keywords.put("TEXT", Token.TEXT);
        keywords.put("OFFSET", Token.OFFSET);
        keywords.put("RADIUS", Token.RADIUS);
        keywords.put("SIDES", Token.SIDES);
    }

    /**
     * Scans the input stream and returns the next recognized token
     *
     * @return The next Token from the input stream
     * @throws LexicalError if an unrecognized token is encountered
     * @throws IOException  if an I/O error occurs
     */
    public Token getNextToken() throws LexicalError, IOException {
        int tokenType = tokenizer.nextToken();
        switch (tokenType) {
            case StreamTokenizer.TT_NUMBER:
                return Token.NUMBER;
            case StreamTokenizer.TT_WORD:
                String word = tokenizer.sval.toUpperCase();
                // Return the corresponding keyword or IDENTIFIER if not found
                return keywords.getOrDefault(word, Token.IDENTIFIER);
            case '"':
                return Token.STRING;
            case StreamTokenizer.TT_EOF:
                return Token.EOF;
            case '(': return Token.LEFT_PAREN;
            case ')': return Token.RIGHT_PAREN;
            case ',': return Token.COMMA;
            case ';': return Token.SEMICOLON;
            case '.': return Token.PERIOD;
            default:
                throw new LexicalError(getLineNo(), "Unrecognized token");
        }
    }

    /**
     * Getter for lexeme
     *
     * @return The lexeme of the current token
     */
    public String getLexeme() {
        return tokenizer.sval;
    }

    /**
     * Getter for number
     *
     * @return The integer value of the current number token
     */
    public int getNumber() {
        return (int) tokenizer.nval;
    }

    /**
     * Getter for lineno
     *
     * @return The current line number.
     */
    public int getLineNo() {
        return tokenizer.lineno();
    }
}
