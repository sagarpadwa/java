// Slip 13, Question 1: Program to accept a file name, display number of words and lines

import java.io.*;

public class FileWordLineCount {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java FileWordLineCount <file_name>");
            return;
        }

        String fileName = args[0];
        int lineCount = 0, wordCount = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lineCount++;
                wordCount += line.split("\\s+").length;  // Split by spaces to get words
            }
            System.out.println("Number of Lines: " + lineCount);
            System.out.println("Number of Words: " + wordCount);
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}


// Slip 13, Question 2: Display system date and time in various formats

import java.text.SimpleDateFormat;
import java.util.Date;

public class DateTimeFormats {
    public static void main(String[] args) {
        Date date = new Date();

        SimpleDateFormat format1 = new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat format2 = new SimpleDateFormat("MM-dd-yyyy");
        SimpleDateFormat format3 = new SimpleDateFormat("EEEE MMMM dd yyyy");
        SimpleDateFormat format4 = new SimpleDateFormat("EEE MMM dd HH:mm:ss z yyyy");
        SimpleDateFormat format5 = new SimpleDateFormat("dd/MM/yy HH:mm:ss a Z");

        System.out.println("Current date is: " + format1.format(date));
        System.out.println("Current date is: " + format2.format(date));
        System.out.println("Current date is: " + format3.format(date));
        System.out.println("Current date and time is: " + format4.format(date));
        System.out.println("Current date and time is: " + format5.format(date));
    }
}
