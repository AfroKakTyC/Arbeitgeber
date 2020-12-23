using System;

namespace Codewars_style_ranking_system_Codewars_4kyu
{
	public class User
	{
		int[] ranks = new int[] { -8, -7, -6, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 6, 7, 8 };
		int index;

		public int rank { get; private set; }
		
		public int progress { get; private set; }

		public User()
		{
			rank = -8;
			progress = 0;
			index = 0;
		}

		public void incProgress(int taskRank)
		{
			try
			{
				int taskRankIndex = Array.IndexOf(ranks, taskRank);
				if (taskRankIndex < 0)
					throw new ArgumentException();
				if (rank < 8)
				{
					if (taskRankIndex == index)
						progress += 3;
					else if (taskRankIndex - index <= -1)
						progress += 1;
					else if (taskRankIndex - index >= 1)
					{
						int diff = taskRankIndex - index;
						progress += 10 * diff * diff;
					}
					if (progress >= 100)
						incRank();
				}
			}
			catch (ArgumentException exOb)
			{
				Console.WriteLine(exOb.Message);
			}
		}

		void incRank()
		{
			int upRanks = progress / 100;
			if (upRanks + index < ranks.Length)
			{
				rank = ranks[upRanks + index];
				index += upRanks;
				if (rank == 8)
					progress = 0;
				else
					progress = progress - (upRanks * 100);
			}
			else
			{
				rank = 8;
				index = 7;
				progress = 0;
			}
		}
	
	}


	class Program
	{
		static void Main(string[] args)
		{
			User user = new User();
			Console.WriteLine("rank = {0} progress = {1}", user.rank, user.progress);
			user.incProgress(-8);
			Console.WriteLine("rank = {0} progress = {1}", user.rank, user.progress);
			user.incProgress(-7);
			Console.WriteLine("rank = {0} progress = {1}", user.rank, user.progress);
			user.incProgress(3);
			Console.WriteLine("rank = {0} progress = {1}", user.rank, user.progress);
		}
	}
}
