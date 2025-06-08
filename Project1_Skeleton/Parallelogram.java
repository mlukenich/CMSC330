// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Defines a solid parallelogram.

import java.awt.*;

// Class that defines a solid parallelogram
public class Parallelogram extends SolidPolygon {

    // Constructor that initializes the vertices of the parallelogram
    public Parallelogram(Color color, Point upperLeft, Point lowerRight, int offset) {
        super(color, 4);
        int[] x_points = {upperLeft.x, upperLeft.x + (lowerRight.x - upperLeft.x - offset), lowerRight.x, upperLeft.x + offset};
        int[] y_points = {upperLeft.y, upperLeft.y, lowerRight.y, lowerRight.y};
        createPolygon(x_points, y_points);
    }
}
