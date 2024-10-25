import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Student {
    int rollno;
    String name;
    String className;
    double percentage;

    // Constructor to initialize student details
    public Student(int rollno, String name, String className, double percentage) {
        this.rollno = rollno;
        this.name = name;
        this.className = className;
        this.percentage = percentage;
    }

    // Method to display student details
    public void displayStudentInfo() {
        System.out.println("Roll Number: " + rollno);
        System.out.println("Name: " + name);
        System.out.println("Class: " + className);
        System.out.println("Percentage: " + percentage);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Reading input from user
        System.out.print("Enter Roll Number: ");
        int rollno = Integer.parseInt(br.readLine());

        System.out.print("Enter Name: ");
        String name = br.readLine();

        System.out.print("Enter Class: ");
        String className = br.readLine();

        System.out.print("Enter Percentage: ");
        double percentage = Double.parseDouble(br.readLine());

        // Creating a Student object
        Student student = new Student(rollno, name, className, percentage);

        // Display student details
        student.displayStudentInfo();
    }
}


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentGUI {
    public static void main(String[] args) {
        // Creating the frame
        JFrame frame = new JFrame("Student Information");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(6, 2));

        // Creating components
        JLabel nameLabel = new JLabel("Your Name");
        JTextField nameField = new JTextField(20);

        JLabel classLabel = new JLabel("Your Class");
        JRadioButton fyRadio = new JRadioButton("FY");
        JRadioButton syRadio = new JRadioButton("SY");
        JRadioButton tyRadio = new JRadioButton("TY");

        // Grouping radio buttons
        ButtonGroup classGroup = new ButtonGroup();
        classGroup.add(fyRadio);
        classGroup.add(syRadio);
        classGroup.add(tyRadio);

        JLabel hobbiesLabel = new JLabel("Your Hobbies");
        JCheckBox musicCheck = new JCheckBox("Music");
        JCheckBox danceCheck = new JCheckBox("Dance");
        JCheckBox sportsCheck = new JCheckBox("Sports");

        JTextArea resultText = new JTextArea(3, 20);
        resultText.setEditable(false);

        JButton submitButton = new JButton("Submit");

        // Adding action listener to submit button
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Get the name
                String name = nameField.getText();

                // Get the selected class
                String className = "";
                if (fyRadio.isSelected()) {
                    className = "FY";
                } else if (syRadio.isSelected()) {
                    className = "SY";
                } else if (tyRadio.isSelected()) {
                    className = "TY";
                }

                // Get the selected hobbies
                StringBuilder hobbies = new StringBuilder();
                if (musicCheck.isSelected()) {
                    hobbies.append("Music ");
                }
                if (danceCheck.isSelected()) {
                    hobbies.append("Dance ");
                }
                if (sportsCheck.isSelected()) {
                    hobbies.append("Sports ");
                }

                // Display the result in the text area
                resultText.setText("Name: " + name + "\nClass: " + className + "\nHobbies: " + hobbies.toString());
            }
        });

        // Adding components to the frame
        frame.add(nameLabel);
        frame.add(nameField);

        frame.add(classLabel);
        frame.add(fyRadio);
        frame.add(new JLabel(""));
        frame.add(syRadio);
        frame.add(new JLabel(""));
        frame.add(tyRadio);

        frame.add(hobbiesLabel);
        frame.add(musicCheck);
        frame.add(danceCheck);
        frame.add(sportsCheck);

        frame.add(submitButton);
        frame.add(resultText);

        // Set frame visibility
        frame.setVisible(true);
    }
}
