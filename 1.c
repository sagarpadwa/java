// Slip 1, Question 1: Program to print all Prime numbers in an array of 'n' elements (use command line arguments)

public class PrimeArray {
    public static void main(String[] args) {
        int n = args.length;
        int[] array = new int[n];
        
        // Convert command line arguments to integers
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(args[i]);
        }

        // Find and print prime numbers
        System.out.println("Prime numbers in the array:");
        for (int num : array) {
            if (isPrime(num)) {
                System.out.print(num + " ");
            }
        }
    }

    // Method to check if a number is prime
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}


// Slip 1, Question 2: Define abstract class Staff with subclass OfficeStaff

abstract class Staff {
    protected int id;
    protected String name;

    // Parameterized constructor
    public Staff(int id, String name) {
        this.id = id;
        this.name = name;
    }

    // Abstract method to display details (can be overridden in subclasses)
    public abstract void display();
}

class OfficeStaff extends Staff {
    private String department;

    // Constructor for OfficeStaff
    public OfficeStaff(int id, String name, String department) {
        super(id, name);
        this.department = department;
    }

    // Overriding the display method
    @Override
    public void display() {
        System.out.println("ID: " + id + ", Name: " + name + ", Department: " + department);
    }
}

public class OfficeStaffTest {
    public static void main(String[] args) {
        // Create multiple OfficeStaff objects
        OfficeStaff[] staffArray = new OfficeStaff[3];
        staffArray[0] = new OfficeStaff(101, "Alice", "HR");
        staffArray[1] = new OfficeStaff(102, "Bob", "Finance");
        staffArray[2] = new OfficeStaff(103, "Charlie", "IT");

        // Display all OfficeStaff details
        for (OfficeStaff staff : staffArray) {
            staff.display();
        }
    }
}
