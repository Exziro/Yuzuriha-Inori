//#include<stdio.h>
//char* Strcpy(char * dest,const char * src)
//{       int i =0;
//		char * temp =dest;
//		if(dest == NULL || src == NULL)
//           return NULL;
//		if(src[i]!='\0'){
//			dest[i]=src[i];
//			i++;
// 	}
//		return dest;
//}
//char *Strcpy(char *strDest, const char *strSrc){
//	    char *tempptr = strDest ;
//    if(strDest == NULL || strSrc == NULL)
//        return NULL;
//    
//    if(strDest == strSrc)
//        return strDest;
//
//    while( (*strDest++ = *strSrc++) != '\0');
//        return tempptr ;
//}
//
//int main()
//{
//	char a[]="hello world";
//	char b[20];
//    int i =0;     
//	printf("%s",Strcpy(b,a));
//return 0;
//}
#include<stdio.h>

int Strlen(const char *str)  
{   
	int len = 0;
    if(str==NULL) return 0;

    for(; *str != '\0';*str++ )
    {
        len++;
    }
    return len;
}
int main()
{      
	    int i=0;
        char a[]="hello world";
		i=Strlen(a);
		printf("%d",i);
        return   0;
}
