package battleship;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void fillField(String[][] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                if (i == 0 && j == 0)
                    field[i][j] = " ";
                else if (i == 0)
                    field[i][j] = Integer.toString(j);
                else if (j == 0)
                    field[i][j] = Character.toString((char)('A' + i - 1));
                else
                    field[i][j] = "~";
            }
        }
    }

    public static void printField(String[][] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                System.out.print(field[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static boolean isInputValid(String[][] field, String input, int cellsCount) {
        String[] coords = input.split(" ");
        int firstCoordA = coords[0].charAt(0) - 64;
        int firstCoordB = Integer.parseInt(coords[0].substring(1, coords[0].length()));
        int secondCoordA = coords[1].charAt(0) - 64;
        int secondCoordB = Integer.parseInt(coords[1].substring(1, coords[1].length()));
        if (firstCoordA != secondCoordA && firstCoordB != secondCoordB) {
            System.out.println("Error! Wrong ship location");
            return false;
        }
        int length = 0;
        if (firstCoordA == secondCoordA) {
            length = Math.abs((int)(firstCoordB - secondCoordB)) + 1;
        } else {
            length = Math.abs((int)(firstCoordA - secondCoordA)) + 1;
        }
        if (length != cellsCount) {
            System.out.println("Error! Wrong ship length = " + length);
            return false;
        }
        if (firstCoordA > secondCoordA) {
            int temp = firstCoordA;
            firstCoordA = secondCoordA;
            secondCoordA = temp;
        }
        if (firstCoordB > secondCoordB) {
            int temp = firstCoordB;
            firstCoordB = secondCoordB;
            secondCoordB = temp;
        }
        for (int i = firstCoordA - 1; i <= secondCoordA + 1 && i <= 10; i++) {
            if (i < 1)
                i = 1;
            for (int j = firstCoordB - 1; j <= secondCoordB + 1 && j <= 10; j++) {
                if (j < 1)
                    j = 1;
                if (field[i][j].equals("O")) {
                    System.out.println("Error! Too close to another ship");
                    return false;
                }
            }
        }
        for (int i = firstCoordA; i <= secondCoordA; i++) {
            for (int j = firstCoordB; j <= secondCoordB; j++) {
                //System.out.printf("i = %d j = %d\n",i, j);
                field[i][j] = "O";
            }
        }
        return true;
    }

    public static void shoot(String[][] field, String[][] fieldFogOfWar) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Take a shot!");
        boolean isCorrectInput = false;
        int firstCoordA;
        int firstCoordB;
        String input = "";
        do {
            input = scanner.nextLine();
            firstCoordA = input.charAt(0) - 64;
            firstCoordB = Integer.parseInt(input.substring(1, input.length()));
            if (firstCoordA < 1 || firstCoordA > 10 || firstCoordB < 1 || firstCoordB > 10)
                System.out.println("Error! Wrong input. Try again");
            else
                isCorrectInput = true;
        } while (!isCorrectInput);
        if (field[firstCoordA][firstCoordB] == "~") {
            field[firstCoordA][firstCoordB] = "M";
            fieldFogOfWar[firstCoordA][firstCoordB] = "M";
            printField(fieldFogOfWar);
            System.out.println("You missed. Try again:");

        } else {
            field[firstCoordA][firstCoordB] = "X";
            fieldFogOfWar[firstCoordA][firstCoordB] = "X";
            printField(fieldFogOfWar);
            if (isShipSank(firstCoordA, firstCoordB, field)) {
                System.out.println("You sank a ship! Specify a new target:");
            } else {
                System.out.println("You hit a ship! Try again:");
            }
        }
    }

    public static boolean isShipSank(int coordA, int coordB, String[][] field) {
        for (int i = coordA; i < coordA + 2; i++) {
            for (int j = coordB; j < coordB + 2; j++) {
                if (i < 10 && j < 10) {
                    if (field[i][j] == "O")
                        return (false);
                }
            }
        }
        return (true);
    }

    public static boolean isGameEnded(String[][] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                if (field[i][j] == "O")
                    return (false);
            }
        }
        return (true);
    }

    public static void fillFieldByPlayer(String[][] field) {
        Scanner scanner = new Scanner(System.in);
        String input = "";
        boolean isValid;

        System.out.println("Enter the coordinates of the Aircraft Carrier (5 cells):");
        do {
            input = scanner.nextLine();
            isValid = isInputValid(field, input, 5);
        } while (!isValid);
        printField(field);
        System.out.println("Enter the coordinates of the Battleship (4 cells):");
        do {
            input = scanner.nextLine();
            isValid = isInputValid(field, input, 4);
        } while (!isValid);
        printField(field);
        System.out.println("Enter the coordinates of the Submarine (3 cells):");
        do {
            input = scanner.nextLine();
            isValid = isInputValid(field, input, 3);
        } while (!isValid);
        printField(field);
        System.out.println("Enter the coordinates of the Cruiser (3 cells):");
        do {
            input = scanner.nextLine();
            isValid = isInputValid(field, input, 3);
        } while (!isValid);
        printField(field);
        System.out.println("Enter the coordinates of the Destroyer (2 cells):");
        do {
            input = scanner.nextLine();
            isValid = isInputValid(field, input, 2);
        } while (!isValid);
        printField(field);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = "";
        String[][] fieldPlayer1 = new String[11][11];
        String[][] fieldPlayer2 = new String[11][11];
        String[][] fieldFogOfWar1 = new String[11][11];
        String[][] fieldFogOfWar2 = new String[11][11];


        fillField(fieldPlayer1);
        fillField(fieldPlayer2);
        fillField(fieldFogOfWar1);
        fillField(fieldFogOfWar2);
        System.out.println("Player 1, place your ships on the game field");
        printField(fieldPlayer1);
        fillFieldByPlayer(fieldPlayer1);
        System.out.println("Press Enter and pass the move to another player");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Player 2, place your ships on the game field");
        printField(fieldPlayer2);
        fillFieldByPlayer(fieldPlayer2);
        System.out.println("Press Enter and pass the move to another player");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
        int counter = 0;
        while (true) {
            if (counter % 2 == 0) {
                printField(fieldFogOfWar2);
                System.out.println("---------------------");
                printField(fieldPlayer1);
                System.out.println("Player 1, it's your turn:");
                shoot(fieldPlayer2, fieldFogOfWar2);
                if (isGameEnded(fieldPlayer2))
                    break;
                System.out.println("Press Enter and pass the move to another player");
                try {
                    System.in.read();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                printField(fieldFogOfWar1);
                System.out.println("---------------------");
                printField(fieldPlayer2);
                System.out.println("Player 2, it's your turn:");
                shoot(fieldPlayer1, fieldFogOfWar1);
                if (isGameEnded(fieldPlayer1))
                    break;
                System.out.println("Press Enter and pass the move to another player");
                try {
                    System.in.read();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            counter++;
        }
        System.out.println("You sank the last ship. You won. Congratulations!");
    }
}
