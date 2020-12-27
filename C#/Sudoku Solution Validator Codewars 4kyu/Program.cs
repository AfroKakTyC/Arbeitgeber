using System;
using System.Collections.Generic;

namespace Sudoku_Solution_Validator_Codewars_4kyu
{
	class Program
	{
		public static bool ValidateSolution(int[][] board)
		{
			//Проход по столбцам
			for (int i = 0; i < 9; i++)
			{
				List<int> intInColumn = new List<int>();
				for(int j = 0; j < 9; j++)
				{
					int currInt = board[j][i];
					if (currInt >= 1 && currInt <= 9)
					{
						if (intInColumn.Contains(currInt))
							return (false);
						else
							intInColumn.Add(currInt);
					}
					else
						return (false);
				}
			}
			//Проход по строкам
			for (int i = 0; i < 9; i++)
			{
				List<int> intInColumn = new List<int>();
				for (int j = 0; j < 9; j++)
				{
					int currInt = board[i][j];
					if (currInt >= 1 && currInt <= 9)
					{
						if (intInColumn.Contains(currInt))
							return (false);
						else
							intInColumn.Add(currInt);
					}
					else
						return (false);
				}
			}
			//Проход по блокам 3х3
			for (int i = 0; i < 9; i = i + 3)
			{
				for (int j = 0; j < 9; j = j + 3)
				{
					int kMax = i + 3;
					int lMax = j + 3;
					List<int> intInColumn = new List<int>();
					for (int k = i; k < kMax; k++)
					{
						for (int l = j; l < lMax; l++)
						{
							int currInt = board[k][l];
							if (currInt >= 1 && currInt <= 9)
							{
								if (intInColumn.Contains(currInt))
									return (false);
								else
									intInColumn.Add(currInt);
							}
							else
								return (false);
						}
					}
				}
			}
			return (true);
		}
		

		static void Main(string[] args)
		{
			int[][] array = new int[][]
			{
			  new int[] {5, 3, 4, 6, 7, 8, 9, 1, 2},
			  new int[] {6, 7, 2, 1, 9, 5, 3, 4, 8},
			  new int[] {1, 9, 8, 3, 4, 2, 5, 6, 7},
			  new int[] {8, 5, 9, 7, 6, 1, 4, 2, 3},
			  new int[] {4, 2, 6, 8, 5, 3, 7, 9, 1},
			  new int[] {7, 1, 3, 9, 2, 4, 8, 5, 6},
			  new int[] {9, 6, 1, 5, 3, 7, 2, 8, 4},
			  new int[] {2, 8, 7, 4, 1, 9, 6, 3, 5},
			  new int[] {3, 4, 5, 2, 8, 6, 1, 7, 9},
			};
			Console.WriteLine(ValidateSolution(array));

		}
	}
}
