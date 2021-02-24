using System;

namespace Areas2DLib
{
	public class Shape2D
	{
		public double Width;
		public double Height;
	}

	public class Circle : Shape2D
	{
		public double Radius;

		public Circle(double radius)
		{
			Width = radius * 2;
			Height = radius * 2;
			Radius = radius;
		}

		public double GetArea()
		{
			return (2 * Math.PI * Radius * Radius);
		}
	}

	public class Triangle : Shape2D
	{
		public double SideA;
		public double SideB;
		public double SideC;

		public Triangle(double a, double b, double c)
		{
			SideA = a;
			SideB = b;
			SideC = c;
		}

		public double GetArea()
		{
			double semiPerimeter = (SideA + SideB + SideC) / 2;
			return (Math.Sqrt(semiPerimeter * (semiPerimeter - SideA) * (semiPerimeter - SideB) * (semiPerimeter - SideC)));
		}

		public bool IsRectangular()
		{
			double hypotenuse;
			double cathetusA;
			double cathetusB;

			if (SideA > SideB && SideA > SideC)
			{
				hypotenuse = SideA;
				cathetusA = SideB;
				cathetusB = SideC;
			}
			else if (SideB > SideA && SideB > SideC)
			{
				hypotenuse = SideB;
				cathetusA = SideA;
				cathetusB = SideC;

			}
			else
			{
				hypotenuse = SideC;
				cathetusA = SideA;
				cathetusB = SideB;
			}
			if (hypotenuse * hypotenuse == cathetusA * cathetusA + cathetusB * cathetusB)
				return (true);
			else
				return (false);
		}
	}
}
