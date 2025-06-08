// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: REVISED - Uses a HashMap for robust keyword tokenizing.

import java.io.*;
import java.util.HashMap;
import java.util.Map;

// This class provides the lexical analyzer for project 1
class Lexer {

    private StreamTokenizer tokenizer;
    // MODIFICATION START: Use a HashMap for keyword lookups
    private Map<String, Token> keywords;
    // MODIFICATION END

    // Constructor that creates a lexical analyzer object given the source file
    public Lexer(File file) throws FileNotFoundException {
        tokenizer = new StreamTokenizer(new FileReader(file));
        tokenizer.ordinaryChar('.');
        tokenizer.quoteChar('"');

        // MODIFICATION START: Initialize the keyword map
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
        // MODIFICATION END
    }

    // Returns the next token in the input stream
    public Token getNextToken() throws LexicalError, IOException {
        int tokenType = tokenizer.nextToken();
        switch (tokenType) {
            case StreamTokenizer.TT_NUMBER:
                return Token.NUMBER;
            case StreamTokenizer.TT_WORD:
                // MODIFICATION START: Look up the word in the keywords map
                String word = tokenizer.sval.toUpperCase();
                if (keywords.containsKey(word)) {
                    return keywords.get(word);
                }
                // If it's not a keyword, it's an identifier
                return Token.IDENTIFIER;
                // MODIFICATION END
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
                throw new LexicalError(lexer.getLineNo(), "Unrecognized token");
        }
    }

    // Returns the lexeme associated with the current token
    public String getLexeme() {
        return tokenizer.sval;
    }

    // Returns the numeric value of the current token for numeric tokens
    public int getNumber() {
        return (int) tokenizer.nval;
    }

    // Returns the current line of the input file
    public int getLineNo() {
        return tokenizer.lineno();
    }
}
