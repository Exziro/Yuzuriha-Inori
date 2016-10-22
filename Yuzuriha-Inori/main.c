#include<stdio.h>
int main()
{  int a=0;
	while(1){
	printf("***********sweep mine!!*****");
	printf("**********1.play************");
	printf("**********2.exit************");
	printf("****************************");
	scanf("%d",&a);
	switch (a)
	{case 1:game();
	case 2:break;
	default:printf("erro try again:");
		break;
	}
	break;}
