#include<iostream>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef ValueType* Iterator;
	typedef const ValueType* ConstIterator;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;


public:
	Vector()
		: _start(0)
		, _end(0)
		, _endOfStorage(0)
	{}

	Vector(SizeType n, const T& value)
	{
		FillAndInit(n, value);
	}

	Vector(SizeType n)
	{
		FillAndInit(n, T());
	}

	Vector(const Vector<T>& v)
	{
		_start = new T[v.Capacity()];
		_end += _start + v.Size();
		_endOfStorage = _start + v.Capacity();

		for (size_t idx = 0; idx < v.Size(); ++idx)
			_start[idx] = v[idx];
	}

	Vector<T>& operator=(const Vector<T>& v);
	~Vector();


	/////////////////////Capacity//////////////////////
	SizeType Capacity()const
	{
		return (_endOfStorage-_start);
	}
	SizeType Size()const
	{
		return(_endOfStorage-_start)
	}
	SizeType MaxSize()const
	{
		return (_end-_start);
	}
	bool Empty()const
	{
		if(_stat==_end)
		{
			return 1;
		}
		return -1;
	}

        //////////////Acess/////////////////////
	Reference operator[](size_t index)
	{
		return _start[index];
	}
	ConstReference operator[](size_t index)const
	{
		return const _start[index];
	}
	Reference Front()
	{
		return Begin();
	}
    ConstReference Front()const
	{
		return Begin();
	}
	Reference Back()
	{
		return End();
	}
	ConstReference Back()const
	{
		return End();
	}

	/////////////Iterator//////////////////
	Iterator Begin()
	{
		rerturn _start;
	}
	ConstIterator Begin()const
	{
		rerturn _start;
	}
	Iterator End()
	{
		return _end;
	}
	ConstIterator End()const
	{
		return _end;
	}

        //////////////Modify///////////////////
	void PushBack(const T& value);
	void PopBack();

	// 在position位置插入元素data
	Iterator Insert(Iterator position, const T& data);
        
        // 删除position位置的元素
	Iterator Erase(Iterator position);
protected:
	void FillAndInit(SizeType n, const T& value)
	{
		Iterator temp=_start;
		while(_temp!=_end)
		{
		   (*_temp)=0;
		   temp++;
		}
	}
    void CheckCapacity()
	{

protected:
	Iterator _start;
	Iterator _end;
	Iterator _endOfStorage;

};