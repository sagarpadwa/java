// Q1) Write a program to create an abstract class named Shape that contains two integers and an
// empty method named printArea(). Provide three classes named Rectangle, Triangle and Circle
// such that each one of the classes extends the class Shape. Each one of the classes contains
// only the method printArea() that prints the area of the given shape. (use method overriding).

abstract class Shape {
    int a; // Represents one dimension (base or radius)
    int b; // Represents another dimension (height or not used)

    // Abstract method
    abstract void printArea();
}

// Rectangle class extending Shape
class Rectangle extends Shape {
    Rectangle(int length, int width) {
        this.a = length;
        this.b = width;
    }

    @Override
    void printArea() {
        double area = a * b; // Area = length * width
        System.out.println("Area of Rectangle: " + area);
    }
}

// Triangle class extending Shape
class Triangle extends Shape {
    Triangle(int base, int height) {
        this.a = base;
        this.b = height;
    }

    @Override
    void printArea() {
        double area = 0.5 * a * b; // Area = 0.5 * base * height
        System.out.println("Area of Triangle: " + area);
    }
}

// Circle class extending Shape
class Circle extends Shape {
    Circle(int radius) {
        this.a = radius;
    }

    @Override
    void printArea() {
        double area = Math.PI * a * a; // Area = π * radius^2
        System.out.println("Area of Circle: " + area);
    }
}

// Main class
public class ShapeExample {
    public static void main(String[] args) {
        Shape rectangle = new Rectangle(10, 5);
        rectangle.printArea();

        Shape triangle = new Triangle(8, 5);
        triangle.printArea();

        Shape circle = new Circle(7);
        circle.printArea();
    }
}


// Q2) Write a program that handles all mouse events and shows the event name at the center of the
// Window, red in color when a mouse event is fired. (Use adapter classes)

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// Main class
public class MouseEventExample extends JFrame {
    private JLabel label;

    public MouseEventExample() {
        setTitle("Mouse Event Example");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        label = new JLabel("Mouse Event: ", SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.BOLD, 20));
        label.setForeground(Color.RED);
        add(label, BorderLayout.CENTER);

        // Adding mouse listener using MouseAdapter
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked at: " + e.getPoint());
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                label.setText("Mouse Entered");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                label.setText("Mouse Exited");
            }

            @Override
            public void mousePressed(MouseEvent e) {
                label.setText("Mouse Pressed");
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                label.setText("Mouse Released");
            }
        });
    }

    // Main method
    public static void main(String[] args) {
        MouseEventExample frame = new MouseEventExample();
        frame.setVisible(true);
    }
}
