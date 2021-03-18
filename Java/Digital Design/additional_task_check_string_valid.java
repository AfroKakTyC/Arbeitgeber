package com.company;

import java.util.Scanner;

public class Main {

    public static boolean isStringValid(String input)
    {
        int openBracketsCount = 0;
        int closeBracketsCount = 0;
        for (int i = 0; i < input.length(); i++) {
            if (!((input.charAt(i) >= '0' && input.charAt(i) <= '9') || (input.charAt(i) >= 'A' && input.charAt(i) <= 'Z')
                || (input.charAt(i) >= 'a' && input.charAt(i) <= 'z') || (input.charAt(i) == '[') || (input.charAt(i) == ']'))) //Проверка на допустимые символы
                return (false);
            else if (input.charAt(i) >= '0' && input.charAt(i) <= '9') {
                if (i == input.length() - 1 || input.charAt(i + 1) != '[' || Character.isDigit(input.charAt(i + 1))) { //Проверка на правильность установки чисел
                        return (false);
                }
            }
            else if (input.charAt(i) == '[') {
                openBracketsCount++;
                if (i == 0 || !Character.isDigit(input.charAt(i - 1))) //Проверка на правильность установки открывающих скобок
                    return (false);
            }
            else if (input.charAt(i) == ']') {
                closeBracketsCount++;
            }
            if (closeBracketsCount > openBracketsCount) //Проверка на правильность установки закрывающих скобок
                return (false);
        }
        if (openBracketsCount != closeBracketsCount) //Проверка на количество скобок
            return (false);
        return (true);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(isStringValid(input));
    }
}
