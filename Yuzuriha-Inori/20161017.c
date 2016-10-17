#include<stdio.h>
int mul(int a)
{
	int i;
	int j;
	for(i=1;i<=a;i++){
		for(j=1;j<=i;j++){
			printf("%d*%d=%d ",i,j,i*j);}
		printf("\n");}
}


int main()
{
	int a;
	int i;
	int j;
	printf("please enter a number:");
	scanf("%d",&a);
	mul(a);
	return 0;
}
