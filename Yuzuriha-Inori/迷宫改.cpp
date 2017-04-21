#include<iostream>
using namespace std;
class Seat
{
public:
	Seat(int _x,int _y)
		:x(_x)
		,y(_y)
	{}
	int x;
	int y;
};
class Map
{
private:
	int** _map;
	int _row;
	int _col;
	/*Map(const string& filepath);*///读取文件中的地图
private:
	bool ispass();
public:
	bool goprint();
	void printf();
	~Map();
}

