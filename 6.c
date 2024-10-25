// Slip 6, Question 1: Display Employee information using toString()

class Employee {
    int empId;
    String empName;
    String empDesignation;
    double empSal;

    public Employee(int empId, String empName, String empDesignation, double empSal) {
        this.empId = empId;
        this.empName = empName;
        this.empDesignation = empDesignation;
        this.empSal = empSal;
    }

    @Override
    public String toString() {
        return "Employee [ID: " + empId + ", Name: " + empName + ", Designation: " + empDesignation + ", Salary: " + empSal + "]";
    }
}

public class EmployeeTest {
    public static void main(String[] args) {
        Employee emp = new Employee(101, "John", "Manager", 75000);
        System.out.println(emp.toString());
    }
}


// Slip 6, Question 2: Abstract class 'Order' with PurchaseOrder and SalesOrder subclasses

abstract class Order {
    int id;
    String description;

    public Order(int id, String description) {
        this.id = id;
        this.description = description;
    }

    abstract void accept();

    abstract void display();
}

class PurchaseOrder extends Order {
    String customerName;

    public PurchaseOrder(int id, String description, String customerName) {
        super(id, description);
        this.customerName = customerName;
    }

    @Override
    void accept() {
        System.out.println("Purchase Order accepted from customer: " + customerName);
    }

    @Override
    void display() {
        System.out.println("Purchase Order [ID: " + id + ", Description: " + description + ", Customer Name: " + customerName + "]");
    }
}

class SalesOrder extends Order {
    String vendorName;

    public SalesOrder(int id, String description, String vendorName) {
        super(id, description);
        this.vendorName = vendorName;
    }

    @Override
    void accept() {
        System.out.println("Sales Order accepted from vendor: " + vendorName);
    }

    @Override
    void display() {
        System.out.println("Sales Order [ID: " + id + ", Description: " + description + ", Vendor Name: " + vendorName + "]");
    }
}

public class OrderTest {
    public static void main(String[] args) {
        PurchaseOrder po = new PurchaseOrder(1, "Laptop", "John");
        SalesOrder so = new SalesOrder(2, "Phone", "Apple Inc.");

        po.accept();
        po.display();

        so.accept();
        so.display();
    }
}
