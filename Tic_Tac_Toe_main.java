import java.util.*;
public class Tic_Tac_Toe_main {
	
	static char matrix[][] = new char[3][3];
	static boolean winner = false;
	
	public static void display() {
		for(int i = 0; i < 3; i++ ) {
			for(int j = 0; j < 3; j++ ) {
				if( j < 2 )
					System.out.print(matrix[i][j] + "\t |");
				else
					System.out.print(matrix[i][j]);
			}
			System.out.println();
			if( i < 2 )
				System.out.println("--------------------------------");
		}
	}
	
	public static void move(char c) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Choose your move (row [ 1 -3 ] and column [ 1 - 3 ] :-    ");
		int row = sc.nextInt();
		int column = sc.nextInt();
		
		row--;
		column--;
		
		if( matrix[row][column] == 'X' || matrix[row][column] == 'O' ) {
			System.out.println("Are you illiterate?????? Giving you another try");
			move(c);
		}
		else {
			matrix[row][column] = c;
			display();
		}
	}
	
	public static void check_Move(char c) {
		int rowCount = 0, columnCount = 0, leftDiagonalCount = 0, rightDiagonalCount = 0;
		for(int i = 0; i < 3; i++ ) {
			for(int j = 0; j < 3; j++ ) {
				if( matrix[i][j] == c )
					rowCount++;
				if( matrix[j][i] == c )
					columnCount++;
				if( i == j && matrix[i][j] == c )
					leftDiagonalCount++;
				if( i == 3-j-1 && matrix[i][j] == c )
					rightDiagonalCount++;
			}
			if( rowCount == 3 || columnCount == 3 )
				winner = true;
			else
				rowCount = columnCount = 0;
		}
		if( rightDiagonalCount == 3 || leftDiagonalCount == 3 )
			winner = true;
		if( winner )
			System.out.println( c + " Won....");
	}
	
	public static void main(String args[]) {            //main
		for(int i = 1; i <= 9; i++ ) {
			if( winner == false ) {
				if( i % 2 == 0 ) {
					move('O');
					check_Move('O');
				}
				else {
					move('X');
					check_Move('X');
				}
			}
			else {
				System.out.println("Game Over..........");
				break;
			}
		}
		if( winner == false )
			System.out.println("Match Draw.............");
	}
}
