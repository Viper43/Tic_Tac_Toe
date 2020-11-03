using System;
using System.Net;

namespace ConsoleApp1
{
	class Program
	{
		public static char[,] matrix = new char[3, 3] { {' ',' ',' ' }, { ' ', ' ' , ' ' }, { ' ', ' ', ' ' } };
		static bool winner = false;

        	public static void Display()
		{
		    for (int i = 0; i < 3; i++)
		    {
			Console.WriteLine();
			for (int j = 0; j < 3; j++)
			{
				if (j < 2)
				Console.Write(matrix[i, j] + "\t |");
				else
				Console.Write(matrix[i, j]);
			}
			Console.WriteLine();
			if (i < 2)
				Console.Write("--------------------------------");
		    }
		}

		public static void Move(char c)
		{
			Console.Write("Choose your move (row [ 1 -3 ] and column [ 1 - 3 ] :-    ");
			int row = Convert.ToInt32(Console.ReadLine());
			int column = Convert.ToInt32(Console.ReadLine());

			row--;
			column--;
			if (matrix[row, column] == 'X' || matrix[row, column] == 'O')
	    		{
				Console.Write("Are you illiterate?????? Giving you another try");
				Move(c);
			}
			else
			{
				matrix[row,column] = c;
				Display();
			}
		}

		public static void check_Move(char c)
		{
			int rowCount = 0, columnCount = 0, leftDiagonalCount = 0, rightDiagonalCount = 0;
			for (int i = 0; i < 3; i++)
		    	{
				for (int j = 0; j < 3; j++)
				{
					if (matrix[i, j] == c)
						rowCount++;
					if (matrix[j,i] == c)
						columnCount++;
					if (i == j && matrix[i, j] == c)
						leftDiagonalCount++;
					if (i == 3 - j - 1 && matrix[i, j] == c)
						rightDiagonalCount++;
				}
				if (rowCount == 3 || columnCount == 3)
					winner = true;
				else
					rowCount = columnCount = 0;
			}
			if ( rightDiagonalCount == 3 || leftDiagonalCount == 3 )
				winner = true;
			if( winner )
				Console.Write(c + " Won....");
		}
		public static void PlayGame()
		{
			matrix = new char[3, 3] { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
			for (int i = 1; i <= 9; i++)
			{
				if (!winner)
				{
					if (i % 2 == 0)
					{
						Move('O');
						check_Move('O');
					}
					else
					{
						Move('X');
						check_Move('X');
					}
				}
				else
				{
					Console.WriteLine("Game Over..........");
					break;
				}
			}
			if (!winner)
				Console.Write("Match Draw.............");
		}
		public static void Main(string[] args)
		{
			//main
			PlayGame();

		}
	}
}
