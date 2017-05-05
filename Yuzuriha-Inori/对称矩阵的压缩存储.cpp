#include<iostream>
using namespace std;
template<class T>
class Sym
{
public:
	Sym(T* _array,size_t n)
	{
		_arraysize=n*(n+1)/2;
		_size=n;
		_array=new T[_arraysize];

		for(size_t i=0;i<n;i++)
		{	for(size_t j=0;j<i;j++)
			{
				_array[i*(i+1)/2+j]=_array[i*n+j];
			}
	
		}
	}
	T& Getpos(size_t row,size_t col)
	{
		n=_size;
		if(row<col)
		{
			swap(row,col);
		}
		return _array[row*(row+1)/2+col];
	}
	void display()//´òÓ¡Êä³ö
	{
		size_t n=_size;
		for(size_t i=0;i<n;i++)
		{
			for(size_t j=0;j<n;j++)
				if(i<=j)
				{
					cout<<_array[i*(i+1)/2+j]<<" ";
				}
				else if(i<j)
				{
					cout<<_array[i*(j+1)/2+i]<<" ";
				}
		}
	}
private:
	T *_array;
	size_t _size;
	size_t _arraysize;
};
int main()
{
	int a[6]={1,2,3,4,5,6};
	Sym<int>b(a,7);
	b.display();
	return 0;
}