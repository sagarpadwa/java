import java.io.File;
import java.util.Scanner;

public class FileInfo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the file name from the user
        System.out.print("Enter the file name: ");
        String fileName = scanner.nextLine();

        // Create a File object
        File file = new File(fileName);

        // Check if the file exists
        if (file.exists()) {
            System.out.println("File exists: " + file.getName());

            // Check if the file is readable
            if (file.canRead()) {
                System.out.println("The file is readable.");
            } else {
                System.out.println("The file is not readable.");
            }

            // Check if the file is writable
            if (file.canWrite()) {
                System.out.println("The file is writable.");
            } else {
                System.out.println("The file is not writable.");
            }

            // Get the file type (extension)
            String fileNameWithExtension = file.getName();
            String extension = "";
            int dotIndex = fileNameWithExtension.lastIndexOf('.');
            if (dotIndex > 0) {
                extension = fileNameWithExtension.substring(dotIndex + 1);
            } else {
                extension = "Unknown type";
            }
            System.out.println("File type: " + extension);

            // Get the file length (size) in bytes
            long length = file.length();
            System.out.println("File length: " + length + " bytes");

        } else {
            System.out.println("File does not exist.");
        }

        scanner.close();
    }
}



////////////////////////////////////////////////
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingTemperatureConverter {

    public static void main(String[] args) {
        // Create a JFrame
        JFrame frame = new JFrame("Temperature Converter");
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(3, 2));

        // Create components
        JLabel celsiusLabel = new JLabel("Celsius:");
        JTextField celsiusField = new JTextField();
        JLabel fahrenheitLabel = new JLabel("Fahrenheit:");
        JTextField fahrenheitField = new JTextField();
        JButton convertButton = new JButton("Convert");

        // Add components to frame
        frame.add(celsiusLabel);
        frame.add(celsiusField);
        frame.add(fahrenheitLabel);
        frame.add(fahrenheitField);
        frame.add(new JLabel(""));  // Empty label for spacing
        frame.add(convertButton);

        // Add action listener to the convert button
        convertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    // Check if Celsius field has input
                    if (!celsiusField.getText().isEmpty()) {
                        double celsius = Double.parseDouble(celsiusField.getText());
                        double fahrenheit = (celsius * 9 / 5) + 32;
                        fahrenheitField.setText(String.format("%.1f", fahrenheit));
                    }
                    // Check if Fahrenheit field has input
                    else if (!fahrenheitField.getText().isEmpty()) {
                        double fahrenheit = Double.parseDouble(fahrenheitField.getText());
                        double celsius = (fahrenheit - 32) * 5 / 9;
                        celsiusField.setText(String.format("%.1f", celsius));
                    } else {
                        JOptionPane.showMessageDialog(null, "Please enter a value in either field.");
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Please enter a valid number.");
                }
            }
        });

        // Set frame visibility
        frame.setVisible(true);
    }
}
