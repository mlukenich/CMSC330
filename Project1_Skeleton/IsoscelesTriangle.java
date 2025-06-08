// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Defines a solid isosceles triangle.

import java.awt.*;

// Class that defines a solid isosceles triangle
public class IsoscelesTriangle extends SolidPolygon {

    // Constructor that initializes the vertices of the isosceles triangle
    public IsoscelesTriangle(Color color, Point top, int height, int width) {
        super(color, 3);
        int halfWidth = width / 2;
        int[] x_points = {top.x, top.x - halfWidth, top.x + halfWidth};
        int[] y_points = {top.y, top.y + height, top.y + height};
        createPolygon(x_points, y_points);
    }
}
