// Slip 4, Question 1: Program to print an array after changing rows and columns of a 2D array

import java.util.Scanner;

public class TransposeMatrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input dimensions
        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = scanner.nextInt();

        int[][] matrix = new int[rows][cols];

        // Input matrix elements
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Print original matrix
        System.out.println("Original Matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        // Transpose matrix (switch rows and columns)
        System.out.println("Transposed Matrix:");
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                System.out.print(matrix[j][i] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }
}


// Slip 4, Question 2: Program to design a screen using AWT for username and password with exception handling

import java.awt.*;
import java.awt.event.*;

class LoginScreenAWT extends Frame implements ActionListener {
    Label l1, l2, message;
    TextField t1, t2;
    Button login, clear;
    int attempt = 0;

    public LoginScreenAWT() {
        setLayout(new FlowLayout());

        l1 = new Label("Username:");
        t1 = new TextField(15);
        l2 = new Label("Password:");
        t2 = new TextField(15);
        t2.setEchoChar('*');  // To hide password input

        login = new Button("Login");
        clear = new Button("Clear");

        message = new Label();
        
        add(l1); add(t1); add(l2); add(t2); add(login); add(clear); add(message);

        login.addActionListener(this);
        clear.addActionListener(this);

        setTitle("Login Screen");
        setSize(300, 200);
        setVisible(true);

        // Window closing event to exit the program
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public void actionPerformed(ActionEvent ae) {
        String username = t1.getText();
        String password = t2.getText();

        if (ae.getSource() == login) {
            if (username.equals(password)) {
                message.setText("Login successful!");
            } else {
                attempt++;
                if (attempt < 3) {
                    message.setText("Invalid login. Try again.");
                } else {
                    message.setText("Too many attempts. Access denied.");
                    login.setEnabled(false);  // Disable login after 3 attempts
                }
            }
        } else if (ae.getSource() == clear) {
            t1.setText("");
            t2.setText("");
            message.setText("");
        }
    }

    public static void main(String[] args) {
        new LoginScreenAWT();
    }
}
