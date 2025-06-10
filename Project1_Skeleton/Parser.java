// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.awt.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

/**
 * Parser class
 */
class Parser {
    private Token token;
    private Lexer lexer;

    /**
     * Constructor to create new Lexer from input file
     * @param file
     * @throws IOException
     */
    public Parser(File file) throws IOException {
        lexer = new Lexer(file);
    }

    /**
     * Parses the scene
     * @return scene
     * @throws LexicalError
     * @throws SyntaxError
     * @throws IOException
     */
    public Scene parseScene() throws LexicalError, SyntaxError, IOException {
        verifyNextToken(Token.SCENE);
        verifyNextToken(Token.IDENTIFIER);
        String window = lexer.getLexeme();
        int[] dimensions = getNumberList(2);
        Scene scene = new Scene(window, dimensions[0], dimensions[1]);
        parseImages(scene, lexer.getNextToken());
        verifyNextToken(Token.PERIOD);
        return scene;
    }

    /*
     * Private method. Parses all image productions recursively
     * @param scene
     * @param imageToken
     * @throws LexicalError
     * @throws SyntaxError
     * @throws IOException
     */ 
    private void parseImages(Scene scene, Token imageToken) throws LexicalError, SyntaxError, IOException {
        int height, width, offset, radius, sides;
        verifyNextToken(Token.COLOR);
        int[] colors = getNumberList(3);
        Color color = new Color(colors[0], colors[1], colors[2]);
        verifyNextToken(Token.AT);
        int[] location = getNumberList(2);
        Point point = new Point(location[0], location[1]);

        if (imageToken == Token.RIGHT_TRIANGLE) {
            verifyNextToken(Token.HEIGHT);
            verifyNextToken(Token.NUMBER);
            height = lexer.getNumber();
            verifyNextToken(Token.WIDTH);
            verifyNextToken(Token.NUMBER);
            width = lexer.getNumber();
            RightTriangle triangle = new RightTriangle(color, point, height, width);
            scene.addImage(triangle);
        } else if (imageToken == Token.RECTANGLE) {
            verifyNextToken(Token.HEIGHT);
            verifyNextToken(Token.NUMBER);
            height = lexer.getNumber();
            verifyNextToken(Token.WIDTH);
            verifyNextToken(Token.NUMBER);
            width = lexer.getNumber();
            Rectangle rectangle = new Rectangle(color, point, height, width);
            scene.addImage(rectangle);
        } else if (imageToken == Token.ISOSCELES) {
            verifyNextToken(Token.HEIGHT);
            verifyNextToken(Token.NUMBER);
            height = lexer.getNumber();
            verifyNextToken(Token.WIDTH);
            verifyNextToken(Token.NUMBER);
            width = lexer.getNumber();
            IsoscelesTriangle triangle = new IsoscelesTriangle(color, point, height, width);
            scene.addImage(triangle);
        } else if (imageToken == Token.PARALLELOGRAM) {
            int[] point2_coords = getNumberList(2);
            Point point2 = new Point(point2_coords[0], point2_coords[1]);
            verifyNextToken(Token.OFFSET);
            verifyNextToken(Token.NUMBER);
            offset = lexer.getNumber();
            Parallelogram parallelogram = new Parallelogram(color, point, point2, offset);
            scene.addImage(parallelogram);
        } else if (imageToken == Token.REGULAR_POLYGON) {
            verifyNextToken(Token.SIDES);
            verifyNextToken(Token.NUMBER);
            sides = lexer.getNumber();
            verifyNextToken(Token.RADIUS);
            verifyNextToken(Token.NUMBER);
            radius = lexer.getNumber();
            RegularPolygon polygon = new RegularPolygon(color, sides, point, radius);
            scene.addImage(polygon);
        } else if (imageToken == Token.TEXT) {
            verifyNextToken(Token.STRING);
            String textContent = lexer.getLexeme();
            Text text = new Text(color, point, textContent);
            scene.addImage(text);
        } else {
             throw new SyntaxError(lexer.getLineNo(), "Unexpected image name " + imageToken);
        }
        verifyNextToken(Token.SEMICOLON);
        token = lexer.getNextToken();
        if (token != Token.END)
            parseImages(scene, token);
    }

    /*
     * Private method to get the number list 
     * @param count
     * @return numberList
     * @throws LexicalError
     * @throws SyntaxError
     * @throws IOException
     */
    private int[] getNumberList(int count) throws LexicalError, SyntaxError, IOException {
        int[] list = new int[count];
        verifyNextToken(Token.LEFT_PAREN);
        for (int i = 0; i < count; i++) {
            verifyNextToken(Token.NUMBER);
            list[i] = lexer.getNumber();
            token = lexer.getNextToken();
            if (i < count - 1)
                verifyCurrentToken(Token.COMMA);
            else
                verifyCurrentToken(Token.RIGHT_PAREN);
        }
        return list;
    }
 
 /*
  * Private method to verify next token 
  * @param expectedToken
  * @throws LexicalError
  * @throws SyntaxError
  * @throws IOException
  */
 private void verifyNextToken(Token expectedToken) throws LexicalError, SyntaxError, IOException {
        token = lexer.getNextToken();
        verifyCurrentToken(expectedToken);
}

/*
 * Private method to verify current token
 * @param expectedToken
 * @throws SyntaxError
 */
private void verifyCurrentToken(Token expectedToken) throws SyntaxError {
        if (token != expectedToken)
            throw new SyntaxError(lexer.getLineNo(), "Expecting token " + expectedToken + " not " + token);
}
}
