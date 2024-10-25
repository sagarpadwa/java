// Slip 11, Question 1: Interface Operation and Cylinder class

interface Operation {
    double PI = 3.142;

    double volume();
}

class Cylinder implements Operation {
    private double radius;
    private double height;

    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double volume() {
        return PI * radius * radius * height;
    }

    public void display() {
        System.out.println("Volume of Cylinder: " + volume());
    }

    public static void main(String[] args) {
        Cylinder cylinder = new Cylinder(5, 10);  // Example dimensions
        cylinder.display();
    }
}


// Slip 11, Question 2: Raise Invalid Password exception for wrong input

class InvalidPasswordException extends Exception {
    public InvalidPasswordException(String message) {
        super(message);
    }
}

public class LoginValidation {
    public static void main(String[] args) {
        String username = "user1";
        String password = "password1";

        try {
            if (!username.equals(password)) {
                throw new InvalidPasswordException("Invalid Password: Username and password do not match.");
            } else {
                System.out.println("Login successful!");
            }
        } catch (InvalidPasswordException e) {
            System.out.println(e.getMessage());
        }
    }
}
