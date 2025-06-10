// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Class that defines all hollow polygons
 */
class HollowPolygon extends Polygon_ {

    /**
     * Constructor that calls super constructor
     * @param color
     * @param vertexCount
     */
    public HollowPolygon(Color color, int vertexCount) {
        super(color, vertexCount);
    }

    /**
     * Draws hollow polygon
     * @param graphics
     * @param polygon
     */
    @Override
    public void drawPolygon(Graphics graphics, Polygon polygon) {
        graphics.drawPolygon(polygon);
    }
}
