#include<iostream>
using namespace std;
int typedef DataType;
class Vector
{
public:
	explicit Vector(size_t capacity = 3);

	// 有size个值为data的元素
	Vector(size_t n, const DataType& data);

	Vector(const Vector& v)
		: _capacity(v._capacity)
		, _size(v._size)
	{
		_pData = new DataType[_capacity];

		// 比较1和2的优缺点？
		// 1
		//memcpy(_pData, v._pData, sizeof(DataType)*_size);

		// 2
		for(size_t idx = 0; idx < _size; ++idx)
			_pData[idx] = v._pData[idx];
	}

	Vector& operator=(const Vector& v);

	~Vector();

	/////////////////////////////////////
	void PushBack(const DataType& data)
	{
		if(IsFull())
		{_pData[_size]=data;
		}
		else
			cout<<"the Capacity is full"<<endl;
	}

	
	void PopBack()
	{
		if(IsEmpty()){
			cout<<"the Capacity is empty"<<endl;
		}
		else
			_size--;
	}

	void Insert(size_t pos, const DataType& data)
	{
		if(pos>_capacity){
			cout<<"wrong number"<<endl;
		}
		else
		_pData[pos-1]=data;
	}
	void Erase(size_t pos)
	{
		_pData[pos-1]='/0';
		_size--;
	}

	int Find(const DataType& data)const
	{
		int n=0;
		while(_pData[n])
		{
			if(_pData[n]==data)
			{
				return n;
			}
			n++;
		}
		cout<<"no find"<<endl;
	}
	void Clear()
	{
		_size=0;
	}
	size_t Size()const;


	void ReSize(size_t size, const DataType& data = DataType())
	{
		if(_size>size)
		{
			delete[_size-size]_pData;
		}
		else if(_size<size)
		{
			_pData = new DataType[_size+size];
		}
	}
	size_t Capacity()const;
	bool Empty()const
	{
		if(_size==0)
			return 1;
		else
			return 0;
	}

	DataType& Front()
	{
		return _pData[0];
	}
	const DataType& Front()const
	{
		return _pData[0];
	}
	DataType& Back()
	{
		int n=0;
		while(_size!=n)
		{
			if(_pData[n]!=0){
				n++;
			}
		}
		return _pData[n];
	}
	const DataType& Back()const
	{
		int n=0;
		while(_size!=n)
		{
			if(_pData[n]!=0){
				n++;
			}
		}
		return _pData[n];
	}
	DataType& operator[](size_t index)
{  
        if(index < _size)  
        {  
            return _pData[index];  
        }  
    } 
	const DataType& operator[](size_t index)const
	{
		
			return _pData[index];
    }
	private:
		void _CheckCapacity();
		    bool IsFull()  
    {  
        if (_size == _capacity)  
            return true;  
        else  
            return false;  
    }  
    bool IsEmpty()  
    {  
        if (_size == 0)  
            return true;  
        else  
            return false;  
    }  
	friend std::ostream& operator<<(std::ostream& _cout, const Vector& v);
private:
	DataType* _pData;
	size_t _capacity;
	size_t _size;
};//缺少resize

