#include<stdio.h>
#include<windows.h>
int del_substr(char *str,char const *substr)  
{  
    char const *subp;  
    char *strp = str;  
    char *temp ;  
    int flag = 1;  
  
    if((!*str)||(*substr == '\0'))//�������Ϊ�ջ��Ӵ�Ϊ���ַ������򷵻�  
    {  
        return 0;  
    }  
    while(*strp)  
    {  
        temp = strp;  
        for(subp = substr;*subp;subp++)  
        {  
            if(*strp == *subp)//�����ǰ���������Ӵ��ַ����  
            {  
                strp++;      //������ָ����ǰ��һ���ַ�  
                flag = 0;    //����Ϊfalse����ֹ����������ָ�룬�ظ��ƶ�  
                continue;       
            }  
            break;  
        }  
        if(*subp == '\0')     //���subPָ��ĩβ��'\0'���ʾ�Ӵ�ƥ��ɹ�  
        {  
            while(*temp++ = *strp++)//�����ַ�����  
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