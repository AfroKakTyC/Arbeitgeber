using System;
using System.Collections.Generic;

namespace Human_readable_duration_format_Codewars_4kyu
{
	class TimeUnit
	{
		public int Value { get; private set; }
		
		public string Name { get; private set; }

		public TimeUnit(int value, string name)
		{
			Value = value;
			Name = name;
		}
			
	}

	class Program
	{
		public static string formatDuration(int seconds)
		{
			List<TimeUnit> timeUnits = new List<TimeUnit>();

			int years = seconds / 60 / 60 / 24 / 365;
			if (years > 0)
				timeUnits.Add(new TimeUnit(years, "year"));
			seconds = seconds - years * 60 * 60 * 24 * 365;
			int days = seconds / 60 / 60 / 24;
			if (days > 0)
				timeUnits.Add(new TimeUnit(days, "day"));
			seconds = seconds - days * 60 * 60 * 24;
			int hours = seconds / 60 / 60;
			if (hours > 0)
				timeUnits.Add(new TimeUnit(hours, "hour"));
			seconds = seconds - hours * 60 * 60;
			int minutes = seconds / 60;
			if (minutes > 0)
				timeUnits.Add(new TimeUnit(minutes, "minute"));
			seconds = seconds - minutes * 60;
			if (seconds > 0)
				timeUnits.Add(new TimeUnit(seconds, "second"));

			string result = "";
			for (int i = 0; i < timeUnits.Count; i++)
			{
				result += timeUnits[i].Value + " " + timeUnits[i].Name;
				if (timeUnits[i].Value > 1)
					result += "s";
				if (timeUnits.Count - i == 2)
					result += " and ";
				else if (timeUnits.Count - i > 1)
					result += ", ";
			}
			if (timeUnits.Count == 0)
				result += "now";
			return (result);
		}

		static void Main(string[] args)
		{
			//formatDuration(121);
			Console.WriteLine(formatDuration(242062374));
		}
	}
}
