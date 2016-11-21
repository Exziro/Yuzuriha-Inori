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
//	for(i=0;i<4;i++)
//		for(j=0;j<4;j++)
//		{
//			scanf("%d",&a[i][j]);
//		}
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
//        printf("无满足字符\n");  
//    }  
//
//}
//	 void Find(char *arr, int len)  
//    {  
//        int hashtable[26] = {0};  
//        int i;  
//      
//        for(i=0;i<len;i++)  
//            hashtable[arr[i]-'a']++;  
//      
//        for(i=0;i<len;i++)  
//        {  
//            if(hashtable[arr[i]-'a'] == 1)  
//            {  
//                printf("%c\n",arr[i]);  
//                break;  
//            }  
//        }  
//      
//        if(i >= len)  
//        {  
//            printf("无满足字符\n");  
//        }  
//    } 
//int main()
//{
//	char *a="aabbccddeff";
//	int len=strlen(a);
//	Find(a,len);
//
//	system("pause");
//	return 0;
//}
//char *my_strcpy(const char *arr,char*pp)
//{
//	char *p=pp;
//	assert(*arr);
//	assert(*pp);
//
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
//char * my_strcopy(const char *src,char *dest,int n )
//{
//		char * p=dest;
//	assert(*src);
//	assert(*dest);
//
//	while(n)
//	{
//		*dest=*src;
//		*dest++;
//		*src++;
//		n--;
//	}
//	*dest='\0';
//	return p;
//}
//int main()
//{
//	char arr[]="hello world!";
//	char pp[1000];
//	my_strcopy(arr,pp,5);
//	printf("%s",pp);
//	system("pause");
//	return 0;
//}
//char *my_strcat(const char*src,char*dest)
//{
//	char *p=dest;
//	assert(*src);
//	assert(*dest);
//	while(*dest)
//	{
//		dest++;
//	}
//	while(*src)
//	{
//		*dest=*src;
//		dest++;
//		src++;
//	}
//	*dest='\0';
//}
//int main()
//{
//	char arr[]="hello world!";
//	char pp[]="hello.bit!";
//	my_strcat(arr,pp);
//	printf("%s",pp);
//	system("pause");
//	return 0;
//}
//char*my_strncat(char*src,char*dest,int n)
//	{
//	char *p=dest;
//	assert(*src);
//	assert(*dest);
//	while(*dest)
//	{
//		dest++;
//	}
//	while(n)
//	{
//		*dest=*src;
//		dest++;
//		src++;
//		n--;
//	}
//	*dest='\0';
//	return p;
//}
//int main()
//{
//	char arr[]="hello world!";
//	char pp[]="hello.bit!";
//	my_strncat(arr,pp,5);
//	printf("%s",pp);
//	system("pause");
//	return 0;
//}
//int my_strcmp(char *src,char*dest)
//{
//	assert(*src);
//	assert(*dest);
//	while(*src!=0&&*dest!=0&&*src==*dest)
//	{
//		src++;
//		dest++;
//	}
//	return *dest-*src;
//		 
//}
//int main()
//{
//	char arr[]="hello world!";
//	char pp[]="hello.bit!";
//	printf("%d",my_strcmp(arr,pp));
//	system("pause");
//	return 0;
//}
//int my_strncmp(const char*src,char*dest,int n)
//{
//	assert(*src);
//	assert(*dest);
//	while(*src!=0&&*dest!=0&&*src==*dest&&n-1)//会提前一位所以需要减去1
//	{
//		src++;
//		dest++;
//		n--;	
//	}
//	return *dest-*src;
//}
//
//int main()
//{
//	char arr[]="hello world!";
//	char pp[]="hello.bit!";
//	printf("%d",my_strncmp(arr,pp,5));
//	system("pause");
//	return 0;
//}

//void *my_memcpy(const void*src,void *dest,int n)
//{
//	char*p1=(char*)src;
//	char*p2=(char*)dest;
//	if(src==0||dest==0)
//	{
//		return NULL;
//	}
//
//	while(n)
//	{
//		*p2=*p1;
//		p1++;
//		p2++;
//		n--;
//	}
//	*p2='\0';
//}
//int main()
//{
//	char arr[]="hello world!";
//	char pp[1000];
//	my_memcpy(arr,pp,5);
//	printf("%s",pp);
//	system("pause");
//	return 0;
//}
//void * my_memmove(void *src,const void *dest,int n)
//{
//	void *ret=dest; 
//	if(src==0||dest==0){
//		return dest;}
//	 while(n--)
//	 {
//		 *(char*)dest=*(char*)src;
//		 dest=(char*)dest+1;
//		 src=(char*)src+1;
//	 }
//	 return ret;
//}
int main()
{
	char arr[]="hello world!";
	char pp[1000];
	memcpy(arr,pp,5);
	printf("%s",pp);
	system("pause");
	return 0;
}