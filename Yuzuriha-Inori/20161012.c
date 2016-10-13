//#include<stdio.h>
//int main()
//{
//	int arr[]={1,2,3,4,5,6,7,8,9,};
//	int key =7;
//	int left = 0;
//	int right= sizeof(arr)/sizeof(arr[0]);
//	while(left<= right){int mid =(right-left)/2+left;
//		if(arr[mid]<key)
//		{
//			left=mid+1;
//		}
//		else if(arr[mid]>key)
//		{
//			right = mid - 1;
//		}
//		else{
//			printf("找到了，数字为%d\n",arr[mid]);
//		
//		break;}}
//	return 0;
//
//}
//#include<stdio.h>
//int main()
//{
//	int i,j,n=0;
//	int a[100][100]={0};
//	while(n<1||n>100)
//	{printf("请输入层数:");
//	scanf("%d",&n);}
//	for(i=0;i<n;i++)
//		a[i][0]=1;
//	for(i=1;i<n;i++){
//		for(j=1;j<=i;j++)
//		a[i][j]=a[i-1][j-1]+a[i-1][j];
//	}
//
//	for(i=0;i<n;i++)
//	{for(j=0;j<=i;j++)
//	printf("%5d",a[i][j]);
//	printf("\n");}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a,b,c,d,e;
//	for(a=1;a<=5;a++)
//		for(b=1;b<=5;b++)
//			for(c=1;c<=5;c++)
//				for(d=1;d<=5;d++)
//					for(e=1;e<=5;e++)
//						/*if((b==1)+(a==3)==1&&(b==2)+(e==4)==1&&(c==1)+(d==2)==1&&(c==5)+(d==3)==1&&(e==4)+(a==1)==1)*/
//						if ((b == 1) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1)
//
//
//						{printf("a=%d,b=%d,c=%d,d=%d,e=%d\n",a,b,c,d,e);
//							break;}
//						
//					return 0;
//}
#include<stdio.h>
int main()
{
	char killer;
	killer='A';
	for(killer='A';killer<='D';killer++)
	{
		if((killer!='A')+(killer=='C')+(killer=='D')+(killer!='D')==3)
			{printf("%c是凶手\n",killer);
		break;}
	}
	return 0;
}