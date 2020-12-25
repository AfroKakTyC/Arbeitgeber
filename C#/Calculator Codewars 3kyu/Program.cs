using System;
using System.Collections.Generic;

namespace Calculator_Codewars_3kyu
{
	class Program
	{
		public static bool IsNumber(string str)
		{
			char[] numChars = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };
			foreach (char ch in str)
				if (Array.IndexOf(numChars, ch) < 0)
					return (false);
			if (str.Length > 0)
				return (true);
			else
				return (false);
		}

		public static int CheckPriority(string str)
		{
			if (str == "+" || str == "-")
				return (1);
			else if (str == "*" || str == "/")
				return (2);
			return (0);
		}

		public static double DoOperation(double firstNum, double secondNum, string operation)
		{
			if (operation == "+")
				return (secondNum + firstNum);
			else if (operation == "-")
				return (secondNum - firstNum);
			else if (operation == "*")
				return (secondNum * firstNum);
			else
				return (secondNum / firstNum);
		}

		public static double Evaluate(string expression)
		{
			Stack<double> nums = new Stack<double>();
			Stack<string> operators = new Stack<string>();
			string[] numsAndOperators = expression.Split(' ');
			for (int i = 0; i < numsAndOperators.Length; i++)
			{
				if (IsNumber(numsAndOperators[i]))
					nums.Push(Double.Parse(numsAndOperators[i]));
				else
				{
					if (numsAndOperators[i] == "(")
						operators.Push(numsAndOperators[i]);
					else if (numsAndOperators[i] == ")")
					{
						while (operators.Peek() != "(")
						{
							if (nums.Count == 1)
							{
								if (operators.Peek() == "-")
									nums.Push(-nums.Pop());
								operators.Pop();
							}
							else
							{
								double firstNum = nums.Pop();
								double secondNum = nums.Pop();
								string operation = operators.Pop();
								nums.Push(DoOperation(firstNum, secondNum, operation));
							}
						}
						operators.Pop();
					}
					else
					{
						if (operators.Count == 0 || CheckPriority(numsAndOperators[i]) > CheckPriority(operators.Peek()))
							operators.Push(numsAndOperators[i]);
						else
						{
							while (operators.Count > 0 && CheckPriority(numsAndOperators[i]) <= CheckPriority(operators.Peek()))
							{
								Console.WriteLine(operators.Count);
								if (nums.Count == 1)
								{
									if (operators.Peek() == "-")
										nums.Push(-nums.Pop());
									operators.Pop();
								}
								else
								{
									double firstNum = nums.Pop();
									double secondNum = nums.Pop();
									string operation = operators.Pop();
									nums.Push(DoOperation(firstNum, secondNum, operation));
								}
							}
							operators.Push(numsAndOperators[i]);
						}
					}
				}
			}
			while (operators.Count > 0)
			{
				if (nums.Count == 1)
				{
					if (operators.Peek() == "-")
						nums.Push(-nums.Pop());
					operators.Pop();
				}
				else
				{
					double firstNum = nums.Pop();
					double secondNum = nums.Pop();
					string operation = operators.Pop();
					nums.Push(DoOperation(firstNum, secondNum, operation));
				}
			}
			return (nums.Pop());
		}

		static void Main(string[] args)
		{

			Console.WriteLine("Result = {0}", Evaluate("1 + 2 * ( 3 + 4 / 2 - ( 1 + 2 ) ) * 2 + 1"));
		}
	}
}
