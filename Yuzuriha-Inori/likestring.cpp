#include<iostream>
using namespace std;
//class String
//{
//public:
//	String(const char *Str= "")
//	{
//		if(Str==NULL)
//		{
//			str=new char[1];
//			*str='\0';
//		}
//		else
//		{
//			str=new char[strlen(str)+1];
//			strcpy(str,Str);
//		}
//	}
//	String(const String &s)
//		:str(s.str)
//	{}
//	String &operator =(const String&s)
//	{
//		if(this!= &s)
//		{
//			delete[] str;
//			str=s.str;
//		}
//		return *this ;
//	}
//	    ~String()  
//    {  
//        if(NULL != str)  
//        {  
//            delete[] str;
//            str = NULL;  
//        }   
//    }  
//
//private:
//	char * str;
//};
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
	{
		str=new char [strlen(s.str)+1];
		strcpy(str,s.str);
	}
	String &operator =(const String &s)
	{
		    if(this != &s)  
    {  
        char* tmp = new char[strlen(s.str)+1]; 
        delete[] str;  
        strcpy(tmp,s.str);  
        str = tmp;  
    }

    return *this;
	}
	size_t Size()const
	{
		int count=0;
		while(str!='\0')
		{
			count++;
		}
		return count;
	}
	/*size_t Lengh()const;*/
	char& operator[](size_t index)
	{
		int i=0;
		while(i!=index)
		{
			i++;
		}
		return str[i];
	}
	/*const char& operator[](size_t index)const*/;
	bool operator>(const String& s)
	{

   /*	bool operator<(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	void Copy(const String& s);
	bool strstr(const String& s);
	String& operator+=(const String& s);*/
	friend ostream&operator<<(ostream & _cout,const String &s)  
    {  
        _cout<<s.str;  
        return _cout;  
    }  
private:
	char * str;
};
int main()
{
	String s1("hello");
	String s2(s1);
	String s3(NULL);
	s3=s1;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	return 0;
}

/*String& operator=(String temp)  
{  
     swap(_ptr,temp._ptr);  
     return *this;  
}*///¼ò»¯°æstringº¯Êý  