// Q1) Define an Employee class with suitable attributes having getSalary() method, which returns
// salary withdrawn by a particular employee. Write a class Manager which extends a class Employee,
// override the getSalary() method, which will return salary of manager by adding traveling
// allowance, house rent allowance etc.

class Employee {
    protected double salary;

    public Employee(double salary) {
        this.salary = salary; // Initialize salary
    }

    public double getSalary() {
        return salary; // Return employee salary
    }
}

// Manager class extending Employee
class Manager extends Employee {
    private double travelAllowance;
    private double houseRentAllowance;

    public Manager(double salary, double travelAllowance, double houseRentAllowance) {
        super(salary); // Call Employee constructor
        this.travelAllowance = travelAllowance;
        this.houseRentAllowance = houseRentAllowance;
    }

    @Override
    public double getSalary() {
        // Calculate total salary with allowances
        return salary + travelAllowance + houseRentAllowance;
    }
}

// Main class
public class EmployeeExample {
    public static void main(String[] args) {
        Employee emp = new Employee(30000);
        System.out.println("Employee Salary: Rs." + emp.getSalary());

        Manager mgr = new Manager(40000, 5000, 7000);
        System.out.println("Manager Salary (including allowances): Rs." + mgr.getSalary());
    }
}


// Q2) Write a program to accept a string as command line argument and check whether it is a file or
// directory. Also perform operations as follows:
// i) If it is a directory, delete all text files in that directory. Confirm delete operation from
// user before deleting text files. Also, display a count showing the number of files deleted,
// if any, from the directory.
// ii) If it is a file display various details of that file.

import java.io.File;
import java.util.Scanner;

public class FileDirectoryOperations {
    public static void main(String[] args) {
        // Check if command line argument is provided
        if (args.length != 1) {
            System.out.println("Please provide a file or directory path as a command line argument.");
            return;
        }

        String path = args[0];
        File file = new File(path);

        // Check if it's a directory
        if (file.isDirectory()) {
            System.out.println("Provided path is a directory: " + path);
            File[] files = file.listFiles();
            if (files != null) {
                Scanner scanner = new Scanner(System.in);
                System.out.print("Do you want to delete all text files in this directory? (yes/no): ");
                String confirmation = scanner.nextLine();

                if (confirmation.equalsIgnoreCase("yes")) {
                    int deletedCount = 0;

                    // Delete text files
                    for (File f : files) {
                        if (f.isFile() && f.getName().endsWith(".txt")) {
                            if (f.delete()) {
                                deletedCount++;
                                System.out.println("Deleted: " + f.getName());
                            }
                        }
                    }
                    System.out.println("Total text files deleted: " + deletedCount);
                } else {
                    System.out.println("Delete operation cancelled.");
                }
                scanner.close();
            } else {
                System.out.println("Directory is empty or cannot be accessed.");
            }
        }
        // Check if it's a file
        else if (file.isFile()) {
            System.out.println("Provided path is a file: " + path);
            System.out.println("File Name: " + file.getName());
            System.out.println("Absolute Path: " + file.getAbsolutePath());
            System.out.println("Readable: " + file.canRead());
            System.out.println("Writable: " + file.canWrite());
            System.out.println("File Size: " + file.length() + " bytes");
        } else {
            System.out.println("Provided path does not exist or is not a file/directory.");
        }
    }
}
