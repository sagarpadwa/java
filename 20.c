// Q1) Write a Program to illustrate multilevel Inheritance such that country is inherited from
// continent. State is inherited from country. Display the place, state, country and continent.

// Base class
class Continent {
    String continentName;

    Continent(String continentName) {
        this.continentName = continentName;
    }
}

// Derived class
class Country extends Continent {
    String countryName;

    Country(String continentName, String countryName) {
        super(continentName);
        this.countryName = countryName;
    }
}

// Derived class
class State extends Country {
    String stateName;

    State(String continentName, String countryName, String stateName) {
        super(continentName, countryName);
        this.stateName = stateName;
    }

    // Method to display details
    void displayDetails() {
        System.out.println("Continent: " + continentName);
        System.out.println("Country: " + countryName);
        System.out.println("State: " + stateName);
    }
}

// Main class
public class MultilevelInheritance {
    public static void main(String[] args) {
        // Create an object of the State class
        State state = new State("North America", "United States", "California");
        
        // Display details
        state.displayDetails();
    }
}


// Q2) Write a package for Operation, which has two classes, Addition and Maximum. 
// Addition has two methods add () and subtract (), which are used to add two integers 
// and subtract two float values respectively. Maximum has a method max () to display the maximum of two integers.

package Operation;

public class Addition {
    // Method to add two integers
    public int add(int a, int b) {
        return a + b;
    }

    // Method to subtract two float values
    public float subtract(float a, float b) {
        return a - b;
    }
}

package Operation;

public class Maximum {
    // Method to find maximum of two integers
    public int max(int a, int b) {
        return (a > b) ? a : b;
    }
}

// Main class to test the package
import Operation.Addition;
import Operation.Maximum;

public class Main {
    public static void main(String[] args) {
        // Create objects of the classes
        Addition addition = new Addition();
        Maximum maximum = new Maximum();

        // Test addition
        int sum = addition.add(5, 10);
        float difference = addition.subtract(15.5f, 10.0f);
        System.out.println("Sum of 5 and 10: " + sum);
        System.out.println("Difference of 15.5 and 10.0: " + difference);

        // Test maximum
        int maxVal = maximum.max(20, 15);
        System.out.println("Maximum of 20 and 15: " + maxVal);
    }
}


