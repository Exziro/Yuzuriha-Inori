#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define rows 11
#define cols 11
#define mine_number 10
int get_mine(char mine[rows][cols],int x,int y);
void display(char show[rows][cols]);
void set_mine(char mine[rows][cols]);
void Sweep(char mine[rows][cols], char show[rows][cols]);
void game(char mine[rows][cols],int x,int y);