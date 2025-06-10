// CMSC 330 Advanced Programming Languages
// Matthew Lukenich
// 06/07/2025
// Project 1
// UMGC CITE

import java.io.*;
import java.util.*;
import javax.swing.*;

/**
 * Main
 */
class Main {

    /**
     * main
     * @param args
     */
    public static void main(String[] args) {
        File sceneFile = null;

        // check if a command line argument was provided
        if (args.length > 0) {
            // If yes, use the first argument as the file name
            sceneFile = new File(args[0]);
        } else {
            // If no argument, use the file chooser
            JFileChooser choice = new JFileChooser(new File("."));
            int option = choice.showOpenDialog(null);
            if (option == JFileChooser.APPROVE_OPTION) {
                sceneFile = choice.getSelectedFile();
            } else {
                // Quit if the user cancels the file chooser
                System.out.println("No file selected. Exiting.");
                return;
            }
        }

        try {
            Parser parser = new Parser(sceneFile);
            Scene scene = parser.parseScene();
            scene.draw();
        } catch (SyntaxError error) {
            System.out.println(error.getMessage());
        } catch (LexicalError error) {
            System.out.println(error.getMessage());
        } catch (IOException error) {
            System.out.println("IO Error: File not found or could not be read.");
        }
    }
}
