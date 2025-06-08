// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Defines a solid polygon by filling the shape with color.

import java.awt.*;

// Class that defines all solid polygons
public class SolidPolygon extends Polygon_ {

    // Constructor that calls the super constructor
    public SolidPolygon(Color color, int vertexCount) {
        super(color, vertexCount);
    }

    // Draws a solid polygon by filling the shape
    @Override
    public void drawPolygon(Graphics graphics, Polygon polygon) {
        graphics.fillPolygon(polygon);
    }
}
