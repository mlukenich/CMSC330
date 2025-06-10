// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Abstract base class for a drawable image object.
 *
 */
abstract class Image {

    /** The color of the image */
    private Color color;

    /**
     * Constructs an Image with a given color
     *
     * @param color The {@code Color} for this image
     */
    public Image(Color color) {
        this.color = color;
    }

    /**
     * Sets the graphics context to the image's color. This should be
     * called by the draw method in subclasses.
     *
     * @param graphics The graphics context to modify
     */
    public void colorDrawing(Graphics graphics) {
        graphics.setColor(color);
    }

    /**
     * Renders the image onto the graphics context
     *
     * @param graphics The graphics context on which to draw.
     */
    abstract void draw(Graphics graphics);

}


