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
		return (SizeType(-1)/sizeof(T));
	}
	SizeType Size()const
	{
		int i=0;
		while(_start!=_end)
		{
			i++;
		}
		return i;
	}
	SizeType MaxSize()const;
	bool Empty()const
	{
		if(_stat==_end)
		{
			return 1;
		}
		return -1;
	}

        //////////////Acess/////////////////////
	Reference operator[](size_t index);
	ConstReference operator[](size_t index)const;
	Reference Front()
    ConstReference Front()const;
	Reference Back();
	ConstReference Front()const;


	/////////////Iterator//////////////////
	Iterator Begin();
	ConstIterator Begin()const;
	Iterator End();
	ConstIterator End()const;

        //////////////Modify///////////////////
	void PushBack(const T& value);
	void PopBack();

	// 在position位置插入元素data
	Iterator Insert(Iterator position, const T& data);
        
        // 删除position位置的元素
	Iterator Erase(Iterator position);
protected:
	void FillAndInit(SizeType n, const T& value);
        void CheckCapacity();
protected:
	Iterator _start;
	Iterator _end;
	Iterator _endOfStorage;

};