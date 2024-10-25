// Slip 18, Question 1: Program to implement Border Layout Manager

import java.awt.*;
import javax.swing.*;

public class BorderLayoutExample extends JFrame {
    public BorderLayoutExample() {
        setLayout(new BorderLayout());

        add(new JButton("North"), BorderLayout.NORTH);
        add(new JButton("South"), BorderLayout.SOUTH);
        add(new JButton("East"), BorderLayout.EAST);
        add(new JButton("West"), BorderLayout.WEST);
        add(new JButton("Center"), BorderLayout.CENTER);

        setTitle("Border Layout Example");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new BorderLayoutExample();
    }
}


// Slip 18, Question 2: CricketPlayer class to calculate and sort batting averages

class CricketPlayer {
    String name;
    int noOfInnings;
    int noOfTimesNotOut;
    int totalRuns;
    double batAvg;

    public CricketPlayer(String name, int noOfInnings, int noOfTimesNotOut, int totalRuns) {
        this.name = name;
        this.noOfInnings = noOfInnings;
        this.noOfTimesNotOut = noOfTimesNotOut;
        this.totalRuns = totalRuns;
        this.batAvg = avg(noOfInnings, noOfTimesNotOut, totalRuns);
    }

    public static double avg(int innings, int notOut, int runs) {
        return (innings - notOut) == 0 ? runs : (double) runs / (innings - notOut);
    }

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

    public void display() {
        System.out.println("Name: " + name + ", Average: " + batAvg);
    }
}

public class CricketPlayerTest {
    public static void main(String[] args) {
        CricketPlayer[] players = new CricketPlayer[3];
        
        players[0] = new CricketPlayer("Player1", 10, 2, 500);
        players[1] = new CricketPlayer("Player2", 12, 3, 600);
        players[2] = new CricketPlayer("Player3", 15, 4, 700);

        CricketPlayer.sortPlayersByAvg(players);

        System.out.println("Player details sorted by average:");
        for (CricketPlayer player : players) {
            player.display();
        }
    }
}
