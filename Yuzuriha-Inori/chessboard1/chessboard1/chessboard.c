#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include"chessboard.h"
void init_board(char board[ROWS][COLS],int x,int y)
{
memset(board,' ',ROWS*COLS*sizeof(char));
}
 void display_board(char board[ROWS][COLS],int x,int y)
 {
	 int i=0;
	 for(i=0;i<3;i++){
			 printf("%c  |%c  |%c\n",board[i][0],board[i][1],board[i][2]);
			 if (i!=2) printf("---|---|---\n");			
	 }
	 }
void player_move(char board[ROWS][COLS],int x,int y)
{
	int a=0;
	int b=0;
	printf("please enter a number:");
	while (1)
	{

	
	scanf("%d %d",&a,&b);
	if(board[a][b]=' ')
	{	board[a][b]='X';
	break;}
	printf("erro number try again£º");
	}
}

void computer_move(char board[ROWS][COLS],int x,int y)
{
	int i=0;
	int j=0;
	int flag =1;
	srand((unsigned) time(NULL));
	do
	{i= rand()%3;
	j= rand()%3;
	if(board[i][j]==' '){
			board[i][j]='O';
			flag = 0;}
	}while(flag);
}
char check_win(char board[ROWS][COLS],int x,int y)
{
	int i=0;
	int j=0;
	int playrow=0;
	int playcols=0;
	int playn=0;
	int plays=0;
	int cr=0;
	int cc=0;
	int cn=0;
	int cs=0;
	int count = 0;
	int count1=0;
	//for(i=0;i<3;i++){
	//	while(j!=3){
	//		if(board[i][j]=='X')
	//		{count=count+1;}
	//		if(board[i][j]=='O')
	//		{count=count-1;}
	//		j++;}
	//	if(count==3)
	//	{	return ' x';
	//	break;}
	//	else if(count==-3)
	//	{	return 'o';
	//	break;}
	//}
	//i = 0;
	//for(j=0;j<3;j++){
	//	while(i!=3){
	//		if(board[i][j]=='X')
	//		{count=count+1;}
	//		if(board[i][j]=='O')
	//		{count=count-1;}
	//		i++;}
	//	if(count==3)
	//	{	printf("you win!\n");
	//	break;}
	//	else if(count==-3)
	//	{	printf("you lose!\n");
	//	break;}
	//}
for(i=0;i<ROWS;i++)
	playrow=0;
	playn=0;
	plays=0;
	playcols=0;
	cr=0;
	cc=0;
	cs=0;
	cn=0;
	for(j=0;j<COLS;j++)
	{if(board[j][i]=='X')playrow++;
	if(board[i][j]=='X')playcols++;
if(board[j][j]=='X')playn++;
if(board[j][3-1-j]=='X')plays++;
if(board[j][i]=='O')cc++;
if(board[j][j]=='O')cn++;
if(board[j][3-1-j]=='O')cs++;
if(board[i][j]=='O')cr++;
}
{if(playrow==3)return 'x';
if(playcols==3)return 'x';
if(playn==3)return 'x';
if(plays==3)return 'x';
if(cc==3)return 'o';
if(cn==3)return 'o';
if(cs==3)return 'o';
if(cr==3)return 'o';
}
for(i=0;i<ROWS;i++)
	{for(j=0;j<COLS;j++)
	if(board[i][j]==' ')count1++;}
if(count==9)return ' ';
}
