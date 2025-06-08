// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Defines a drawable text object.

import java.awt.*;

// Class that defines a text image
public class Text extends Image {

    private Point location;
    private String text;

    // Constructor that initializes the text's color, location, and content
    public Text(Color color, Point location, String text) {
        super(color);
        this.location = location;
        this.text = text;
    }

    // Draws the text string on the graphics context
    @Override
    void draw(Graphics graphics) {
        colorDrawing(graphics);
        graphics.drawString(text, location.x, location.y);
    }
}
