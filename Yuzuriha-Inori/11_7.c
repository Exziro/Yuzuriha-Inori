#include<stdio.h>
#include<windows.h>
#include<string.h>
//int del_substr(char *str,char const *substr)  
//{  
//    char const *subp;  
//    char *strp = str;  
//    char *temp ;  
//    int flag = 1;  
//  
//    if((!*str)||(*substr == '\0'))//如果主串为空或子串为空字符串，则返回  
//    {  
//        return 0;  
//    }  
//    while(*strp)  
//    {  
//        temp = strp;  
//        for(subp = substr;*subp;subp++)  
//        {  
//            if(*strp == *subp)//如果当前的主串和子串字符相等  
//            {  
//                strp++;      //则主串指针向前移一个字符  
//                flag = 0;    //设置为false，防止后续的主串指针，重复移动  
//                continue;       
//            }  
//            break;  
//        }  
//        if(*subp == '\0')     //如果subP指向末尾的'\0'则表示子串匹配成功  
//        {  
//            while(*temp++ = *strp++)//进行字符复制  
//            {  
//                ;  
//            }  
//            break;  
//        }  
//        if(flag)  
//        {  
//            strp++;  
//        }  
//    }  
//    return 1;  
//}  
//int main()  
//{  
//    char str1 [] = "abcdefgh";  
//    char const * str2= "bcd";  
//  
//    printf("before delete: %s\n", str1);  
//    printf("will delete che chars: %s\n", str2);  
//    del_substr(str1, str2);  
//    printf("After delete: %s\n", str1);  
//	system("pause");
//    return 0;  
//} 
//int moarl(char *string,int n)
//{
//	int a;
//	char *p;
//
//int main()
//{
//
//int reverse(char * arr)
//{
//	char *left=arr;
//	char *right=strlen(*arr);
//}
//char * conserve ( char * left,char*right )  //逆序字符串
//{  
//       // char *start = string;  
//       // char *left = string;  
//       // char ch;  
// 
//       // while (*string++)                 
//       //         ;  
//       //// string -= 2;  
//	char ch;
// 
//        while (left < right)  
//        {  
//                ch = *left;  
//                *left = *right;  
//                *right= ch;  
//					left++;
//					right--;
//        }  
//
//          
//} 
//void rotate(char * string,int n)//左旋
//{      
//        int i=strlen(string);
//		conserve(string,string+n-1);
//		conserve(string+n,string+i-1);
//		conserve(string,string+i-1);
//		
//}
//int main()
//{
//	char a[]="abcdef";
//	rotate(a,1);
//	printf("%s",a);
//	system("pause");
//	return 0;
//}


int Strstr(char*arr,char*string)
{
	int i,j,k;
	int count=0;
	int counts=0;
	int len=strlen(arr);
	while(1)
	{
		while(*arr!='0')
		{if(*arr++==*string)
			{*string++;
			counts++;}
		if(*string=='\0')
			break;
		if(*arr=='\0')
		{
			count++;
			arr=arr-len;
		}
		}
		if(count==1)
			break;
	}
	if(counts==6)
		return 1;
	else return 0;
}
int main()
{
	int i;
	char a[]="abcdef";
	char b[]="cdefab";
	i=Strstr(a,b);
	printf("%d",i);
	system("pause");
	return 0;
}

