// Q1) Define a class MyNumber having one private int data member. Write a default constructor to
// initialize it to 0 and another constructor to initialize it to a value (Use this). Write methods
// isNegative, isPositive, isZero, isOdd, isEven. Create an object in main. Use command line
// arguments to pass a value to the Object.

class MyNumber {
    private int data;

    // Default constructor
    public MyNumber() {
        this.data = 0;
    }

    // Parameterized constructor
    public MyNumber(int value) {
        this.data = value;
    }

    // Method to check if the number is negative
    public boolean isNegative() {
        return data < 0;
    }

    // Method to check if the number is positive
    public boolean isPositive() {
        return data > 0;
    }

    // Method to check if the number is zero
    public boolean isZero() {
        return data == 0;
    }

    // Method to check if the number is odd
    public boolean isOdd() {
        return data % 2 != 0;
    }

    // Method to check if the number is even
    public boolean isEven() {
        return data % 2 == 0;
    }

    // Method to display the number and its properties
    public void displayProperties() {
        System.out.println("Number: " + data);
        System.out.println("Is Negative: " + isNegative());
        System.out.println("Is Positive: " + isPositive());
        System.out.println("Is Zero: " + isZero());
        System.out.println("Is Odd: " + isOdd());
        System.out.println("Is Even: " + isEven());
    }
}

// Main class
public class MyNumberExample {
    public static void main(String[] args) {
        // Check if command line arguments are provided
        if (args.length > 0) {
            try {
                // Convert the argument to an integer
                int value = Integer.parseInt(args[0]);
                MyNumber number = new MyNumber(value);
                number.displayProperties();
            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid integer.");
            }
        } else {
            // Create object with default constructor
            MyNumber number = new MyNumber();
            number.displayProperties();
        }
    }
}


// Q2) Write a simple currency converter, as shown in the figure. User can enter the amount of
// "Singapore Dollars", "US Dollars", or "Euros", in floating-point number. The converted
// values shall be displayed to 2 decimal places. Assume that 1 USD = 1.41 SGD,
// 1 USD = 0.92 Euro, 1 SGD = 0.65 Euro.

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CurrencyConverter extends JFrame implements ActionListener {
    private JTextField inputField;
    private JTextArea outputArea;
    private JButton convertButton;

    // Conversion rates
    private static final double USD_TO_SGD = 1.41;
    private static final double USD_TO_EURO = 0.92;
    private static final double SGD_TO_EURO = 0.65;

    public CurrencyConverter() {
        setTitle("Currency Converter");
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        JLabel label = new JLabel("Enter amount:");
        add(label);

        inputField = new JTextField(10);
        add(inputField);

        convertButton = new JButton("Convert");
        convertButton.addActionListener(this);
        add(convertButton);

        outputArea = new JTextArea(8, 20);
        outputArea.setEditable(false);
        add(new JScrollPane(outputArea));

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            double amount = Double.parseDouble(inputField.getText());
            StringBuilder result = new StringBuilder();
            result.append(String.format("Amount in SGD: %.2f\n", amount * USD_TO_SGD));
            result.append(String.format("Amount in Euro: %.2f\n", amount * USD_TO_EURO));
            result.append(String.format("Amount in USD: %.2f\n", amount));
            outputArea.setText(result.toString());
        } catch (NumberFormatException ex) {
            outputArea.setText("Please enter a valid amount.");
        }
    }

    public static void main(String[] args) {
        new CurrencyConverter();
    }
}
