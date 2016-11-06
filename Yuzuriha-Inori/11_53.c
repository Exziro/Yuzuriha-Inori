#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<string.h>
//char* Strstr(char * string, const char * sstring)
//{
//	int k;
//	int i;
//	int j;
//			for(i=0;string[i]!='\0';i++)
//			{
//				for(j=i,k = 0; sstring[k] != '\0'&&string[j] == sstring[k]; j++, k++)
//				{
//					;
//				}
//					if(string[k]=='\0'&&k>0)
//                    return &string[i];
//				
//			
//			
//			}
//		return NULL;
//
//	}
// char * Strstr( char *dst, const char * src)  
//    {  
//		int i, j, k; 
//        assert(dst);  
//        assert(src);  
// 
//        for (i = 0; dst[i] != '\0'; i++)  
//        {  
//            for (j = i, k = 0; src[k] != '\0'&&dst[j] == src[k]; j++, k++)  
//            {  
//                ;  
//            }  
//            if (src[k] == '\0'&&k > 0)  
//                return &dst[i];  
//        }  
//        return NULL;  
//    } 
//int main()
//{
//	char *a ="abcdefg";
//	char *b ="cdefg";
//
//	printf("%s",Strstr(a,b));
//	system("pause");
//	return 0;
//}
//char *conserve(char *string,int len)
//{
//	char * start=string;
//	char * end=string+len-1;
//	//int len=0;
//	char change=0;
//	int i;
//	//for(len=0;string[len]!=0;len++)
//	//{
//	//	;
//	//}
//	//start=string;
//	//end=string+len-1;
//	if(string!=NULL)
//	{
//	while(start<end)
//	{
//		*end=change;
//		*end=*start;
//		*start=change;
//		start++;
//		end--;
//	}
//	}return start;
//
//}
//char * conserve ( char * string )  
//{  
//        char *start = string;  
//        char *left = string;  
//        char ch;  
// 
//        while (*string++)                 
//                ;  
//        string -= 2;  
// 
//        while (left < string)  
//        {  
//                ch = *left;  
//                *left++ = *string;  
//                *string-- = ch;  
//        }  
// 
//        return(start);  
//} 
//int main()
//{
//	char a[]="helelelelelel";
//	int len=strlen(a);
//	printf("%d\n",len);
//	printf("%s",conserve(a,len));
//	system("pause");
//	return 0;
//}
int main()
{
  int q =0;
  int a=20;
  int c=0;//最初的瓶数需要保存
  int s=0;
  c=a;
  while(a!=1)//最后一瓶没法换
  {
	  s=(a+a%2)/2;
	  q=s+q;
	  a=a/2;
  }
  c=q+c;
  printf("%d\n",c);
  system("pause");
  return 0;
}
