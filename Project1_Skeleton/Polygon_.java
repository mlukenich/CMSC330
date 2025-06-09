// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// Project 1
// UMGC CITE

import java.awt.*;

/**
 * Abstract base class for all polygon classes
 */
abstract class Polygon_ extends Image {

    private int vertexCount;
    private Polygon polygon;

    /**
     * Constructor that initializes color and vertexCount of a polygon
     * @param color
     * @param vertexCount
     */
    public Polygon_(Color color, int vertexCount) {
        super(color);
        this.vertexCount = vertexCount;
    }

    /**
     * Creates a polygon object given its vertices
     * @param x_points
     * @param y_points
     */
    public void createPolygon(int[] x_points, int[] y_points) {
        polygon = new Polygon(x_points, y_points, vertexCount);
    }

    /**
     * Draw method
     * @param graphics
     */
    @Override
    public void draw(Graphics graphics) {
        colorDrawing(graphics);
        drawPolygon(graphics, polygon);
    }

    /**
     * Abstract method to draw polygon
     * @param graphics
     * @param polygon
     */
    abstract public void drawPolygon(Graphics graphics, Polygon polygon);
}
