//Extend your program by adding different algorithms to encode/decode data. The first one would be shifting algorithm
//		(it shifts each letter by the specified number according to its order in the alphabet in circle).
//		The second one would be based on Unicode table, like in the previous stage.
//
//		When starting the program, the necessary algorithm should be specified by an argument (-alg).
//		The first algorithm should be named shift, the second one should be named unicode. If there is no -alg you should default it to shift.
//
//		Remember that in case of shift algorithm you need to encode only English letters
//		(from 'a' to 'z' as the first circle and from 'A' to 'Z' as the second circle i.e. after 'z' comes 'a' and after 'Z' comes 'A')

package encryptdecrypt;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

public class Main {
	public static String encription(String input, int key, String mode)
	{
		String output = "";
		if (mode.equals("unicode")) {
			for (int i = 0; i < input.length(); i++) {
				char ch = input.charAt(i);
				ch = (char) (ch + key);
				output += ch;
			}
		} else {
			for (int i = 0; i < input.length(); i++) {
				char ch = input.charAt(i);
				boolean isLower = false;
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
					if (ch >= 'a' && ch <= 'z')
						isLower = true;
					ch = (char) (ch + key);
					if (isLower) {
						if (ch > 'z') {
							ch = (char) (ch - 'z' - 1 + 'a');
						}
					} else {
						if (ch > 'Z') {
							ch = (char) (ch - 'Z' - 1 + 'A');
						}
					}

				}
				output += ch;
			}
		}
		return (output);
	}

	public static String decription(String input, int key, String mode)
	{
		String output = "";
		if (mode.equals("unicode")) {
			for (int i = 0; i < input.length(); i++) {
				char ch = input.charAt(i);
				ch = (char) (ch - key);
				output += ch;
			}
		} else {
			for (int i = 0; i < input.length(); i++) {
				char ch = input.charAt(i);
				boolean isLower = false;
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
					if (ch >= 'a' && ch <= 'z')
						isLower = true;
					ch = (char) (ch - key);
					if (isLower) {
						if (ch < 'a') {
							ch = (char) ('z' - ('a' - ch - 1));
						}
					} else {
						if (ch < 'A') {
							ch = (char) ('Z' - ('A' - ch - 1));
						}
					}

				}
				output += ch;
			}
		}
		return (output);
	}

	public static String readFromFile(String filePath)
	{
		File file = new File(filePath);
		String result = "";
		try (Scanner scanner = new Scanner(file)) {
			result = scanner.nextLine();
		} catch (FileNotFoundException e) {
			System.out.println("Error: file not found.");
		}
		return (result);
	}

	public static void writeData(String data)
	{
		System.out.println(data);
	}

	public static void writeData(String data, String fileToWritePath)
	{
		File file = new File(fileToWritePath);
		try (FileWriter writer = new FileWriter(file)) {
			writer.write(data);
		} catch (IOException e) {
			System.out.printf("An exception occurs %s", e.getMessage());
		}
	}

	public static void main(String[] args) {

		String mode = "enc";
		int key = 0;
		String data = "";
		int index = 0;
		String pathToOutputFile = "";
		String result = "";
		String algorithm = "";

		if ((index = Arrays.asList(args).indexOf("-mode")) >= 0)
			mode = args[index + 1];
		if ((index = Arrays.asList(args).indexOf("-key")) >= 0)
			key = Integer.parseInt(args[index + 1]);
		if (Arrays.asList(args).indexOf("-data") >= 0 && Arrays.asList(args).indexOf("-in") >= 0)
			data = args[Arrays.asList(args).indexOf("-data") + 1];
		else if ((index = Arrays.asList(args).indexOf("-data")) >= 0)
			data = args[index + 1];
		else if ((index = Arrays.asList(args).indexOf("-in")) >= 0)
			data = readFromFile(args[index + 1]);
		if ((index = Arrays.asList(args).indexOf("-out")) >= 0)
			pathToOutputFile = args[index + 1];
		if ((index = Arrays.asList(args).indexOf("-alg")) >= 0)
			algorithm = args[index + 1];
		if (mode.equals("enc"))
			result = encription(data, key, algorithm);
		else
			result = decription(data, key, algorithm);
		if (pathToOutputFile.equals(""))
			writeData(result);
		else
			writeData(result, pathToOutputFile);
	}
}
