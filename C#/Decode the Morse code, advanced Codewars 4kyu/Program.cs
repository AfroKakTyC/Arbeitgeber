using System;
using System.Collections.Generic;

namespace Decode_the_Morse_code__advanced_Codewars_4kyu
{
	class Program
	{
		//Определить минимальный размер единицы измерения темпа
		public static int DefineRate(string bits)
		{
			int counter = 0;
			int rate = 100000;
			int i = 0;
			while (i < bits.Length)
			{
				counter = 0;
				while (i < bits.Length && bits[i] == '1')
				{
					counter++;
					i++;
				}
				if (counter > 0 && counter < rate)
					rate = counter;
				counter = 0;
				while (i < bits.Length && bits[i] == '0')
				{
					counter++;
					i++;
				}
				if (counter > 0 && counter < rate)
					rate = counter;
			}
			return (rate);
		}

		//Создать строку заданной длины, содержащую заданные символы
		public static string BuildSameSymbolsString(char symbol, int length)
		{
			string result = "";
			for (int i = 0; i < length; i++)
			{
				result += symbol;
			}
			return (result);
		}

		//Преобразовать нули и единички в точки и тире
		public static string DecodeBits(string bits)
		{
			string result = "";
			
			bits = bits.Trim('0');
			int transRate = DefineRate(bits);
			string dot = BuildSameSymbolsString('1', transRate);
			string dash = BuildSameSymbolsString('1', 3 * transRate);

			string[] words = bits.Split(BuildSameSymbolsString('0', 7 * transRate));
			foreach (string word in words)
			{
				string[] wordChars = word.Split(BuildSameSymbolsString('0', 3 * transRate));
				foreach (string character in wordChars)
				{
					string[] dotsDashes = character.Split(BuildSameSymbolsString('0', transRate));
					foreach (string dotDash in dotsDashes)
					{
						if (dotDash == dot)
							result += ".";
						else
							result += "-";
					}
					result += " ";
				}
				result += "   ";
			}
			return (result);
		}

		public static string DecodeMorse(string morseCode)
		{
			Dictionary<string, string> Morse = new Dictionary<string, string>
			{
				{".-", "A"},
				{"-...", "B"},
				{"-.-.", "C"},
				{"-..", "D"},
				{".", "E"},
				{"..-.", "F"},
				{"--.", "G"},
				{"....", "H"},
				{"..", "I"},
				{".---", "J"},
				{"-.-", "K"},
				{".-..", "L"},
				{"--", "M"},
				{"-.", "N"},
				{"---", "O"},
				{".--.", "P"},
				{"--.-", "Q"},
				{".-.", "R"},
				{"...", "S"},
				{"-", "T"},
				{"..-", "U"},
				{"...-", "V"},
				{".--", "W"},
				{"-..-", "X"},
				{"-.--", "Y"},
				{"--..", "Z"},
				{"-----", "0"},
				{".----", "1"},
				{"..---", "2"},
				{"...--", "3"},
				{"....-", "4"},
				{".....", "5"},
				{"-....", "6"},
				{"--...", "7"},
				{"---..", "8"},
				{"----.", "9"},
				{"...---...", "SOS"},
				{".-.-.-", "."},
				{"--..--", ","},
				{"..--..", "?"},
				{".----.", "'"},
				{"-.-.--", "!"},
				{"-..-.", "/"},
				{"-.--.", "("},
				{"-.--.-", ")"},
				{".-...", "&"},
				{"---...", ":"},
				{"-.-.-.", ";"},
				{"-...-", "="},
				{".-.-.", "+"},
				{"-....-", "-"},
				{"..--.-", "_"},
				{".-..-.", "\""},
				{"...-..-", "$"},
				{".--.-.", "@"},
			};
			morseCode = morseCode.Trim(' ');
			string[] morseCodeWords = morseCode.Split("    ");
			string result = "";

			foreach (string word in morseCodeWords)
			{
				string[] chars = word.Split(" ");
				foreach (string character in chars)
				{
					result += Morse[character];
				}
				result += " ";
			}
			
			return (result.Trim(' '));
		}
	   
		static void Main(string[] args)
		{
			Console.WriteLine("'{0}'", DecodeMorse(DecodeBits("0000000000000000000000000000000000001100110011001100000011000000111111001100111111001111110000000000000011001111110011111100111111000000110011001111110000001111110011001100000011")));     
		}
	}
}
