import java.util.*;
public class Tic_Tac_Toe_main {
	static char matrix[][] = new char[3][3];
	
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
		
		matrix[row][column] = c;
		
		display();
	}
	
	void check_Move() {
		for(int i = 0; i < 3; i++ ) {
			for(int j = 0; j < 3; j++ ) {
			}
		}
	}
	
	public static void main(String args[]) {
		for(int i = 1; i <= 9; i++ ) {
			if( i % 2 == 0 )
				move('O');
			else
				move('X');
		}	
	}
}
