// Slip 2, Question 1: Program to calculate BMI using command line arguments

public class BMICalculator {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Usage: java BMICalculator <FirstName> <LastName> <WeightInKg> <HeightInMeters>");
            return;
        }

        String firstName = args[0];
        String lastName = args[1];
        double weight = Double.parseDouble(args[2]);
        double height = Double.parseDouble(args[3]);

        double bmi = weight / (height * height);

        System.out.println("BMI for " + firstName + " " + lastName + " is: " + bmi);
    }
}



// Slip 2, Question 2: Define class CricketPlayer and calculate batting average using static methods

class CricketPlayer {
    String name;
    int noOfInnings;
    int noOfTimesNotOut;
    int totalRuns;
    double batAvg;

    // Constructor
    public CricketPlayer(String name, int noOfInnings, int noOfTimesNotOut, int totalRuns) {
        this.name = name;
        this.noOfInnings = noOfInnings;
        this.noOfTimesNotOut = noOfTimesNotOut;
        this.totalRuns = totalRuns;
        this.batAvg = avg(noOfInnings, noOfTimesNotOut, totalRuns);
    }

    // Static method to calculate average
    public static double avg(int innings, int notOut, int runs) {
        return (innings - notOut) == 0 ? runs : (double) runs / (innings - notOut);
    }

    // Static method to sort players by batting average
    public static void sortPlayersByAvg(CricketPlayer[] players) {
        for (int i = 0; i < players.length - 1; i++) {
            for (int j = i + 1; j < players.length; j++) {
                if (players[i].batAvg < players[j].batAvg) {
                    CricketPlayer temp = players[i];
                    players[i] = players[j];
                    players[j] = temp;
                }
            }
        }
    }

    // Display player details
    public void display() {
        System.out.println("Name: " + name + ", Average: " + batAvg);
    }
}

public class CricketPlayerTest {
    public static void main(String[] args) {
        CricketPlayer[] players = new CricketPlayer[3];
        
        // Creating player objects
        players[0] = new CricketPlayer("Player1", 10, 2, 500);
        players[1] = new CricketPlayer("Player2", 12, 3, 600);
        players[2] = new CricketPlayer("Player3", 15, 4, 700);

        // Sort by average
        CricketPlayer.sortPlayersByAvg(players);

        // Display player details
        System.out.println("Player details sorted by average:");
        for (CricketPlayer player : players) {
            player.display();
        }
    }
}
