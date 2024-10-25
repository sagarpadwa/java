// Slip 16, Question 1: Program to find the square of a number using a functional interface

@FunctionalInterface
interface Square {
    int calculate(int x);
}

public class SquareTest {
    public static void main(String[] args) {
        // Lambda expression to calculate the square of a number
        Square square = (x) -> x * x;

        int num = 6;  // Example number
        System.out.println("The square of " + num + " is: " + square.calculate(num));
    }
}

// Slip 16, Question 2: Basic AWT Screen with buttons and text fields

import java.awt.*;
import java.awt.event.*;

public class AWTScreenDesign extends Frame implements ActionListener {
    TextField tf;
    Button submitButton, clearButton;

    public AWTScreenDesign() {
        // Layout manager
        setLayout(new FlowLayout());

        // Create TextField and Buttons
        tf = new TextField(20);
        submitButton = new Button("Submit");
        clearButton = new Button("Clear");

        // Add components to frame
        add(new Label("Enter Text:"));
        add(tf);
        add(submitButton);
        add(clearButton);

        // Add ActionListener
        submitButton.addActionListener(this);
        clearButton.addActionListener(this);

        // Frame settings
        setTitle("AWT Screen");
        setSize(300, 150);
        setVisible(true);

        // Handle closing the window
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submitButton) {
            System.out.println("Submitted text: " + tf.getText());
        } else if (e.getSource() == clearButton) {
            tf.setText("");
        }
    }

    public static void main(String[] args) {
        new AWTScreenDesign();
    }
}
