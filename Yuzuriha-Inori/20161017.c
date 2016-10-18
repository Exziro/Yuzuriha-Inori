//#include<stdio.h>
//int mul(int a)
//{
//	int i;
//	int j;
//	for(i=1;i<=a;i++){
//		for(j=1;j<=i;j++){
//			printf("%d*%d=%d ",i,j,i*j);}
//		printf("\n");}
//}
//
//
//int main()
//{
//	int a;
//	int i;
//	int j;
//	printf("please enter a number:");
//	scanf("%d",&a);
//	mul(a);
//	return 0;
//}
//#include<stdio.h>
//int change(int*a,int*b)
//
//{int temp;
//temp=*b;
//*b=*a;
//*a=temp;
//}
//
//int main()
//{
//	int a=6;
//	int b=5;
//	printf("First:%d %d\n",a,b);
//	change(&a,&b);
//	printf("change:a=%d b=%d\n",a,b);
//	return 0;
//}
//#include<stdio.h>
//int def(int a)
//{ {if(a%4==0&&a%100!=0||a%400==0)
//printf("yes");
//else
//printf("NO");
//}
//}
//int main()
//{
//	int year,a;
//	printf("please enter a number:");
//	scanf("%d",&year);
//	a=def(year);
//		return 0;}

//#include<stdio.h>
//int primer(int a)
//{
//	int i=0;
//	for(i=2;i<a;i++)
//	{
//		if(a%i==0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int a=0,s;
//	printf("please enter a number:");
//	scanf("%d",&a);
//	s=primer(a);
//	if(s=0)
//		printf("NO");
//	else
//		printf("Yes");
//	return 0;
//}
#include<stdio.h>
int init()
{	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
}
int empty(int arr[])
{
	int i=0;
	for(i=0;i<10;i++);
	arr[i]=0;
	for(i=0;i<10;i++);
	printf("%d\n ",arr[i]);
}
//int reverse(int arr[],int size)
//			
//{
//	int i,j;
//	int temp =0;
//	for(j=size;j>(size/2);j--)
//		for(i=0;i<(size/2);i++)
//		temp=arr[j];
//		arr[j]=arr[i];
//		arr[i]=temp;
//	for(i=0;i<10;i++)
//		printf("%d \n",arr[i]);
//}
void reverse(int data[],int n)
{
	int i,j,t;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t=data[i];
		data[i]=data[j];
		data[j]=t;}
		{for(i=0;i<10;i++)
		printf("%d",data[i]);
	}
} 
int main()
{

	int a=0;
	int i = 10;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	while(1)
	{
	printf("please choice something you want:\n");
	printf("1.init arr\n 2.empty arr\n 3.reverse arr\n");
	scanf("%d",&a);
		switch (a)
		{case 1: init();break;
		case 2: empty(arr);break;
		case 3: reverse(arr,i);break;

		

		default:printf("erro");
			break;
	}
	}
		return 0;
}

