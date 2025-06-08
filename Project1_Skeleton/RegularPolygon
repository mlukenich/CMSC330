// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Defines a solid regular polygon.

import java.awt.*;

// Class that defines a solid regular polygon
public class RegularPolygon extends SolidPolygon {

    // Constructor that initializes the vertices of a regular polygon
    public RegularPolygon(Color color, int sides, Point center, int radius) {
        super(color, sides);
        int[] x_points = new int[sides];
        int[] y_points = new int[sides];

        for (int i = 0; i < sides; i++) {
            double angle = 2 * Math.PI * i / sides;
            x_points[i] = (int) (center.x + radius * Math.cos(angle));
            y_points[i] = (int) (center.y + radius * Math.sin(angle));
        }
        createPolygon(x_points, y_points);
    }
}
