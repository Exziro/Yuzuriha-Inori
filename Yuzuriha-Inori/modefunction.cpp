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
	system("pause");
	return 0;
	
}
