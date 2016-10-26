//#include<stdio.h>
//int main()
//{
//	int a;
//	int arr[32];
//	int brr[32];
//	int b;
//	int i=0;
//	int count=0;
//	printf("please enter two number:");
//	scanf("%d %d",&a,&b);
//	for(i=0;a!=0;i++)
//	{
//	arr[i]=a%2;
//		a=a/2;
//	}
//	for(i=0;b!=0;i++)
//	{   
//		brr[i]=b%2;
//		b=b/2;
//	}
//	for(i=0;i<32;i++)
//	{
//		if(arr[i]!=brr[i])
//			count++;
//	}
//	printf("they have %d diffrence.\n",count);
//	return 0;
//}
//unsigned int reverse_bit(unsigned int value)
//{
//	int mid = 0;
//	int i =32;
//	int num;
//	for(i=31;i>0;--i)
//		{num=value&1;
//		mid=mid|num;
//		mid<<=1;
//		value>>=1;
//	}
//	return mid;
//}
//
//#include<stdio.h>
//int main()
//{
//	int value=0;
//	int result;
//	printf("please enter a number:");
//	scanf("%d",&value);
//	result=reverse_bit(value);
//	printf("reverse number:%u\n",result);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[9]={1,3,5,7,1,3,5,8,8};
	int i=0;
	int t=0;
	int j=0;
	int count = 0;
	for(i=0;i<9;i++)
		{t=arr[i];
	count=0;
		for(j=0;j<9;j++)
			if(1==arr[j]^t)
			{
			count++;}
			
		if(8==count)
	{printf("The single dog is %d\n",arr[i]);
	break;}}
	return 0;
}

