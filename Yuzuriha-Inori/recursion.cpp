#include<iostream>
using namespace std;
int Fib(int Fisrt,int second,int n)
{
	if(n<3)
	{
		return 1;
	}
	if(3==n)
	{
		return Fisrt+second;
	}
	return Fib(second,Fisrt+second,n-1);
}

