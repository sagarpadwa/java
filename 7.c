// Slip 7, Question 1: Bank class supporting deposit, withdraw, and balance check

class Bank {
    private String accountHolder;
    private double balance;

    // Constructor to initialize account
    public Bank(String accountHolder, double balance) {
        this.accountHolder = accountHolder;
        this.balance = balance;
    }

    // Method to deposit money
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Deposit amount should be positive.");
        }
    }

    // Method to withdraw money
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrew: " + amount);
        } else {
            System.out.println("Invalid withdrawal amount.");
        }
    }

    // Method to return current balance
    public void getBalance() {
        System.out.println("Current balance: " + balance);
    }
}

public class BankTest {
    public static void main(String[] args) {
        Bank account = new Bank("Alice", 1000.00);

        account.deposit(500);
        account.withdraw(300);
        account.getBalance();
    }
}


// Slip 7, Question 2: Display file contents in reverse order and change its case

import java.io.*;

public class FileReverseCase {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java FileReverseCase <file_name>");
            return;
        }

        String fileName = args[0];

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            StringBuilder content = new StringBuilder();
            String line;

            // Read file content
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }

            // Reverse content and change case
            content.reverse();
            String reversedContent = content.toString();
            String changedCaseContent = switchCase(reversedContent);

            System.out.println("Reversed and Case Changed Content:\n" + changedCaseContent);

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    // Helper method to change case of characters
    public static String switchCase(String str) {
        StringBuilder result = new StringBuilder();
        for (char ch : str.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                result.append(Character.toLowerCase(ch));
            } else {
                result.append(Character.toUpperCase(ch));
            }
        }
        return result.toString();
    }
}
