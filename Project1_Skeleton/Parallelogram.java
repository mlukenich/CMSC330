// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Class that defines a solid parallelogram
 */
public class Parallelogram extends SolidPolygon {

    /**
     * Constructor that initializes the vertices of the parallelogram
     * @param color
     * @param upperLeft
     * @param lowerRight
     * @param offset
     */
    public Parallelogram(Color color, Point upperLeft, Point lowerRight, int offset) {
        super(color, 4);
        int[] x_points = {upperLeft.x, upperLeft.x + (lowerRight.x - upperLeft.x - offset), lowerRight.x, upperLeft.x + offset};
        int[] y_points = {upperLeft.y, upperLeft.y, lowerRight.y, lowerRight.y};
        createPolygon(x_points, y_points);
    }
}
