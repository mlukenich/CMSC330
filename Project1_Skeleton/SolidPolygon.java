// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Class that defines all solid polygons
 */
public class SolidPolygon extends Polygon_ {

    /**
     * Constructor that calls the super constructor
     * @param color
     * @param vertexCount
     */
    public SolidPolygon(Color color, int vertexCount) {
        super(color, vertexCount);
    }

    /**
     * Draws a solid polygon by filling the shape
     * @param graphics
     * @param polygon
     */
    @Override
    public void drawPolygon(Graphics graphics, Polygon polygon) {
        graphics.fillPolygon(polygon);
    }
}
