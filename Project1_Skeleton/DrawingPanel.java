// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE


import java.awt.*;
import java.util.*;
import javax.swing.*;

/**
 * Class that defines the panel for drawing the images
 */ 
class DrawingPanel extends JPanel {

    private ArrayList<Image> images = new ArrayList<>();

    /**
     * Adds a graphic object to the drawing panel
     * @param image
     */
    public void addImage(Image image) {

        images.add(image);
      }

    /**
     * Draws all the images on the drawing panel
     * @param graphics
     */
    @Override
    protected void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        for (Image image : images)
            image.draw(graphics);
    }
}
