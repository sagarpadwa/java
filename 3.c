// Slip 3, Question 1: Program to accept 'n' city names from user and sort them in ascending order

import java.util.Arrays;
import java.util.Scanner;

public class CitySort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of cities: ");
        int n = scanner.nextInt();
        scanner.nextLine();  // Consume the newline character

        String[] cities = new String[n];

        // Accept city names from the user
        for (int i = 0; i < n; i++) {
            System.out.print("Enter city name: ");
            cities[i] = scanner.nextLine();
        }

        // Sort cities in ascending order
        Arrays.sort(cities);

        // Display sorted city names
        System.out.println("Cities in ascending order:");
        for (String city : cities) {
            System.out.println(city);
        }

        scanner.close();
    }
}



// Slip 3, Question 2: Define class Patient and handle exception for oxygen level and HRCT report

class CovidException extends Exception {
    public CovidException(String message) {
        super(message);
    }
}

class Patient {
    String patientName;
    int patientAge;
    int patientOxyLevel;
    int patientHRCTReport;

    // Constructor to initialize patient details
    public Patient(String name, int age, int oxyLevel, int hrctReport) {
        this.patientName = name;
        this.patientAge = age;
        this.patientOxyLevel = oxyLevel;
        this.patientHRCTReport = hrctReport;
    }

    // Method to check patient's condition and throw exception if needed
    public void checkCondition() throws CovidException {
        if (patientOxyLevel < 95 && patientHRCTReport > 10) {
            throw new CovidException("Patient is Covid Positive(+) and Needs to be Hospitalized");
        } else {
            displayInfo();
        }
    }

    // Display patient information
    public void displayInfo() {
        System.out.println("Patient Name: " + patientName);
        System.out.println("Patient Age: " + patientAge);
        System.out.println("Oxygen Level: " + patientOxyLevel + "%");
        System.out.println("HRCT Report: " + patientHRCTReport);
        System.out.println("Patient is Stable.");
    }
}

public class PatientTest {
    public static void main(String[] args) {
        // Creating a sample patient
        Patient patient = new Patient("John Doe", 45, 92, 12);
        
        try {
            patient.checkCondition();
        } catch (CovidException e) {
            System.out.println(e.getMessage());
        }
    }
}
