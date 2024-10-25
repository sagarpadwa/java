// Slip 14, Question 1: Program to throw exception if number is 0 and check if it's prime

class ZeroException extends Exception {
    public ZeroException(String message) {
        super(message);
    }
}

public class PrimeCheck {
    public static void main(String[] args) {
        int number = Integer.parseInt(args[0]);

        try {
            if (number == 0) {
                throw new ZeroException("Number is 0");
            } else if (isPrime(number)) {
                System.out.println(number + " is a prime number.");
            } else {
                System.out.println(number + " is not a prime number.");
            }
        } catch (ZeroException e) {
            System.out.println(e.getMessage());
        }
    }

    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}


// Slip 14, Question 2: Program to calculate grades based on SYMarks and TYMarks

package SY;
public class SYMarks {
    int computerTotal, mathsTotal, electronicsTotal;

    public SYMarks(int computer, int maths, int electronics) {
        this.computerTotal = computer;
        this.mathsTotal = maths;
        this.electronicsTotal = electronics;
    }

    public int getComputerTotal() {
        return computerTotal;
    }
}

package TY;
public class TYMarks {
    int theory, practicals;

    public TYMarks(int theory, int practicals) {
        this.theory = theory;
        this.practicals = practicals;
    }

    public int getTheoryTotal() {
        return theory;
    }
}

public class Student {
    int rollNumber;
    String name;
    SY.SYMarks syMarks;
    TY.TYMarks tyMarks;

    public Student(int rollNumber, String name, SY.SYMarks syMarks, TY.TYMarks tyMarks) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.syMarks = syMarks;
        this.tyMarks = tyMarks;
    }

    public void calculateGrade() {
        int totalMarks = syMarks.getComputerTotal() + tyMarks.getTheoryTotal();
        String grade;

        if (totalMarks >= 70) {
            grade = "A";
        } else if (totalMarks >= 60) {
            grade = "B";
        } else if (totalMarks >= 50) {
            grade = "C";
        } else if (totalMarks >= 40) {
            grade = "Pass";
        } else {
            grade = "Fail";
        }

        System.out.println("Student: " + name + " | Roll No: " + rollNumber + " | Grade: " + grade);
    }

    public static void main(String[] args) {
        SY.SYMarks syMarks = new SY.SYMarks(65, 70, 75);
        TY.TYMarks tyMarks = new TY.TYMarks(60, 80);

        Student student = new Student(101, "Alice", syMarks, tyMarks);
        student.calculateGrade();
    }
}
