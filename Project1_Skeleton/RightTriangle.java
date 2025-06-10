// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Class that defines a hollow right triangle
 */
class RightTriangle extends HollowPolygon {

    /**
     * Constructor that initializes the vertices of the right triangle
     * @param color
     * @param upperLeft
     * @param height
     * @param width
     */
    public RightTriangle(Color color, Point upperLeft, int height, int width) {
        super(color, 3);
        int[] x_points = {upperLeft.x, upperLeft.x, upperLeft.x + width};
        int[] y_points = {upperLeft.y, upperLeft.y + height, upperLeft.y + height};
        createPolygon(x_points, y_points);
    }
}
