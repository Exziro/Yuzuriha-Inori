
#include"sweep.h"
void set_mine(char mine[rows][cols])
{
	int count =mine_number;
	int i=0;
	int j=0;
	srand((unsigned)time(NULL));
	while(count)
	{
		i=rand()%rows;
		j=rand()%cols;
		if(mine[i][j]=='0')
		{
			mine[i][j]='1';
			count--;
		}
	}
}
int get_mine(char mine[rows][cols],int x,int y)
{
	int count =0;
	if(mine[x-1][y-1]=='1')
	{count++;}
	if(mine[x][y-1]=='1')
		{count++;}
	if(mine[x+1][y-1]=='1')
	{count++;}
	if(mine[x+1][y]=='1')
	{count++;}
	if(mine[x+1][y+1]=='1')
	{count++;}
	if(mine[x][y+1]=='1')
		{count++;}
	if(mine[x-1][y+1]=='1')
	{count++;}
	if(mine[x-1][y]=='1')
	{count++;}
	return count;
}
void display(char show[rows][cols])
{
	int i=0;
	int j=0;
	printf("  ");
	for(i=1;i<cols-1;i++)
	{
		printf("%d  ",i);
	}
	printf("\n");
    for (i = 1; i < rows - 1; i++)  
    {  
        printf("%d", i);  
        for (j = 1; j < cols - 1; j++)  
        {  
            printf(" %c ", show[i][j]);  
        }  
        printf("\n");  
    }  
}
//int sweep(char mine[rows][cols],char show[rows][cols])
//{
//	int count=0;
//	int x=0;
//	int y=0;
//	int mine=0;
//	while(count!=((rows-2)*(cols-2)-mine_number)
//	{
//		printf("please enter number:");
//		scanf("%d%d"&x,&y);
//		if(miner[x][y]=='x')
//		{
//			printf("you are die!!");
//			return 0;
//		}
//		else
//		{
//			mine=get_mine(mine,10,10);
//			show[x][y]=mine+'0';
//			dispaly(show);
//			count++;
//		}
//	}
//	printf("congratulation!");
//	display(mine);
//	return 0;
//}
void Sweep(char mine[rows][cols], char show[rows][cols])  
{  
    int count = 0;  
    int x = 0;  
    int y = 0;  
    while (count!=((rows-2)*(cols-2)-mine_number))  
    {  
        printf("please number£º\n");  
        scanf("%d%d", &x, &y);  
        if (mine[x][y] == '1')  
        {  
            printf("you are die!!\n");  
      
        }  
        else  
        {  
            int ret = get_mine(mine, x, y);  
            show[x][y] = ret + '0';  
            //set_mine(mine);  
            display(show);  
            count++;  
        }  
    }  
    printf("congratulation£¡\n");  
    display(mine);  
      
}  
 //int game(char mine[rows][cols],char show[rows][cols])
 //{
	// set_mine(mine);
	// display(show);
	// Sweep(mine,show);
 //}