import java.util.Scanner;

public class DiagonalSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Accepting dimensions of the matrix
        System.out.print("Enter the number of rows and columns (n for n x n matrix): ");
        int n = scanner.nextInt();

        int[][] matrix = new int[n][n];

        // Accepting elements of the matrix
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Element [" + (i + 1) + "][" + (j + 1) + "]: ");
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Calculating the sum of diagonal elements
        int diagonalSum = 0;
        for (int i = 0; i < n; i++) {
            diagonalSum += matrix[i][i]; // Summing main diagonal elements
        }

        // Displaying the result
        System.out.println("The sum of the diagonal elements is: " + diagonalSum);

        scanner.close();
    }
}
///


import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SubjectComboBox {
    public static void main(String[] args) {
        // Creating the frame
        JFrame frame = new JFrame("T.Y.B.Sc. (Comp. Sci) Subjects");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(null);

        // Creating the combo box
        String[] subjects = {
            "Data Structures",
            "Database Management Systems",
            "Operating Systems",
            "Computer Networks",
            "Software Engineering",
            "Web Technologies",
            "Object-Oriented Programming",
            "Artificial Intelligence"
        };

        JComboBox<String> comboBox = new JComboBox<>(subjects);
        comboBox.setBounds(50, 30, 300, 30);
        frame.add(comboBox);

        // Creating the text field
        JTextField textField = new JTextField();
        textField.setBounds(50, 80, 300, 30);
        frame.add(textField);

        // Adding action listener to the combo box
        comboBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedSubject = (String) comboBox.getSelectedItem();
                textField.setText(selectedSubject); // Display selected subject in text field
            }
        });

        // Making the frame visible
        frame.setVisible(true);
    }
}
