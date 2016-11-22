#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<assert.h>
//void change(int *a,int len)
//{
//	        int i=0;
//        int j=len-1;
//        int temp;
//        while(i<j){
//            if(a[i]%2==1){
//                i++;
//                continue;
//            }
//
//            if(a[j]%2==0){
//                j--;
//                continue;
//            }
//
//            temp=a[i];
//            a[i]=a[j];
//            a[j]=temp;
//            i++;
//            j--;
//        }
//}
//int main()
//{
//	int i=0;
//	int a[]={1,2,3,4,5,6,7,8,9,10};
//	int len=sizeof(a)/sizeof(a[0]);
//	change(a,len);
//	for(i=0;i<len;i++)
//	{
//		printf("%d\n",a[i]);
//	}
//	system("pause");
//	return 0;
//}
//int Find(int arr[4][4],int target)
//{  
//    int i =0, j =4-1;  
//
//    while(j>=0&&i<4)  
//      {  if(arr[i][j]==target)  
//			return 1;  
//        else if (arr[i][j]<target && i<3)  
//            i++;  
//        else if(arr[i][j]>target && j>0)  
//			j--;  
//		}  return -1;
//}
//
//int main()
//{
//	int d=0;
//	int a[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
//	int b=4;
//	//for(i=0;i<4;i++)
//	//	for(j=0;j<4;j++)
//	//	{
//	//		scanf("%d",&a[i][j]);
//	//	}
//	d=Find(a,b);
//	if(d==1)
//		printf("Yes");
//	else
//		printf("No");
//		system("pause");
//		return 0;
//}
//void Find(char *arr,int len)
//{
//	int s[26]={0};
//	int i=0;
//	for(i=0;i<len;i++)
//	{
//		s[arr[i]-'a']++;
//	}
//	for(i=0;i<len;i++)
//	{	if(s[arr[i]-'a']==1)
//			{printf("the number is%c",arr[i]);
//			break;}
//	}   
//	if(i >= len)  
//    {  
//        printf("ÎÞÂú×ã×Ö·û\n");  
//    }  
//
//}
 /*   void Find(char *arr, int len)  
    {  
        int hashtable[26] = {0};  
        int i;  
      
        for(i=0;i<len;i++)  
            hashtable[arr[i]-'a']++;  
      
        for(i=0;i<len;i++)  
        {  
            if(hashtable[arr[i]-'a'] == 1)  
            {  
                printf("%c\n",arr[i]);  
                break;  
            }  
        }  
      
        if(i >= len)  
        {  
            printf("ÎÞÂú×ã×Ö·û\n");  
        }  
    }  */
//int main()
//{
//	char *a="aabbccddeff";
//	int len=strlen(a);
//	Find(a,len);
//	//printf("%c",Find(a,len));
//	system("pause");
//	return 0;
////}
//char *my_strcpy(const char *arr,char*pp)
//{
//	assert(*arr);
//	assert(*pp);
//	char *p=pp;
//	while(*pp)
//	{
//		*pp=*arr;
//		pp++;
//		arr++;
//	}
//
//	*pp='\0';
//	return p;
//}
//int main()
//{
//	char arr[]="hello world!";
//	char pp[1000];
//	my_strcpy(arr,pp);
//	printf("%s",pp);
//	system("pause");
//	return 0;
//}
int fun(int a,int b)
{
	return a+b;
}
int main()
{
	int a=0xaaaaaaaa;
	int b=0xbbbbbbbb;
	int ret=fun(a,b);
	printf("%d\n",ret);
	system("pause");
	return 0;
}