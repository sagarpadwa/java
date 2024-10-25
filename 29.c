import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Q1) Write a program to create a class Customer(custno,custname,contactnumber,custaddr).
// Write a method to search the customer name with given contact number and display the details.

class Customer {
    private int custNo;
    private String custName;
    private String contactNumber;
    private String custAddr;

    public Customer(int custNo, String custName, String contactNumber, String custAddr) {
        this.custNo = custNo;
        this.custName = custName;
        this.contactNumber = contactNumber;
        this.custAddr = custAddr;
    }

    public String getContactNumber() {
        return contactNumber;
    }

    public void displayDetails() {
        System.out.println("Customer Number: " + custNo);
        System.out.println("Customer Name: " + custName);
        System.out.println("Contact Number: " + contactNumber);
        System.out.println("Customer Address: " + custAddr);
    }
}

public class CustomerSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Customer> customers = new ArrayList<>();

        // Adding sample customers
        customers.add(new Customer(1, "Alice Smith", "1234567890", "123 Elm Street"));
        customers.add(new Customer(2, "Bob Johnson", "0987654321", "456 Oak Avenue"));
        customers.add(new Customer(3, "Charlie Brown", "1112223333", "789 Pine Road"));

        System.out.print("Enter contact number to search: ");
        String contactNumber = scanner.nextLine();
        
        boolean found = false;
        for (Customer customer : customers) {
            if (customer.getContactNumber().equals(contactNumber)) {
                customer.displayDetails();
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Customer with contact number " + contactNumber + " not found.");
        }

        scanner.close();
    }
}



import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Q2) Write a program to create a super class Vehicle having members Company and price.
// Derive two different classes LightMotorVehicle(mileage) and HeavyMotorVehicle (capacity_in_tons).
// Accept the information for "n" vehicles and display the information in appropriate form.

class Vehicle {
    protected String company;
    protected double price;

    public Vehicle(String company, double price) {
        this.company = company;
        this.price = price;
    }

    public void displayInfo() {
        System.out.println("Company: " + company);
        System.out.println("Price: Rs." + price);
    }
}

class LightMotorVehicle extends Vehicle {
    private double mileage;

    public LightMotorVehicle(String company, double price, double mileage) {
        super(company, price);
        this.mileage = mileage;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Mileage: " + mileage + " km/l");
    }
}

class HeavyMotorVehicle extends Vehicle {
    private double capacityInTons;

    public HeavyMotorVehicle(String company, double price, double capacityInTons) {
        super(company, price);
        this.capacityInTons = capacityInTons;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Capacity: " + capacityInTons + " tons");
    }
}

public class VehicleInformation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Vehicle> vehicles = new ArrayList<>();

        System.out.print("Enter the number of vehicles: ");
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < n; i++) {
            System.out.print("Enter vehicle type (1 for Light Motor Vehicle, 2 for Heavy Motor Vehicle): ");
            int vehicleType = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            System.out.print("Enter company name: ");
            String company = scanner.nextLine();
            System.out.print("Enter price: ");
            double price = scanner.nextDouble();

            if (vehicleType == 1) {
                System.out.print("Enter mileage: ");
                double mileage = scanner.nextDouble();
                vehicles.add(new LightMotorVehicle(company, price, mileage));
            } else if (vehicleType == 2) {
                System.out.print("Enter capacity in tons: ");
                double capacity = scanner.nextDouble();
                vehicles.add(new HeavyMotorVehicle(company, price, capacity));
            } else {
                System.out.println("Invalid vehicle type entered.");
            }
            scanner.nextLine(); // Consume newline
        }

        System.out.println("\nVehicle Information:");
        for (Vehicle vehicle : vehicles) {
            vehicle.displayInfo();
            System.out.println("---------------------------");
        }

        scanner.close();
    }
}
