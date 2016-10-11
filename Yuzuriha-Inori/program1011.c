#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int first()
{
	printf("****guess number!!**\n");
	printf("********************\n");
	printf("*******1.start******\n");
	printf("*******2.excit******\n");
	return 0;
}
int game(int b)
{	int a;
while(1)
	{scanf("%d",&a);
	if(a==b)
	{	printf("Congratulation!!\n");
	break;
	}
	if(a<b)
	{printf("太小了。Try again\n");}
	else
	{printf("太大了。Try again\n");}
	}


}
int main()
{   int a;
	int b;

while(1){
	first();
printf("请输入操作:");
scanf("%d",&a);
switch(a){
	case 1:	srand((unsigned int)time(NULL));
	b = rand()%100;
	printf("please enter a number:");
	game(b);
	continue;
case 2:
	break;}
break;
}
return 0;
}