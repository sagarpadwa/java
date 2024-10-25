// Slip 17, Question 1: Customer, Depositor, and Borrower classes with multilevel inheritance

class Customer {
    String name;
    String phoneNumber;

    public Customer(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public void display() {
        System.out.println("Customer Name: " + name + ", Phone Number: " + phoneNumber);
    }
}

class Depositor extends Customer {
    int accNo;
    double balance;

    public Depositor(String name, String phoneNumber, int accNo, double balance) {
        super(name, phoneNumber);
        this.accNo = accNo;
        this.balance = balance;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Account No: " + accNo + ", Balance: " + balance);
    }
}

class Borrower extends Depositor {
    int loanNo;
    double loanAmt;

    public Borrower(String name, String phoneNumber, int accNo, double balance, int loanNo, double loanAmt) {
        super(name, phoneNumber, accNo, balance);
        this.loanNo = loanNo;
        this.loanAmt = loanAmt;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Loan No: " + loanNo + ", Loan Amount: " + loanAmt);
    }
}

public class CustomerDetails {
    public static void main(String[] args) {
        Borrower borrower = new Borrower("Alice", "1234567890", 101, 20000.0, 201, 50000.0);
        borrower.display();
    }
}


// Slip 17, Question 2: Concatenate and reverse strings using Swing

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StringOperations extends JFrame implements ActionListener {
    JTextField textField1, textField2, resultField;
    JButton concatenateButton, reverseButton;

    public StringOperations() {
        // Create components
        textField1 = new JTextField(10);
        textField2 = new JTextField(10);
        resultField = new JTextField(15);
        resultField.setEditable(false);  // Result field is non-editable

        concatenateButton = new JButton("Concatenate");
        reverseButton = new JButton("Reverse");

        // Add action listeners
        concatenateButton.addActionListener(this);
        reverseButton.addActionListener(this);

        // Set layout and add components
        setLayout(new FlowLayout());
        add(new JLabel("First String:"));
        add(textField1);
        add(new JLabel("Second String:"));
        add(textField2);
        add(concatenateButton);
        add(reverseButton);
        add(new JLabel("Result:"));
        add(resultField);

        // Frame settings
        setTitle("String Operations");
        setSize(400, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String str1 = textField1.getText();
        String str2 = textField2.getText();

        if (e.getSource() == concatenateButton) {
            resultField.setText(str1 + str2);
        } else if (e.getSource() == reverseButton) {
            StringBuilder sb = new StringBuilder(str1);
            resultField.setText(sb.reverse().toString());
        }
    }

    public static void main(String[] args) {
        new StringOperations();
    }
}
