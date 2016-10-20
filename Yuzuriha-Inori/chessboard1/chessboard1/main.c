#include<stdio.h>
#include"chessboard.h"
int main()
{int i=1;
 int a=0;
 int b=0;
 char result;
 char board[3][3];
 while(i){
	printf("*****************\n");
	printf("***1.play********\n");
	printf("***2.exit********\n");
	printf("*****************\n");
	printf("please choice:");
	scanf("%d",&a);
	switch (a)
	{case 1:
	init_board(board,3,3);
	do{
	display_board(board,3,3);
	player_move(board,3,3);
	computer_move(board,3,3);
	 result=check_win(board,3,3);
	 if(result==' '){printf("balance\n");break;}
	 if(result=='x'){printf("youwin!\n");break;}
	 if(result=='o'){printf("youlose!\n");break;}
	}while(1);
	break;
	 case 2:i=0;break;

	default:printf("erro input!");
	}
 }}