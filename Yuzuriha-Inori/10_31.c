//#include<stdio.h>
//#include<string.h>
//void change(char * arr)
//{
//	int i =0;
//	int j=0;
//	int count;
//	int len = strlen(arr);
//	for (i = 0; i < len; i++)
//	{
//		if(arr[i]==' ')
//			count++;
//
//	}
//	j=count*2+len;
//	while (/*i>=0&&*/i!=j)
//	{
//		if(arr[i]==' ')
//		{
//			arr[j--]='%';
//			arr[j--]='0';
//			arr[j--]='2';
//			i--;
//
//	}
//		else
//		{
//			arr[j--]=arr[i--];
//		}
//	}
//}
//#include <stdio.h>
//#include<string.h>
//void change(char arr[])
//{
//	int len =strlen(arr);
//	int i=0;
//	int j=0;
//	int count =0;
//	for(;i<len;i++)
//	{
//		if(arr[i]==' ')
//		count++;	
//	}
//	i=len;
//	j=2*count+len;
//	while(i!=j)
//	{
//		if(arr[i]==' ')
//		{
//			arr[j--]='0';
//			arr[j--]='2';
//			arr[j--]='%';
//			i--;	
//		}	
//		else 
//		{
//			arr[j--]=arr[i--];	
//		}
//	}
//		
//}
//int main()
//{
//	char a[]="we are happy";
//	int i=0;int k;
//	change(a);
//	k=strlen(a);
//	for(i = 0; i< k;i++)
// {
//  printf("%c",a[i]);
// }
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
// char arr[] = "we are happy.";
// int i = 0;
// int j = 0;
// int len = 0;
// int count = 0;
// len = strlen(arr);
// for(i = 0;i < len;i++)
// {
//  if(arr[i] == ' ')
//  {
//   count ++; 
//  }  
// }
// i = len;
// j = 2 * count + len;
// while(i != j && i >= 0)
// {
//  if(arr[i] == ' ')
//  {
//   arr[j--] = '0';
//   arr[j--] = '2';
//   arr[j--] = '%';
//   i--;
//  }
//  else
//  {
//   arr[j] = arr[i];
//   j--;
//   i--; 
//  }
// }
// len = strlen(arr);
// for(i = 0; i< len ;i++)
// {
//  printf("%c",arr[i]);
// }
// printf("\n");
// return 0; 
//}
#include <stdio.h>  
#include <assert.h>  
void replace(char *src)  
{    
    int OldLen = 0;                    
    int NewLen = 0;                   
    int BlackNum = 0;                  
    int NewBack = 0;                   
    int OldBack = 0;                   
    while (src[OldLen] != '\0')  
    {  
        if (src[OldLen] == ' ')  
        {  
            BlackNum++;  
        }  
        OldLen++;  
    }  
    NewLen = OldLen + BlackNum * 2;  
    OldBack = OldLen-1;  
    NewBack = NewLen - 1;  
    while (OldBack!=0)  
    {  
        if (src[OldBack] == ' ')  
        {  
            src[NewBack--] = '0';  
            src[NewBack--] = '2';  
            src[NewBack] = '%';  
        }  
        else  
        {  
            src[NewBack] = src[OldBack];  
        }  
        OldBack--;  
        NewBack--;  
    }  
}  
int main()  
{  
    char p[20] = "we have fun!!";  
    replace(p);  
    printf("%s\n", p);  
    return 0;  
    return 0;  
}
//#include<stdio.h>
//int Strlen(char * arr)
//{
//	int count =0;
//	int i = 0;
//    while(arr[i]!='\0')
//	{count++;
//	i++;
//    }
//	return count;
//}
//
//char Reverse(char *start,char *stop)
//{
//	char temp;
//	while(start<stop)
//	{
//		temp=*start;
//		*start=*stop;
//		*stop=temp;
//	stop--;
//	start++;
//
//	}
//}
//
//char S_reverse(char *arr,int len)
//{
//	char *str=arr;
//	char *left=arr;
//	char *right=arr+len-1;
//	Reverse(left,right);
//	while(*str)
//	{
//		left=str;
//		while((*str !='\0')&&(*str!=' '))
//		{
//			str++;
//		}
//		right = str-1;
//		Reverse(left,right);
//		if(*str==' ')
//		{
//			str++;
//		}
//	}
//}
//int main()
//{
//	char arr[]="student a am i";
//	int len=Strlen(arr);
//	S_reverse(arr,len);
//	printf("%s\n",arr);
//	return 0;
//}