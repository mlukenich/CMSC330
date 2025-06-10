// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Class that defines a solid isosceles triangle
 * @author Matthew Lukenich
 */
public class IsoscelesTriangle extends SolidPolygon {

    /**
     * Constructs an isosceles triangle with a specified color, top vertex,
     * height, and width.
     *
     * @param color  The {@code Color} of the triangle
     * @param top    The {@code Point} representing the top vertex
     * @param height The height of the triangle from the top vertex to the base
     * @param width  The width of the base of the triangle
     */
    public IsoscelesTriangle(Color color, Point top, int height, int width) {
        super(color, 3);
        int halfWidth = width / 2;
        int[] x_points = {top.x, top.x - halfWidth, top.x + halfWidth};
        int[] y_points = {top.y, top.y + height, top.y + height};
        createPolygon(x_points, y_points);
    }
}
