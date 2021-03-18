package com.company;

import java.util.Scanner;

public class Main {

	//Поиск первого вхождения числа в строку
	public static int findFirstNumberIndex(String input) {
		for (int i = 0; i < input.length(); i++) {
			if (Character.isDigit(input.charAt(i)))
				return (i);
		}
		return (-1);
	}

	//Нахождения индекса закрывающей скобочки конкретной упакованной подстрочки
	public static int findCloseBracketIndex(String input, int startIndex) {
		int openBracketsCount = 0;
		int closeBracketsCount = 0;

		for (int i = startIndex; i < input.length(); i++) {
			if (input.charAt(i) == '[')
				openBracketsCount++;
			else if (input.charAt(i) == ']')
				closeBracketsCount++;
			if (openBracketsCount > 0 && closeBracketsCount > 0 && openBracketsCount == closeBracketsCount)
				return (i);
		}
		return (0);
	}

	//Перевод числа перед скобками в инт
	public static int calculateNumberOfIterations(String input, int startIndex) {
		String strNumber = "";
		int i = startIndex;

		while (Character.isDigit(input.charAt(i))) {
			strNumber += input.charAt(i);
			i++;
		}
		return (Integer.parseInt(strNumber));
	}

	//Расчёт смещения на случай, если число имеет больше одного разряда
	public static int calculateStartShift(String input, int startIndex) {
		int i = startIndex;
		int counter = 0;

		while (Character.isDigit(input.charAt(i))) {
			i++;
			counter++;
		}
		return (counter);
	}

	//Функция распаковки строки
	public static String unpackString(String input) {
		int startIndex = 0;
		int endIndex = 0;
		int iterationsCount = 0;
		int startShift = 0;
		String tempString = "";

		while ((startIndex = findFirstNumberIndex(input)) >= 0) {
			tempString = "";
			iterationsCount = calculateNumberOfIterations(input, startIndex);
			startShift = calculateStartShift(input, startIndex);
			endIndex = findCloseBracketIndex(input, startIndex);
			for (int i = 0; i < iterationsCount; i++) {
				tempString += input.substring(startIndex + startShift + 1, endIndex);
			}
			input = input.substring(0, startIndex) + tempString + input.substring(endIndex + 1);
		}
		return (input);
	}

    public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(unpackString(input));
    }
}
