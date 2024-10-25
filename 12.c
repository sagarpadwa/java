// Slip 12, Question 1: College and Department classes

class College {
    int cno;
    String cname;
    String caddr;

    public College(int cno, String cname, String caddr) {
        this.cno = cno;
        this.cname = cname;
        this.caddr = caddr;
    }

    public void displayCollegeDetails() {
        System.out.println("College No: " + cno + ", Name: " + cname + ", Address: " + caddr);
    }
}

class Department extends College {
    int dno;
    String dname;

    public Department(int cno, String cname, String caddr, int dno, String dname) {
        super(cno, cname, caddr);
        this.dno = dno;
        this.dname = dname;
    }

    public void displayDepartmentDetails() {
        displayCollegeDetails();
        System.out.println("Department No: " + dno + ", Name: " + dname);
    }

    public static void main(String[] args) {
        Department dept = new Department(101, "ABC College", "Pune", 201, "Computer Science");
        dept.displayDepartmentDetails();
    }
}


// Slip 12, Question 2: Simple calculator with GridLayout

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator extends Frame implements ActionListener {
    TextField resultField;
    Button[] buttons;
    double num1, num2, result;
    char operator;

    public SimpleCalculator() {
        setLayout(new GridLayout(4, 4));
        resultField = new TextField();
        add(resultField);

        buttons = new Button[16];
        String[] buttonLabels = {"1", "2", "3", "+", "4", "5", "6", "-", "7", "8", "9", "*", "0", ".", "=", "/"};

        for (int i = 0; i < 16; i++) {
            buttons[i] = new Button(buttonLabels[i]);
            add(buttons[i]);
            buttons[i].addActionListener(this);
        }

        setTitle("Simple Calculator");
        setSize(400, 400);
        setVisible(true);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String input = e.getActionCommand();
        if (input.charAt(0) >= '0' && input.charAt(0) <= '9') {
            resultField.setText(resultField.getText() + input);
        } else if (input.charAt(0) == '.') {
            resultField.setText(resultField.getText() + ".");
        } else if (input.charAt(0) == '=') {
            num2 = Double.parseDouble(resultField.getText());
            switch (operator) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
            }
            resultField.setText(String.valueOf(result));
        } else {
            num1 = Double.parseDouble(resultField.getText());
            operator = input.charAt(0);
            resultField.setText("");
        }
    }

    public static void main(String[] args) {
        new SimpleCalculator();
    }
}
