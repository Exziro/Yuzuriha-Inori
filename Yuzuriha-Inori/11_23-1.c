#include<stdio.h>
#include<windows.h>
//void select_Find(int *arr,int len)
//{
//
//	int i=0;
//	int j=0;
//	for(i=0;i<len;i++)
//	{
//		for(j=i+1;j<len;j++)
//		{if(arr[i]<arr[j])
//		{arr[i]^=arr[j];
//		arr[j]^=arr[i];
//		arr[i]^=arr[j];}
//		}
//	}
//}
//int main()
//{
//	int i=0;
//	int a[6]={5,6,7,9,8,10};
//	select_Find(a,6);
//	for(i=0;i<6;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	system("pause");
//	return 0;
//}
//void recursion(int a)
//{
//	int m;
//	int num=0;
//  if (a < 10)
//	 { num=num+a;
//  printf("%d\n", a);}
//  else
//  {
//    recursion(a/10);
//	m=a%10;
//	num=m+num;
//	printf("%d\n", num);
//  }
//}
// 
//int main()
//{
//	int a=6639;
//	recursion(a);
//	system("pause");
//	return 0;
//}
int my_pow(int a,int n)
{

	if(n+1)
	{
		my_pow(a,n-1);
		a=a*a;
	}
}
int main()
{
	int a=3;
	int i=my_pow(a,3);
	printf("%d",i);
	system("pause");
	return 0;
}