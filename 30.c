import java.util.Scanner;

// Q1) Write program to define class Person with data member as Personname, Aadharno, Panno.
// Accept information for 5 objects and display appropriate information (use this keyword).

class Person {
    private String personName;
    private String aadharNo;
    private String panNo;

    // Constructor
    public Person(String personName, String aadharNo, String panNo) {
        this.personName = personName;
        this.aadharNo = aadharNo;
        this.panNo = panNo;
    }

    // Method to display person details
    public void displayInfo() {
        System.out.println("Name: " + personName);
        System.out.println("Aadhar No: " + aadharNo);
        System.out.println("PAN No: " + panNo);
        System.out.println("----------------------------");
    }
}

public class PersonInformation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Person[] persons = new Person[5];

        // Accepting information for 5 Person objects
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter details for Person " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Aadhar No: ");
            String aadharNo = scanner.nextLine();
            System.out.print("PAN No: ");
            String panNo = scanner.nextLine();

            persons[i] = new Person(name, aadharNo, panNo);
        }

        System.out.println("\nPerson Information:");
        for (Person person : persons) {
            person.displayInfo();
        }

        scanner.close();
    }
}


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// Q2) Write a program that creates a user interface to perform integer divisions. 
// The user enters two numbers in the text fields, Number1 and Number2. 
// The division of Number1 and Number2 is displayed in the Result field when the Divide button is clicked.
// If Number1 or Number2 were not an integer, the program would throw a NumberFormatException.
// If Number2 were Zero, the program would throw an Arithmetic Exception 
// Display the exception in a message dialog box.

public class IntegerDivisionUI extends JFrame implements ActionListener {
    private JTextField number1Field;
    private JTextField number2Field;
    private JTextField resultField;
    private JButton divideButton;

    public IntegerDivisionUI() {
        setTitle("Integer Division");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        // Creating UI components
        JLabel label1 = new JLabel("Number 1:");
        number1Field = new JTextField(10);
        JLabel label2 = new JLabel("Number 2:");
        number2Field = new JTextField(10);
        JLabel resultLabel = new JLabel("Result:");
        resultField = new JTextField(10);
        resultField.setEditable(false);
        divideButton = new JButton("Divide");
        divideButton.addActionListener(this);

        // Adding components to frame
        add(label1);
        add(number1Field);
        add(label2);
        add(number2Field);
        add(divideButton);
        add(resultLabel);
        add(resultField);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            // Parsing numbers from text fields
            int number1 = Integer.parseInt(number1Field.getText());
            int number2 = Integer.parseInt(number2Field.getText());

            // Performing division
            if (number2 == 0) {
                throw new ArithmeticException("Division by zero is not allowed.");
            }
            int result = number1 / number2;
            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter valid integers.", "Input Error", JOptionPane.ERROR_MESSAGE);
        } catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage(), "Math Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        new IntegerDivisionUI();
    }
}