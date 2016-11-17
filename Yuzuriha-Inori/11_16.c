#include<stdio.h>
#include<windows.h>
//int main()
//{
//	int arr[]={1,3,5,7,9,6,21};
//	int i=0;
//	int j=0;
//	int a=0;
//	for(i=0;i<sizeof(arr)/sizeof(arr[0])-1;i++)
//		for(j=0;j<sizeof(arr)/sizeof(arr[0])-i-1;j++)
//		{
//			if(arr[i]>arr[i+1])
//				{arr[i]^=arr[i+1];
//				arr[i+1]^=arr[i];
//				arr[i]^=arr[i+1];}
//		}
//		for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
//		{
//			printf("%d\n",arr[i]);
//		}
//		system("pause");
//		return 0;
//}
int fun(int a,int b)
{
	return a+b;
}
int main()
{
	int a=10;
	int b=20;
	int ret=fun(a,b);
	printf("%d\n",ret);
	return 0;
}
