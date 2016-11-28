#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//int comp(const void *a,const void *b)//自己设定的可控的返回值？
//{
//	return *(int *)b-*(int *)a;
//}
//int main()
//{
//	int i=6;
//	int arr[6]={1,4,7,2,5,8};
//	qsort(arr,6,sizeof(int),comp);
//	for(i=0;i<6;i++)
//	{
//		printf("%d\n",arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//int comp(const void *a,const void* b)
//{
//	if(*(double*)a>*(double*)b)
//		return 1;
//	if(*(double*)a>*(double*)b)
//		return -1;
//}
//int main()
//{
//	int i=0;
//	double arr[6]={1.3,2.3,7.3,5.3,9.9,9.3};
//	qsort(arr,6,sizeof(double),comp);
//		for(i=0;i<6;i++)
//	{
//		printf("%f\n",arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//int comp(const void *a,const void *b)
//{
//	 return *(char *)a - *(char *)b; 
//}
//int main()
//{
//	int i=0;
//	char arr[]="hello oowowoowowoowo";
//	qsort(arr,6,sizeof(char),comp);
//	for(i=0;i<6;i++)
//	{
//		printf("%c\n",arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//void my_buuble(double *a,int n)
//{
//	int i;
//	int j;
//	double p;
//	int flag=0;
//	for(i=0;i<n;i++)
//	{	for(j=0;j<n-i-1;j++)
//		{
//			if(a[j]>a[j+1])
//			{	a[j]=p;
//				a[j]=a[j+1];
//				a[j+1]=p;
//				//{a[j]^=a[j+1];
//				//a[j+1]^=a[j];
//				//a[j]^=a[j+1];
//			}
//		}
//    }
//}
////int main()
////{ 
////	int i;
////	char a[]="abcfdfghj";
////	my_buuble(a,9);
////	for(i=0;i<9;i++)
////		printf("%c",a[i]);
////	system("pause");
////	return 0;
////}
//int main()
//{ 
//	int i;
//	double a[]={1.3,2.3,0.3,4.3};
//	my_buuble(a,4);
//	for(i=0;i<4;i++)
//		printf("%f",a[i]);
//	system("pause");
//	return 0;
//}