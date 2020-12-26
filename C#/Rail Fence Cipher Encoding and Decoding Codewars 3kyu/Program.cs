using System;
using System.Collections.Generic;

namespace Rail_Fence_Cipher_Encoding_and_Decoding_Codewars_3kyu
{
	class Program
	{
		public static string Encode(string s, int n)
		{
			string[] encodedStr = new string[n];

			int rail = 0;
			int d = 1;
			for (int i = 0; i < s.Length; i++)
			{
				encodedStr[rail] += s[i];
				rail += d;
				if (rail == n - 1)
					d = -1;
				if (rail == 0)
					d = 1;
			}
			string result = "";
			for (int i = 0; i < encodedStr.Length; i++)
			{
				result += encodedStr[i];
			}
			return (result);
		}

		public static string Decode(string s, int n)
		{
			int cycle = n * 2 - 2;
			int cyclesCount = s.Length / cycle;
			int cycleRemainder = s.Length - cycle * cyclesCount;
			int[] charOnRailCount = new int[n];

			for (int i = 0; i < n; i++)
			{
				if (i == 0)
					charOnRailCount[i] = cyclesCount;
				else if (i == n - 1)
					charOnRailCount[i] = cyclesCount;
				else
					charOnRailCount[i] = cyclesCount * 2;
			}
			int d = 1;
			int rail = 0;
			for (int i = 0; i < cycleRemainder; i++)
			{
				charOnRailCount[rail]++;
				rail += d;
				if (rail == n - 1)
					d = -1;
				if (rail == 0)
					d = 1;
			}
			string[] encodedStr = new string[n];
			Stack<char>[] charStack = new Stack<char>[n];
			int startIndex = 0;
			for (int i = 0; i < charOnRailCount.Length; i++)
			{
				encodedStr[i] = s.Substring(startIndex, charOnRailCount[i]);
				charStack[i] = new Stack<char>();
				for (int j = encodedStr[i].Length - 1; j > -1; j--)
				{
					charStack[i].Push(encodedStr[i][j]);
				}
				startIndex += charOnRailCount[i];
			}
			rail = 0;
			d = 1;
			string result = "";
			for (int i = 0; i < s.Length; i++)
			{
				result += charStack[rail].Pop();
				rail += d;
				if (rail == n - 1)
					d = -1;
				if (rail == 0)
					d = 1;
			}
			return (result);
		}

		static void Main(string[] args)
		{
			Console.WriteLine(Encode("123456789", 4));
			Console.WriteLine(Decode(Encode("123456789", 4), 4));
		}
	}
}
