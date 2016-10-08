//#include<stdio.h>
//int main()
//{
//	int a[10],i;
//	int max = 0;
//	printf("请输入十个数：");
//	for(i=0;i<10;i++)
//	{	
//		scanf("%d",&a[i]);
//	}
//	for(i=0;i<10;i++)
//	{
//		if(a[i]>max)
//			max=a[i];
//	}
//	printf("%d",max);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a,b;
//	for(a=2;a<=100;a++)
//	{
//		for(b=2;b<=a-1;b++)
//		{
//			if(a%b==0)
//			break;
//		}
//			if(b>=a)
//			printf("%d\n",a);}
//		return 0;	
//}
//#include<stdio.h>
//int main()
//{
//	int i,j,n;
//
//	for(i=2;i<=100;i++)
//	{
//		for(j=2;j<=i-1;j++)
//		{
//			if(i%j==0)
//				break;
//		}
//		if(j>=i)
//		  printf("%d\n",i);
//	}
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a,b,c,e,f;
//	scanf("%d%d",&a,&b);
//	e=a;f=b;
//	while(b!=0)
//	{
//    c=a%b;
//	a=b;
//	b=c;
//	}
//	printf("最大公约数为%d",e*f/a);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int a;
	int b;
	printf("please enter two number:");
		scanf("%d %d",&a,&b);
		a = a^b;
		b = a^b;
		a = a^b;
	printf("change number: %d %d",a,b);
	return 0;
}