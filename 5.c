// Slip 5, Question 1: Multilevel inheritance (Continent -> Country -> State)

class Continent {
    String continentName;

    Continent(String continentName) {
        this.continentName = continentName;
    }
}

class Country extends Continent {
    String countryName;

    Country(String continentName, String countryName) {
        super(continentName);
        this.countryName = countryName;
    }
}

class State extends Country {
    String stateName;

    State(String continentName, String countryName, String stateName) {
        super(continentName, countryName);
        this.stateName = stateName;
    }

    void display() {
        System.out.println("Continent: " + continentName + ", Country: " + countryName + ", State: " + stateName);
    }
}

public class MultilevelInheritance {
    public static void main(String[] args) {
        State s = new State("Asia", "India", "Maharashtra");
        s.display();
    }
}


// Slip 5, Question 2: Menu-driven program for matrix operations

import java.util.Scanner;

public class MatrixOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number of rows and columns for the matrices:");
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();

        int[][] matrix1 = new int[rows][cols];
        int[][] matrix2 = new int[rows][cols];
        int[][] result = new int[rows][cols];

        System.out.println("Enter elements of Matrix 1:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix1[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter elements of Matrix 2:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix2[i][j] = scanner.nextInt();
            }
        }

        while (true) {
            System.out.println("1. Add matrices");
            System.out.println("2. Multiply matrices");
            System.out.println("3. Exit");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    // Matrix Addition
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            result[i][j] = matrix1[i][j] + matrix2[i][j];
                        }
                    }
                    System.out.println("Result of addition:");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            System.out.print(result[i][j] + " ");
                        }
                        System.out.println();
                    }
                    break;
                case 2:
                    // Matrix Multiplication
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            result[i][j] = 0;
                            for (int k = 0; k < cols; k++) {
                                result[i][j] += matrix1[i][k] * matrix2[k][j];
                            }
                        }
                    }
                    System.out.println("Result of multiplication:");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            System.out.print(result[i][j] + " ");
                        }
                        System.out.println();
                    }
                    break;
                case 3:
                    // Exit
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
