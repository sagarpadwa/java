// Q1) Define a class MyDate(Day, Month, year) with methods to accept and display a MyDate object.
// Accept date as dd, mm, yyyy. Throw user-defined exception "InvalidDateException" if the date is invalid.

import java.util.Scanner;

// User-defined exception
class InvalidDateException extends Exception {
    public InvalidDateException(String message) {
        super(message);
    }
}

// MyDate class
class MyDate {
    private int day;
    private int month;
    private int year;

    // Method to accept date
    public void acceptDate() throws InvalidDateException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter date (dd mm yyyy): ");
        day = scanner.nextInt();
        month = scanner.nextInt();
        year = scanner.nextInt();
        
        // Validate the date
        if (!isValidDate(day, month, year)) {
            throw new InvalidDateException("Invalid date: " + day + "/" + month + "/" + year);
        }
    }

    // Method to check if the date is valid
    private boolean isValidDate(int day, int month, int year) {
        if (year < 1 || month < 1 || month > 12 || day < 1) {
            return false;
        }
        int[] daysInMonth = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return day <= daysInMonth[month - 1];
    }

    // Method to check if the year is a leap year
    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Method to display the date
    public void displayDate() {
        System.out.println("Date: " + String.format("%02d/%02d/%04d", day, month, year));
    }
}

// Main class
public class DateExample {
    public static void main(String[] args) {
        MyDate date = new MyDate();
        try {
            date.acceptDate();
            date.displayDate();
        } catch (InvalidDateException e) {
            System.out.println(e.getMessage());
        }
    }
}


// Q2) Create an employee class(id, name, deptname, salary).
// Define a default and parameterized constructor. Use ‘this’ keyword to initialize instance variables.
// Keep a count of objects created. Create objects using the parameterized constructor and display the object count after each object is created.

class Employee {
    private int id;
    private String name;
    private String deptName;
    private double salary;
    private static int objectCount = 0; // Static variable to keep count of objects

    // Default constructor
    public Employee() {
        objectCount++;
    }

    // Parameterized constructor
    public Employee(int id, String name, String deptName, double salary) {
        this.id = id;
        this.name = name;
        this.deptName = deptName;
        this.salary = salary;
        objectCount++; // Increment the object count
    }

    // Static method to get the object count
    public static int getObjectCount() {
        return objectCount;
    }

    // Method to display employee details
    public void displayEmployee() {
        System.out.println("ID: " + id + ", Name: " + name + ", Department: " + deptName + ", Salary: " + salary);
    }
}

// Main class
public class EmployeeExample {
    public static void main(String[] args) {
        Employee emp1 = new Employee(101, "Alice", "IT", 60000);
        System.out.println("Employee created. Current object count: " + Employee.getObjectCount());
        emp1.displayEmployee();

        Employee emp2 = new Employee(102, "Bob", "HR", 50000);
        System.out.println("Employee created. Current object count: " + Employee.getObjectCount());
        emp2.displayEmployee();

        Employee emp3 = new Employee(103, "Charlie", "Finance", 55000);
        System.out.println("Employee created. Current object count: " + Employee.getObjectCount());
        emp3.displayEmployee();
    }
}
