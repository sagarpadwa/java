class Item {
    // Instance variables
    int item_number;
    String item_name;
    double item_price;

    // Static variable to keep track of the number of objects created
    static int objectCount = 0;

    // Default constructor
    public Item() {
        this.item_number = 0;
        this.item_name = "No Name";
        this.item_price = 0.0;
        objectCount++;
    }

    // Parameterized constructor
    public Item(int item_number, String item_name, double item_price) {
        this.item_number = item_number;
        this.item_name = item_name;
        this.item_price = item_price;
        objectCount++;
    }

    // Static method to display object count
    public static void displayObjectCount() {
        System.out.println("Total number of objects created: " + objectCount);
    }

    // Method to display item details
    public void displayItemDetails() {
        System.out.println("Item Number: " + item_number);
        System.out.println("Item Name: " + item_name);
        System.out.println("Item Price: " + item_price);
    }

    public static void main(String[] args) {
        // Creating objects using parameterized constructor
        Item item1 = new Item(101, "Laptop", 45000.50);
        item1.displayItemDetails();
        Item.displayObjectCount();  // Displaying object count

        System.out.println();

        Item item2 = new Item(102, "Smartphone", 25000.75);
        item2.displayItemDetails();
        Item.displayObjectCount();  // Displaying object count
    }
}


import java.io.*;
import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;
import java.util.Scanner;

class Donor implements Serializable {
    String name;
    int age;
    String address;
    String contactNumber;
    String bloodGroup;
    LocalDate lastDonationDate;

    // Constructor
    public Donor(String name, int age, String address, String contactNumber, String bloodGroup, LocalDate lastDonationDate) {
        this.name = name;
        this.age = age;
        this.address = address;
        this.contactNumber = contactNumber;
        this.bloodGroup = bloodGroup;
        this.lastDonationDate = lastDonationDate;
    }

    // Method to check if the donor has not donated in the last 6 months
    public boolean isEligibleForDonation() {
        LocalDate currentDate = LocalDate.now();
        Period period = Period.between(lastDonationDate, currentDate);
        return period.getMonths() >= 6;
    }

    // Method to display donor details
    public void displayDonorDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
        System.out.println("Contact Number: " + contactNumber);
        System.out.println("Blood Group: " + bloodGroup);
        System.out.println("Last Donation Date: " + lastDonationDate);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Donor> donors = new ArrayList<>();

        System.out.print("Enter the number of donors: ");
        int n = scanner.nextInt();
        scanner.nextLine();  // Consume newline

        // Input donor details
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for Donor " + (i + 1));

            System.out.print("Name: ");
            String name = scanner.nextLine();

            System.out.print("Age: ");
            int age = scanner.nextInt();
            scanner.nextLine();  // Consume newline

            System.out.print("Address: ");
            String address = scanner.nextLine();

            System.out.print("Contact Number: ");
            String contactNumber = scanner.nextLine();

            System.out.print("Blood Group: ");
            String bloodGroup = scanner.nextLine();

            System.out.print("Date of Last Donation (yyyy-mm-dd): ");
            LocalDate lastDonationDate = LocalDate.parse(scanner.nextLine());

            // Creating a donor object and adding to the list
            donors.add(new Donor(name, age, address, contactNumber, bloodGroup, lastDonationDate));
        }

        // Writing donor objects to a file
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("donors.dat"))) {
            oos.writeObject(donors);
            System.out.println("Donor details written to file.");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Reading donor objects from file and filtering based on blood group and donation time
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("donors.dat"))) {
            ArrayList<Donor> readDonors = (ArrayList<Donor>) ois.readObject();
            System.out.println("\nDonors with blood group 'A+ve' who have not donated in the last 6 months:");

            for (Donor donor : readDonors) {
                if (donor.bloodGroup.equals("A+ve") && donor.isEligibleForDonation()) {
                    donor.displayDonorDetails();
                    System.out.println();
                }
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        scanner.close();
    }
}
