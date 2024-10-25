// Q1) Create an abstract class 'Bank' with an abstract method 'getBalance'. Rs.100, Rs.150 and
// Rs.200 are deposited in banks A, B and C respectively. 'BankA', 'BankB' and 'BankC'
// are subclasses of class 'Bank', each having a method named 'getBalance'. Call this method
// by creating an object of each of the three classes.

abstract class Bank {
    abstract int getBalance(); // Abstract method to get balance
}

// BankA class extending Bank
class BankA extends Bank {
    private int balance;

    public BankA() {
        this.balance = 100; // Depositing Rs.100
    }

    @Override
    int getBalance() {
        return balance;
    }
}

// BankB class extending Bank
class BankB extends Bank {
    private int balance;

    public BankB() {
        this.balance = 150; // Depositing Rs.150
    }

    @Override
    int getBalance() {
        return balance;
    }
}

// BankC class extending Bank
class BankC extends Bank {
    private int balance;

    public BankC() {
        this.balance = 200; // Depositing Rs.200
    }

    @Override
    int getBalance() {
        return balance;
    }
}

// Main class
public class BankExample {
    public static void main(String[] args) {
        Bank bankA = new BankA();
        Bank bankB = new BankB();
        Bank bankC = new BankC();

        System.out.println("Balance in Bank A: Rs." + bankA.getBalance());
        System.out.println("Balance in Bank B: Rs." + bankB.getBalance());
        System.out.println("Balance in Bank C: Rs." + bankC.getBalance());
    }
}


// Q2) Program that displays three concentric circles wherever the user clicks the mouse on a frame.
// The program must exit when user clicks ‘X’ on the frame.

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class ConcentricCircles extends JFrame {
    public ConcentricCircles() {
        setTitle("Concentric Circles");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Mouse listener to draw circles on click
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Graphics g = getGraphics();
                drawCircles(g, e.getX(), e.getY());
            }
        });

        setVisible(true);
    }

    // Method to draw concentric circles
    private void drawCircles(Graphics g, int x, int y) {
        g.setColor(Color.BLUE);
        g.drawOval(x - 30, y - 30, 60, 60);   // First circle
        g.setColor(Color.GREEN);
        g.drawOval(x - 50, y - 50, 100, 100); // Second circle
        g.setColor(Color.RED);
        g.drawOval(x - 70, y - 70, 140, 140); // Third circle
    }

    // Main method
    public static void main(String[] args) {
        new ConcentricCircles();
    }
}
