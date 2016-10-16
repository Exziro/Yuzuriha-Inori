//#include<stdio.h>
//int main()
//{
//	int i,j,k;
//	for(i=1;i<=7;i++){
//		for(j=1;j<=7-i;j++)
//			printf(" ");
//		for(k=1;k<=2*i-1;k++)
//			printf("*");
//		printf("\n");}
//	for(i=0;i<6;i++){
//		for(j=0;j<=i;j++)
//			printf(" ");
//		for(k=0;k<2*(6-i)-1;k++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//
//}
//#include<stdio.h>
//int main()
//{
//
//	int i =0;
//	int a =0;
//	int b =0;
//	int c =0;
//
//		for(i=100;i<=999;i++)
//	{
//		a=i%10;
//		c=(i-a*100)/10;
//		b=i/100;
//		if(i==a*a*a+b*b*b+c*c*c)
//		printf("%d ",i);
//		}
//		return 0;
//}

//int main()
//{
//	int n=0;
//	int i=0;
//	int j=0;
//	int k=0;
//	for(n=100;n<=999;n++)
//	{
//		i=n/100;
//		j=(n-i*100)/10;
//		k=n%10;
//        if(n==i*i*i+j*j*j+k*k*k)
//		  printf("%d ",n);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int sum=0;
//	int a;
//	int N;
//	printf("please enter an number:");
//	scanf("%d",&a);
//	sum = 5*a+4*10*a+3*100*a+2*1000*a+10000*a;
//	printf("%d ",sum);
//	return 0;
//}
#include<stdio.h>
int main()
{
	           int ch,i=0;  
        ch = getchar();  
        if ( ch=='}')  
            printf("unmatched!");  
        while ( ch !=EOF)  
        {  
            if( ch =='{')  
                i++;  
            if( ch =='}')  
                i--;  
            ch = getchar();  
        }  
        {     
            if( i == 0)  
                printf("matched!");  
            else  
                printf("unmatched!");  
      
        }  
		return 0;  }

