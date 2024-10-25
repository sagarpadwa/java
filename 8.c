// Slip 8, Question 1: Class Sphere to calculate volume and surface area

class Sphere {
    private double radius;

    // Constructor
    public Sphere(double radius) {
        this.radius = radius;
    }

    // Method to calculate surface area
    public double calculateSurfaceArea() {
        return 4 * 3.14 * radius * radius;
    }

    // Method to calculate volume
    public double calculateVolume() {
        return (4.0 / 3) * 3.14 * radius * radius * radius;
    }

    public void display() {
        System.out.println("Radius: " + radius);
        System.out.println("Surface Area: " + calculateSurfaceArea());
        System.out.println("Volume: " + calculateVolume());
    }
}

public class SphereTest {
    public static void main(String[] args) {
        Sphere sphere = new Sphere(5);  // Example radius
        sphere.display();
    }
}


// Slip 8, Question 2: Handle mouse events and display position in TextField

import java.awt.*;
import java.awt.event.*;

public class MouseEventHandler extends Frame implements MouseListener, MouseMotionListener {
    TextField textField;

    public MouseEventHandler() {
        textField = new TextField(20);
        add(textField);
        setSize(300, 200);
        setLayout(new FlowLayout());
        setVisible(true);

        addMouseListener(this);
        addMouseMotionListener(this);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        textField.setText("Mouse Clicked at: " + e.getX() + "," + e.getY());
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        textField.setText("Mouse Moved at: " + e.getX() + "," + e.getY());
    }

    // Unused mouse event methods
    @Override public void mousePressed(MouseEvent e) {}
    @Override public void mouseReleased(MouseEvent e) {}
    @Override public void mouseEntered(MouseEvent e) {}
    @Override public void mouseExited(MouseEvent e) {}
    @Override public void mouseDragged(MouseEvent e) {}

    public static void main(String[] args) {
        new MouseEventHandler();
    }
}
