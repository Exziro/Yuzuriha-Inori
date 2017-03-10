#include<iostream>
using namespace std;
template<typename T>
T Add(T left,T right)
{
	return (right+left);
}
int main()
{
	cout<<Add(10,20)<<endl;
	cout<<Add(1.0,2.0)<<endl;
	cout<<Add('1','2')<<endl;
	system("pause");
	return 0;
	
}
typedef int DataType;
//typedef char DataType; class SeqList { private :          DataType* _data ;     int _size ;     int _capacity ; }