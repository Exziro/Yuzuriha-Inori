#include<iostream>
using namespace std;
template<class T>

class Stack
{
public:
	Stack(size_t capacity = 10);
    Stack(const Stack<T>& s);
    Stack<T>& operator=(const Stack<T>& s);
	void Push(const T& x)
	{
        _CheakCapacity();
        _pData[_size]=x;
        _size++;
    }
	void Pop()
	{
		_CheakCapacity();
        _size--;
	}
	size_t Size()const
	{
		return _size;
	}
	T& Top()
	{
		return _pData[0];
	}
	const T& Top()const;
	bool Empty()const;
private:
	void _CheckCapacity()
	{
		if(_size == _capacity)
		{
			int i;
			// ����ռ�
			int a=new[_capacity*2+3];
			T* temp =a;
			memcpy(tmp,_a,sizeof(T)*_size);//memcpy
			// ����Ԫ��
			//memcpy(); ȱ�㣺ǳ���� �е㣺�ٶȿ�
			//for   // ������ȡ---Add
			for(i=0;i<_size;i++)
			{
				tmp[i]=_pData[i];
			}
			delete _pData;
			_pData=tmp��
			// �ͷžɿռ�

			// ָ���¿ռ�

			_capacity *= 2;

		}
	}
private:
	T* _pData;
	//size_t _capacity;
	//size_t _size;
};
