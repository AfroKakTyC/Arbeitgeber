//Now your menu should look like this:
//
//        1. Show the seats
//        2. Buy a ticket
//        3. Statistics
//        0. Exit
//        When the item Statistics is chosen, your program should print the following information:
//
//        The number of purchased tickets;
//        The number of purchased tickets represented as a percentage. Percentages should be rounded to 2 decimal places;
//        Current income;
//        The total income that shows how much money the theatre will get if all the tickets are sold.
//        The rest of the menu items should work the same way as before, except the item Buy a ticket
//        shouldn't allow a user to buy a ticket that has already been purchased.
//
//        If a user chooses an already taken seat, print That ticket has already been purchased! and ask
//        them to enter different seat coordinates until they pick an available seat. Of course, you
//        shouldn't allow coordinates that are out of bounds. If this happens, print Wrong input!
//        and ask to enter different seat coordinates until the user picks an available seat.


package cinema;

import java.util.Scanner;

class Statistics {
    public int ticketsCount = 0;
    public double ticketsBuyPercent = 0;
    public int currentIncome = 0;
    public int totalIncome = 0;
}

public class Cinema {

    public static String[][] createCinema(int rows, int seats)
    {
        String[][] cinema = new String[rows + 1][seats + 1];
        for (int i = 0; i < cinema.length; i++)
        {
            for (int j = 0; j < cinema[i].length; j++)
            {
                if (j == 0 && i == 0) {
                    cinema[i][j] = " ";
                }
                else if (j > 0 && i == 0) {
                    cinema[i][j] = " " + j;
                }
                else if (j == 0) {
                    cinema[i][j] = Integer.toString(i);
                }
                else cinema[i][j] = " S";
            }
        }
        return cinema;
    }


    public static void showCinema(String[][] cinema)
    {
        System.out.println("Cinema:");
        for (int i = 0; i < cinema.length; i++)
        {
            for (int j = 0; j < cinema[i].length; j++)
            {
                System.out.print(cinema[i][j]);
            }
            System.out.println();
        }
    }

    public static void buyTicket(String[][] cinema, Statistics statistics) {
        Scanner scanner = new Scanner(System.in);
        boolean isIncorrectInput = true;
        int row = 0;
        int seat = 0;
        while (isIncorrectInput) {
            System.out.println("Enter a row number:");
            row = scanner.nextInt();
            System.out.println("Enter a seat number in that row:");
            seat = scanner.nextInt();
            if ((row < 1 || row > cinema.length - 1) || (seat < 1 || seat > cinema[0].length - 1))
                System.out.println("Wrong input!");
            else if (cinema[row][seat].equals(" B"))
                System.out.println("That ticket has already been purchased!");
            else
                isIncorrectInput = false;
        }
        int result = 0;
        if ((cinema.length - 1) * (cinema[0].length - 1) <= 60)
            result = 10;
        else {
            int halfHall = (cinema.length - 1) / 2;
            if (row <= halfHall)
                result = 10;
            else
                result = 8;
        }
        System.out.print("Ticket price: ");
        System.out.println("$" + result);
        statistics.currentIncome += result;
        statistics.ticketsCount++;
        cinema[row][seat] = " B";
    }

    public static void showStatistics(String[][] cinema, Statistics statistics)
    {
        double totalSeats = (cinema.length - 1) * (cinema[0].length - 1);
        double ticketsCountDouble = statistics.ticketsCount;
        if (statistics.ticketsCount == 0)
            statistics.ticketsBuyPercent = 0;
        else
            statistics.ticketsBuyPercent = (ticketsCountDouble / totalSeats) * 100;
        System.out.println("Number of purchased tickets: " + statistics.ticketsCount);
        System.out.printf("Percentage: %.2f%%\n", statistics.ticketsBuyPercent);
        System.out.println("Current income: $" + statistics.currentIncome);
        System.out.println("Total income: $" + statistics.totalIncome);
    }

    public static void menu(String[][] cinema, Statistics statistics)
    {
        Scanner scanner = new Scanner(System.in);
        boolean isNotExit = true;
        while (isNotExit) {
            System.out.println("1.Show the seats\n2. Buy a ticket\n3. Statistics\n0. Exit");
            int choise = scanner.nextInt();
            if (choise == 1) {
                showCinema(cinema);
            } else if (choise == 2) {
                buyTicket(cinema, statistics);
            } else if (choise == 3) {
                showStatistics(cinema, statistics);
            } else if (choise == 0) {
                isNotExit = false;
            }
        }
    }

    public static void countTotalIncome(String[][] cinema, Statistics statistics) {
        int result = 0;
        if ((cinema.length - 1) * (cinema[0].length - 1) <= 60)
            result = (cinema.length - 1) * (cinema[0].length - 1) * 10;
        else {
            int halfHall = (cinema.length - 1) / 2;
            result = halfHall * (cinema[0].length - 1) * 10;
            result += (cinema.length - 1 - halfHall) * (cinema[0].length - 1) * 8;
        }
        statistics.totalIncome = result;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of rows:");
        int rows = scanner.nextInt();
        System.out.println("Enter the number of seats in each row:");
        int seats = scanner.nextInt();
        String[][] cinema = createCinema(rows, seats);
        Statistics statistics = new Statistics();
        countTotalIncome(cinema, statistics);
        menu(cinema, statistics);

    }
}