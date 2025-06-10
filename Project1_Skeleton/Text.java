// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Class that defines a text image
 */
public class Text extends Image {

    private Point location;
    private String text;

    /**
     * Constructor that initializes the text's color, location, and content
     * @param color
     * @param location
     * @param text
     */
    public Text(Color color, Point location, String text) {
        super(color);
        this.location = location;
        this.text = text;
    }

    /**
     * Draws the text string on the graphics context
     * @param graphics
     */
    @Override
    void draw(Graphics graphics) {
        colorDrawing(graphics);
        graphics.drawString(text, location.x, location.y);
    }
}
