#include<stdio.h>
#include<conio.h>
char ar[3][3],m,wx=0,wo=0,flagx=0,flago=0;
void xmove();
void omove();
void board() {
	int i,j;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			printf("%c",ar[i][j]);
			if(j!=2)
			printf("\t|");
		}
		printf("\n");
		if(i!=2)
		printf("---------------------------------");
		printf("\n");
	}
}
void check_x_winner() {
	int i,j,rw=0,cw=0,ldw=0,rdw=0,k=2;
	for(i=0;i<3;i++) {
		rw=0,cw=0;
		for(j=0;j<3;j++) {		
			if(ar[i][j]=='X') {
				rw++;
				if(rw==3)
				wx=1;
			}
			if(ar[j][i]=='X') {
				cw++;
				if(cw==3)
				wx=1;
			}
			if(i==j&&ar[i][j]=='X')
			ldw++;
			if(ar[0][2]=='X'&&ar[1][1]=='X'&&ar[2][0]=='X') {
				rdw=3;
			}
		}
	}
	if(ldw==3||rdw==3)
	wx=1;
	if(wx==1)
	printf("'X' won....Bye");
}
void check_o_winner() {
	int i,j,rw=0,cw=0,ldw=0,rdw=0,k=2;
	for(i=0;i<3;i++) {
		rw=0,cw=0;
		for(j=0;j<3;j++) {		
			if(ar[i][j]=='O') {
				rw++;
				if(rw==3)
				wo=1;
			}
			if(ar[j][i]=='O') {
				cw++;
				if(cw==3)
				wo=1;
			}
			if(i==j&&ar[i][j]=='O')
			ldw++;
			if(ar[k][i]=='O') {
				rdw++;
				k--;
			}
		}
	}
	if(ldw==3||rdw==3)
	wo=1;
	if(wo==1)
	printf("'O' won....Bye");
}
void check_move_validity(int a,int b) {
	if((ar[a][b]=='X'||ar[a][b]=='O')&&m%2!=0) {
		flagx=1;
		printf("YOU HAVE ENTERED WRONG POSITION\n Giving You Another Try......\n");
	}
	else if((ar[a][b]=='O'||ar[a][b]=='X')&&m%2==0) {
		flago=1;
		printf("YOU HAVE ENTERED WRONG POSITION\n Giving You Another Try......\n");
	}
	else {
		flagx=0;
		flago=0;
	}
}
void xmove() {
	int r,c;
	printf("Player 'X',choose your move(row[1-3] and column[1-3]):");
	scanf("%d %d",&r,&c);
	r--;
	c--;
	if(r>=3||c>=3) {
		printf("YOU HAVE ENTERED WRONG POSITION\n Giving You Another Try......\n");
		xmove();
	}
	else {
		check_move_validity(r,c);
		if(flagx==0) {
			ar[r][c]='X';
			board();
			check_x_winner();
		}
		else {
			xmove();
		}
	}
}
void omove() {
	int r,c;
	printf("Player 'O',choose your move(row[1-3] and column[1-3]):");
	scanf("%d %d",&r,&c);
	r--;
	c--;
	if(r>=3||c>=3) {
		printf("ARE YOU ILLITERATE?????\n Giving You Another Try......\n");
		omove();
	}
	else {
		check_move_validity(r,c);
		if(flago==0) {
			ar[r][c]='O';
			board();
			check_o_winner();
		}
		else {
			omove();
		}
	}
}
main() {
	for(m=1;m<=9;m++) {
		if(wx!=1&&wo!=1) {
			if(m%2!=0)
				xmove();
			else
				omove();
		}
		else {
			printf("\nGame Over\n");
			break;
		}
	}
	if((m>=9)&&(wx!=1&&wo!=1))
	printf("\nMatch draw\n");
}
