
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
int get_mine(char mine[rows][cols],int x,int y)//判断上下左右的雷数
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
	int ret =0;
    int x = 0;  
    int y = 0;
	int a=0;
	int b =0;
	printf("please number：\n");
	scanf("%d%d", &x, &y); 
	if (mine[x][y] == '1')
	{       a=rand()%rows;
			b=rand()%cols;
			if(mine[a][b]=='0')
		{
			mine[a][b]='1';
		}
			{ flower(mine,show,x,y);}  
            //set_mine(mine);  
            display(show);
			count++;}

	
	else
	{       flower(mine,show,x,y); 
            //set_mine(mine);  
            display(show);
			count++;

	}
    while (count!=((rows-2)*(cols-2)-mine_number))  
    {  
        printf("please number：\n");  
        scanf("%d%d", &x, &y);  
        if (mine[x][y] == '1')  
        {  
            printf("you are die!!\n");  
      
       goto flag;}  
        else  
        {  
            int ret = get_mine(mine, x, y);  
            show[x][y] = ret + '0';  
            //set_mine(mine);  
            display(show);  
            count++;  
        }  
    }  
    printf("congratulation！\n");
	flag:
    display(mine);  
      
}  
 //int game(char mine[rows][cols],char show[rows][cols])
 //{
	// set_mine(mine);
	// display(show);
	// Sweep(mine,show);
 //}
void flower(char mine[rows][cols],char show[rows][cols],int x,int y)
{    int ret1,ret2,ret3,ret4,ret5,ret6,ret7,ret8;
	 int ret = get_mine(mine, x, y);
	 show[x][y] = ret + '0';
	 ret1=get_mine(mine, x-1, y-1);
	 show[x-1][y-1] = ret1 + '0';
	 ret2=get_mine(mine, x, y-1);
	  show[x][y-1] = ret2 + '0';
	 ret3=get_mine(mine, x+1, y-1);
	   show[x+1][y-1] = ret3 + '0';
	 ret4=get_mine(mine, x+1, y);
		show[x+1][y] = ret4 + '0';
     ret5=get_mine(mine, x+1, y+1);
		 show[x+1][y+1] = ret5 + '0';
     ret6=get_mine(mine, x, y+1);
		  show[x][y+1] = ret6 + '0';
     ret7=get_mine(mine, x-1, y+1);
		   show[x-1][y+1] = ret7 + '0';
	 ret8=get_mine(mine, x-1, y);
			show[x-1][y] = ret8 + '0';
}