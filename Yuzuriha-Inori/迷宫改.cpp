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
	/*Map(const string& filepath);*///��ȡ�ļ��еĵ�ͼ
private:
	bool ispass(int _row,int _col,int a[][10]);//�ж��ǲ��ǿ�·
public:
	void _printf(int a[][10]);//��ӡ���
	~Map();
};
bool Map::ispass(int _row,int _col,int a[][10])
{
	if(_row>10||_col>10)
	{
		return true;
	}
	if(a[_row][_col]!=0)
	{
		a[_row][_col]=2;
		if(ispass(_row-1,_col,a))
		{
			return true;
		}
		if(ispass(_row,_col+1,a))
		{
			return true;
		}
		if(ispass(_row+1,_col,a))
		{
			return true;
		}
		if(ispass(_row,_col-1,a)==1)
		{
			return true;
		}


	}
		
	return false;

}
void Map::_printf(int a[][10])
{
	    for (int row = 0; row<_row; ++row)  
    {  
        for (int col = 0; col<_col; ++col)  
        {  
            cout << a[row][col] << " ";  
        }  
        cout <<endl;  
    }  
    cout <<endl;  
}  
