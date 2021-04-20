using System;
using System.Collections.Generic;
using System.Linq;

namespace Gridnine.FlightCodingTest
{
	public class FlightBuilder
	{
		private DateTime _threeDaysFromNow;

		public FlightBuilder()
		{
			_threeDaysFromNow = DateTime.Now.AddDays(3);
		}

		public IList<Flight> GetFlights()
		{
			return new List<Flight>
					   {
						   //A normal flight with two hour duration
						   CreateFlight("A normal flight with two hour duration", _threeDaysFromNow, _threeDaysFromNow.AddHours(2)),

						   //A normal multi segment flight
						   CreateFlight("A normal multi segment flight", _threeDaysFromNow, _threeDaysFromNow.AddHours(2), _threeDaysFromNow.AddHours(3), _threeDaysFromNow.AddHours(5)),
						   
						   //A flight departing in the past
						   CreateFlight("A flight departing in the past", _threeDaysFromNow.AddDays(-6), _threeDaysFromNow),

						   //A flight that departs before it arrives
						   CreateFlight("A flight that departs before it arrives", _threeDaysFromNow, _threeDaysFromNow.AddHours(-6)),

						   //A flight with more than two hours ground time
						   CreateFlight("A flight with more than two hours ground time", _threeDaysFromNow, _threeDaysFromNow.AddHours(2), _threeDaysFromNow.AddHours(5), _threeDaysFromNow.AddHours(6)),

							//Another flight with more than two hours ground time
						   CreateFlight("Another flight with more than two hours ground time", _threeDaysFromNow, _threeDaysFromNow.AddHours(2), _threeDaysFromNow.AddHours(3), _threeDaysFromNow.AddHours(4), _threeDaysFromNow.AddHours(6), _threeDaysFromNow.AddHours(7))
					   };
		}

		private static Flight CreateFlight(string description, params DateTime[] dates)
		{
			if (dates.Length % 2 != 0) throw new ArgumentException("You must pass an even number of dates,", "dates");



			var departureDates = dates.Where((date, index) => index % 2 == 0);
			var arrivalDates = dates.Where((date, index) => index % 2 == 1);

			var segments = departureDates.Zip(arrivalDates,
											  (departureDate, arrivalDate) =>
											  new Segment { DepartureDate = departureDate, ArrivalDate = arrivalDate }).ToList();

			return new Flight { Description = description, Segments = segments };
		}
	}

	public class Flight
	{
		public string Description { get; set; }
		public IList<Segment> Segments { get; set; }
	}

	public class Segment
	{
		public DateTime DepartureDate { get; set; }
		public DateTime ArrivalDate { get; set; }
	}

	public class Program
	{
		delegate bool Rule(Flight flight);

		static bool IsDepartureBeforeNow(Flight flight)
		{
			foreach (Segment segment in flight.Segments)
			{
				if (segment.DepartureDate < DateTime.Now)
					return (true);
			}
			return (false);
		}

		static bool IsArrivalsBeforeDeparture(Flight flight)
		{
			foreach (Segment segment in flight.Segments)
			{
				if (segment.DepartureDate > segment.ArrivalDate)
					return (true);
			}
			return (false);
		}

		static bool IsGroundTimeMoreThenTwoHours(Flight flight)
		{
			DateTime hoursOnGround = new DateTime();
			DateTime lastArrivalTime = flight.Segments[0].ArrivalDate;
			for (int i = 1; i < flight.Segments.Count; i++)
			{
				hoursOnGround += flight.Segments[i].DepartureDate - lastArrivalTime;
				if (hoursOnGround.Hour > 2)
					return (true);
			}
			return (false);
		}

		static List<Flight> FilterFlights(List<Flight> flights, Rule rule)
		{
			List<Flight> filteredFlights = new List<Flight>();
			foreach (Flight flight in flights)
				if (!rule(flight))
					filteredFlights.Add(flight);

			return (filteredFlights);
		}

		static void Main(string[] args)
		{
			FlightBuilder fb = new FlightBuilder();
			List<Flight> flights = (List<Flight>)fb.GetFlights();
			List<Rule> rules = new List<Rule> { IsDepartureBeforeNow, IsArrivalsBeforeDeparture, IsGroundTimeMoreThenTwoHours };

			//Filtering flights by rule "Departure before now"
			List<Flight> filteredByFirstRuleFlights = FilterFlights((List<Flight>)fb.GetFlights(), rules[0]);
			Console.WriteLine("Flights filtered by rule \"Departure before now\":\n");
			foreach (Flight flight in filteredByFirstRuleFlights)
				Console.WriteLine(flight.Description);
			Console.WriteLine("\n");

			//Filtering flights by rule "Have segments where arrival before departure"
			List<Flight> filteredBySecondRuleFlights = FilterFlights((List<Flight>)fb.GetFlights(), rules[1]);
			Console.WriteLine("Flights filtered by rule \"Have segments where arrival before departure\":\n");
			foreach (Flight flight in filteredBySecondRuleFlights)
				Console.WriteLine(flight.Description);
			Console.WriteLine("\n");

			//Filtering flights by rule "Total ground time is more than two hours"
			List<Flight> filteredByThirdRuleFlights = FilterFlights((List<Flight>)fb.GetFlights(), rules[2]);
			Console.WriteLine("Flights filtered by rule \"Total ground time is more than two hours\":\n");
			foreach (Flight flight in filteredByThirdRuleFlights)
				Console.WriteLine(flight.Description);
			Console.WriteLine("\n");
		}
	}
}

