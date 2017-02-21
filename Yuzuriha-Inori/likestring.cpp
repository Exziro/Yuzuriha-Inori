#include<iostream>
using namespace std;
class String
{
public:
	String(const char *Str= "")
	{
		if(Str==NULL)
		{
			str=new char[1];
			*str='\0';
		}
		else
		{
			str=new char[strlen(str)+1];
			strcpy(str,Str);
		}
	}
	String(const String &s)
		:str(s.str)
	{}
	String &operator =(const String&s)
	{
		if(this!= &s)
		{
			delete[] str;
			str=s.str;
		}
		return *this ;
	}
	    ~String()  
    {  
        if(NULL != str)  
        {  
            delete[] str;//释放指针所指向的内容   
            str = NULL;//将指针置为空      
        }   
    }  

private:
	char * str;
};
