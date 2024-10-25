// Slip 15, Question 1: Program to copy contents from one file to another

import java.io.*;

public class FileCopy {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java FileCopy <source_file> <destination_file>");
            return;
        }

        String sourceFile = args[0];
        String destinationFile = args[1];

        try (BufferedReader reader = new BufferedReader(new FileReader(sourceFile));
             BufferedWriter writer = new BufferedWriter(new FileWriter(destinationFile))) {

            String line;
            while ((line = reader.readLine()) != null) {
                writer.write(line);
                writer.newLine();
            }

            System.out.println("File copied successfully!");

        } catch (IOException e) {
            System.out.println("Error occurred: " + e.getMessage());
        }
    }
}


// Slip 15, Question 2: Class Account, SavingAccount, and AccountDetail

class Account {
    String custName;
    int accNo;

    public Account(String custName, int accNo) {
        this.custName = custName;
        this.accNo = accNo;
    }

    public void display() {
        System.out.println("Customer Name: " + custName + ", Account No: " + accNo);
    }
}

class SavingAccount extends Account {
    double savingBal;
    double minBal;

    public SavingAccount(String custName, int accNo, double savingBal, double minBal) {
        super(custName, accNo);
        this.savingBal = savingBal;
        this.minBal = minBal;
    }
}

class AccountDetail extends SavingAccount {
    double depositAmt;
    double withdrawalAmt;

    public AccountDetail(String custName, int accNo, double savingBal, double minBal, double depositAmt, double withdrawalAmt) {
        super(custName, accNo, savingBal, minBal);
        this.depositAmt = depositAmt;
        this.withdrawalAmt = withdrawalAmt;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Saving Balance: " + savingBal + ", Minimum Balance: " + minBal);
        System.out.println("Deposit Amount: " + depositAmt + ", Withdrawal Amount: " + withdrawalAmt);
    }

    public static void main(String[] args) {
        AccountDetail accDetail = new AccountDetail("John Doe", 12345, 10000.0, 2000.0, 5000.0, 1000.0);
        accDetail.display();
    }
}
