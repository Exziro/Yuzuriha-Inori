#include<stdio.h>
#include<windows.h>
#include<assert.h>
//char* Strstr(char * string, const char * sstring)
//{
//	int k;
//	int i;
//	int j;
//			for(i=0;string[i]!='\0';i++)
//			{
//				for(j=i,k = 0; sstring[k] != '\0'&&string[j]==sstring[k]; j++, k++)
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
 char * Strstr( char *dst, const char * src)  
    {  
		int i, j, k; 
        assert(dst);  
        assert(src);  
 
        for (i = 0; dst[i] != '\0'; i++)  
        {  
            for (j = i, k = 0; src[k] != '\0'&&dst[j] == src[k]; j++, k++)  
            {  
                ;  
            }  
            if (src[k] == '\0'&&k > 0)  
                return &dst[i];  
        }  
        return NULL;  
    } 
int main()
{
	char *a ="abcdefg";
	char *b ="cdefg";

	printf("%s",Strstr(a,b));
	system("pause");
	return 0;
}
 
    //int main()  
    //{  
    //    char *p1 = "abcdefhhju";  
    //    char *p2 = "cde";  
    //    printf("%s\n", my_strstr(p1, p2));  
    //    return 0;  
    //}  