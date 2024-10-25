// Slip 10, Question 1: Program to find the cube of a number using a functional interface

@FunctionalInterface
interface Cube {
    int calculate(int x);
}

public class CubeTest {
    public static void main(String[] args) {
        // Lambda expression to calculate the cube of a number
        Cube cube = (x) -> x * x * x;

        int num = 5;  // Example number
        System.out.println("The cube of " + num + " is: " + cube.calculate(num));
    }
}


// Slip 10, Question 2: Creating a package "student" and defining StudentInfo and StudentPer classes

// Save as: student/StudentInfo.java
package student;

public class StudentInfo {
    int rollNo;
    String studentClass;
    double percentage;

    public StudentInfo(int rollNo, String studentClass, double percentage) {
        this.rollNo = rollNo;
        this.studentClass = studentClass;
        this.percentage = percentage;
    }

    public void displayInfo() {
        System.out.println("Roll No: " + rollNo + ", Class: " + studentClass + ", Percentage: " + percentage);
    }
}

// Save as: student/StudentPer.java
package student;

import java.util.Scanner;

public class StudentPer {
    public double calculatePercentage(int[] marks) {
        int total = 0;
        for (int mark : marks) {
            total += mark;
        }
        return (total / 6.0);  // Assuming 6 subjects
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter Roll No: ");
        int rollNo = scanner.nextInt();
        scanner.nextLine();  // Consume the newline

        System.out.print("Enter Class: ");
        String studentClass = scanner.nextLine();

        int[] marks = new int[6];
        System.out.println("Enter marks for 6 subjects:");
        for (int i = 0; i < 6; i++) {
            marks[i] = scanner.nextInt();
        }

        StudentPer studentPer = new StudentPer();
        double percentage = studentPer.calculatePercentage(marks);

        StudentInfo student = new StudentInfo(rollNo, studentClass, percentage);
        student.displayInfo();
    }
}
