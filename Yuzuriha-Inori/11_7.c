#include<stdio.h>
#include<windows.h>
int del_substr(char *str,char const *substr)  
{  
    char const *subp;  
    char *strp = str;  
    char *temp ;  
    int flag = 1;  
  
    if((!*str)||(*substr == '\0'))//如果主串为空或子串为空字符串，则返回  
    {  
        return 0;  
    }  
    while(*strp)  
    {  
        temp = strp;  
        for(subp = substr;*subp;subp++)  
        {  
            if(*strp == *subp)//如果当前的主串和子串字符相等  
            {  
                strp++;      //则主串指针向前移一个字符  
                flag = 0;    //设置为false，防止后续的主串指针，重复移动  
                continue;       
            }  
            break;  
        }  
        if(*subp == '\0')     //如果subP指向末尾的'\0'则表示子串匹配成功  
        {  
            while(*temp++ = *strp++)//进行字符复制  
            {  
                ;  
            }  
            break;  
        }  
        if(flag)  
        {  
            strp++;  
        }  
    }  
    return 1;  
}  
int main()  
{  
    char str1 [] = "abcdefgh";  
    char const * str2= "bcd";  
  
    printf("before delete: %s\n", str1);  
    printf("will delete che chars: %s\n", str2);  
    del_substr(str1, str2);  
    printf("After delete: %s\n", str1);  
	system("pause");
    return 0;  
} 