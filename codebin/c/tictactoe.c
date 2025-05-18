#include<stdio.h>
#include<stdbool.h>
#define MAX 1
int main(){
	printf("\n------Welcome to TIC TAC TOE------\n");
	char live_board[3][3] = {
		{ , , },
		{ , , },
		{ , , }
	};
	int player1_point = 0;
	int player2_point = 0;
	char player1[100];
	char player2[100];
	char choice;
	int turn = 0;
	int row,col;
	bool match[3]={false,false,false};
	printf("Enter player1: ");
	scanf("%s",player1);
	printf("Enter player2: ");
	scanf("%s",player2);
	while(player1_point !=MAX && player2_point != MAX){
		if(turn == 0){
			printf("%s: ",player1);
			scanf(" %c",&choice);
			printf("Where to write? ");
			scanf("%d %d",&row,&col);
			if(row <= 3 && col <=3){
				if(live_board[row][col] == ' '){
					live_board[row][col] = choice;
				}
				else{
					printf("\n[%d %d] is already written with %c\n",row,col,live_board[row][col]);
				}
				//check both diagonals match
				for(int i = 0;i < 3;i++){
					if(live_board[i][i] == 'x' || live_board[i][i] == 'o'){
						match[i] = true; 
					}
					else{
						match[i] = false;
					}
					int j=2;
					if(live_board[i][j] == 'x' || live_board[i][j] == 'o'){
						j--;
						match[i] = true;
					}
					else{
						match[i] = false;
					}
				}
				//check both sides match
				for(int i = 0;i < 3;i++){
					if(live_board[i][0] == 'x' || live_board[i][0] == 'o'){
						match[i] = true;
					}
					else{
						match[i] = false;
					}
					int j = 2;
					if(live_board[i][2] == 'x' || live_board[i][2] == 'o'){
						j--;
						match[i] == true;
					}
					else{
						match[i] = false;
					}
				}
			}
		else{
				printf("This is a 3X3 board!");
			}
			turn = 1; //Give next turn to player2
			if(match[0] == true && match[1] == true && match[2] == true){
				player1_point++;
			}
	}
		if(turn == 1){
			printf("%s: ",player2);
			scanf(" %c",&choice);
			printf("\nWhere to write?\n");
			scanf("%d %d",&row,&col);
			if(row <= 3 && col <=3){
				if(live_board[row][col] == ' '){
					live_board[row][col] = choice;
				}
				else{
					printf("\n%d %d is already written with %c\n",row,col,live_board[row][col]);
				}
				//check both diagonals match
				for(int i = 0;i < 3;i++){
					if(live_board[i][i] == 'x' || live_board[i][i] == 'o'){
						match[i] = true; 
					}
					else{
						match[i] = false;
					}
					int j=2;
					if(live_board[i][j] == 'x' || live_board[i][j] == 'o'){
						j--;
						match[i] = true;
					}
					else{
						match[i] = false;
					}
				}
				//check both sides match
				for(int i = 0;i < 3;i++){
					if(live_board[i][0] == 'x' || live_board[i][0] == 'o'){
						match[i] = true;
					}
					else{
						match[i] = false;
					}
					int j = 2;
					if(live_board[i][2] == 'x' || live_board[i][2] == 'o'){
						j--;
						match[i] == true;
					}
					else{
						match[i] = false;
					}
				}
			}
			else{
				printf("\nThis is a 3X3 board!\n");
			}
			turn = 0; //Give next turn to player1
			if(match[0] == true && match[1] == true && match[2] == true){
				player2_point++;
			}
		}
	}
}
