// Name: [Your Name]
// Date: [Current Date]
// Project: CMSC 330 Project 1
// Description: Modified to correctly handle command-line arguments.

import java.io.*;
import java.util.*;
import javax.swing.*;

// Project 1 main class

class Main {

    // The main method of the whole program, allows the name of the scene definition file to be input on the
    // command line or selected using the file chooser dialog window. It calls the parser to parse the scene
    // definition file and add the graphic objects to the scene.

    public static void main(String[] args) {
        File sceneFile = null;

        // MODIFICATION START
        // Check if a command-line argument was provided
        if (args.length > 0) {
            // If yes, use the first argument as the file name
            sceneFile = new File(args[0]);
        } else {
            // If no argument is provided, fall back to the file chooser dialog
            JFileChooser choice = new JFileChooser(new File("."));
            int option = choice.showOpenDialog(null);
            if (option == JFileChooser.APPROVE_OPTION) {
                sceneFile = choice.getSelectedFile();
            } else {
                // If the user cancels the file chooser, exit the program.
                System.out.println("No file selected. Exiting.");
                return;
            }
        }
        // MODIFICATION END

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
