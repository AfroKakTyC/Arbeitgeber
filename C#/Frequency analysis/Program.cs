using System;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Diagnostics;

namespace Frequency_analysis
{
	class Triplet
	{
		public int count;

		public string Value { get; private set; }

		public Triplet (string value)
		{
			Value = value;
			count = 1;
		}
	}

	class Program
	{

		static List<string> lines;
		static List<Triplet> triplets;
		static bool isEnd = false;

		//Проверка слова на буквы
		static bool IsLetterWord(string word)
		{
			for (int i = 0; i < word.Length; i++)
			{
				if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')))
					return (false);
			}
			return (true);
		}

		//Сортировка вставками по убыванию
		static void InsertionSort(List<Triplet> list)
		{
			for (int i = 0; i < list.Count - 1; i++)
			{
				for (int j = i + 1; j > 0; j--)
				{
					if (list[j - 1].count < list[j].count)
					{
						Triplet temp = list[j - 1];
						list[j - 1] = list[j];
						list[j] = temp;
					}
				}
			}
		}

		//Проверка на вхождение триплета в список
		static bool IsListContains(List<Triplet> list, Triplet triplet)
		{
			for (int i = 0; i < list.Count; i++)
			{
				if (list[i].Value == triplet.Value)
				{
					list[i].count++;
					return (true);
				}
			}
			return (false);
		}

		//Разбиение строки на слова, выборка и подсчёт триплетов
		static void FrequencyAnalysis(int index, ParallelLoopState pls)
		{
			char[] delimeters = {' ', '\t' };
			string[] words = lines[index].Split(delimeters);
			 
			if (isEnd == true) //Прерывание цикла при нажатии клавиши
				pls.Break();
			for (int i = 0; i < words.Length; i++)
			{
				//Console.WriteLine("we here");
				if (words[i].Length >= 3)
				{
					for (int j = 0; j <= words[i].Length - 3; j++)
					{
						//Console.WriteLine("we here2");

						string strTriplet = words[i].Substring(j, 3);
						if (IsLetterWord(strTriplet))
						{
							Triplet triplet = new Triplet(strTriplet);
							if (!IsListContains(triplets, triplet))
								triplets.Add(triplet);
						}
					}
				}
			}
		}

		//Проверка на нажатие клавиши
		static void KeyListner()
		{
			while (isEnd == false)
			{
				ConsoleKeyInfo key;
				key = Console.ReadKey();
				isEnd = true;
			}
		}

		static void Main(string[] args)
		{
			triplets = new List<Triplet>();
			lines = new List<string>();
			Stopwatch sw = new Stopwatch();
			sw.Start();

			//Запись файла построчно в список
			try
			{
				StreamReader reader = new StreamReader(args[0]);
				
				string line;
				while ((line = reader.ReadLine()) != null)
				{
					lines.Add(line);
				}
			}
			catch (Exception ex)
			{
				Console.WriteLine(ex.Message);
			}


			new Thread(new ThreadStart(KeyListner)).Start();

			if (lines.Count > 0)
			{
				ParallelLoopResult loopResult = Parallel.For(0, lines.Count, FrequencyAnalysis); //Параллельное выполнение цикла по поиску триплетов в строке
				InsertionSort(triplets); //Сортировка результирующего массива
				isEnd = true;
				//Вывод результатов
				if (triplets.Count > 10)
				{
					for (int i = 0; i < 10; i++)
					{
						if (i > 0)
							Console.Write(",");
						Console.Write(triplets[i].Value);
					}
				}
				else
				{
					for (int i = 0; i < triplets.Count; i++)
					{
						if (i > 0)
							Console.Write(",");
						Console.Write(triplets[i].Value);
					}
				}
				sw.Stop();
				Console.WriteLine("\n" + sw.ElapsedMilliseconds);
			}
		}
	}
}
