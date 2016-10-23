#include<stdio.h>
#include"sweep.h"
int main()
{  int a=0;
	int i=0;
	int j=0;

	char mine[rows][cols];
	char show[rows][cols];
		srand((unsigned)time(NULL));
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
		{
			mine[i][j]='0';
			show[i][j]='*';
		}
	while(1){
	printf("***********sweep mine!!*****\n");
	printf("**********1.play************\n");
	printf("**********2.exit************\n");
	printf("****************************\n");
	scanf("%d",&a);
	switch (a)
	{case 1:
	{set_mine(mine);
	display(show);
	Sweep(mine,show);
	break;}
	case 2:break;
	default:printf("erro try again:");
		break;
	}
	break;}
}
