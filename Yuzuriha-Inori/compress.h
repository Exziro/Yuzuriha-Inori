#include<iostream>
using namespace std;
#include"Btree.hpp"
struct Infor
{
	Infor(int count =0)
		:_count(count)
	{
	}
	bool operator<(const Infor infor)
	{
		return _count<infor._count;
	}
	bool operator>(const Infor infor)
	{
		return _count>infor._count;
	}
		bool operator=(const Infor infor)
	{
		return _count=infor._count;
	}
		Infor operator+(const Infor infor)
	{
		return _count+infor._count;
	}
	char ch;
	int _count;
	string _code;
};
//class compress
//{
