// Slip 9, Question 1: Clock class to handle time in AM/PM mode

class Clock {
    private int hours;
    private int minutes;
    private int seconds;
    private String amPm;

    // Constructor
    public Clock(int hours, int minutes, int seconds) {
        if (isValidTime(hours, minutes, seconds)) {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
        } else {
            System.out.println("Invalid time!");
        }
    }

    // Method to check validity of time
    public boolean isValidTime(int hours, int minutes, int seconds) {
        return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
    }

    // Method to set time in AM/PM format
    public void setTimeInAmPm() {
        if (hours >= 12) {
            amPm = "PM";
            if (hours > 12) hours -= 12;
        } else {
            amPm = "AM";
            if (hours == 0) hours = 12;
        }
    }

    public void displayTime() {
        System.out.println("Time: " + hours + ":" + minutes + ":" + seconds + " " + amPm);
    }

    public static void main(String[] args) {
        Clock clock = new Clock(15, 30, 45);
        clock.setTimeInAmPm();
        clock.displayTime();
    }
}


// Slip 9, Question 2: Marker interface for Product and object count

interface MarkerInterface {}

class Product implements MarkerInterface {
    private int productId;
    private String productName;
    private double productCost;
    private int productQuantity;
    private static int objectCount = 0;

    // Constructor
    public Product(int productId, String productName, double productCost, int productQuantity) {
        this.productId = productId;
        this.productName = productName;
        this.productCost = productCost;
        this.productQuantity = productQuantity;
        objectCount++;
    }

    // Method to display product details
    public void display() {
        System.out.println("Product ID: " + productId + ", Name: " + productName + ", Cost: " + productCost + ", Quantity: " + productQuantity);
    }

    public static int getObjectCount() {
        return objectCount;
    }

    public static void main(String[] args) {
        Product p1 = new Product(1, "Laptop", 50000, 10);
        Product p2 = new Product(2, "Phone", 30000, 5);
        
        p1.display();
        p2.display();

        System.out.println("Total objects created: " + Product.getObjectCount());
    }
}
