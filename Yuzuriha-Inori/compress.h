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
class Filecompress
{
public:
	Filecompress()
	{
		for(int i =0;i<256;i++)
		{
			_info[i].ch= i ;
			_info[i]._count=0;
		}
	}

private:
	void Compress(const char *Filename)
	{

	}
	Infor _info[256];
};