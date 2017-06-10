enum State
{
	EMPTY, EXIST, DELETE
};

template<class K, class V>
struct HashElem
{
	pair<K, V>  _kv;
	State _s;

	HashElem()
		: _s(EMPTY)
	{}
};


static size_t BKDRHash(const char * str)
{	
	unsigned int seed = 131; // 31 131 1313 13131 131313	
	unsigned int hash = 0;
	while (*str )
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

// 线性探测
template<class K, class V, class HashFunc = _HashFun<K>, bool IsLine = true>
class HashTable
{
public:
	HashTable(size_t size = 12)
		: _size(0)
	{
		_table.resize(GetNextPrime(size));
	}

	bool Insert(const K& key, const V& value);

	pair<HashElem<K, V>*, bool> Find(const K& key);

	bool Remove(const K& key);
	
private:
	size_t _HashFunc(const K& key);
	// 线性探测处理函数
	size_t HashFunc1(size_t hashAddr);
	// 二次探测处理函数
	size_t HashFunc2(size_t hashAddr, size_t i);

	void _CheckTable();

	void Swap(HashTable<K, V>& ht)
	{
		//_table.swap(ht._table);
		_table.swap(ht._table);
		swap(_size, ht._size);
	}

private:
	public:
	std::vector<HashElem<K, V>> _table;
	size_t _size;  // 有效元素的个数
};
#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<class T>
struct DefaultFunc
{
	size_t operator()(const T& data)
	{
		return (size_t)data;
	}
};

struct StringFunc
{
	size_t operator()(const string& str)
	{
		size_t sum = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			sum += str[i];
		}
		return sum;
	}
};

template<class K, class V>
struct HashBucketNode
{
	K _key;
	V _value;
	HashBucketNode<K, V>* _next;
	HashBucketNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _next(NULL)
	{}
};

template<class K, class V, class FuncModle = DefaultFunc<K>>
class HashBucket
{
	typedef HashBucketNode<K, V> Node;
public:
	HashBucket();
	//~HashBucket();
	HashBucket(const HashBucket<K, V, FuncModle>& h);
	HashBucket<K, V, FuncModle>& operator=(HashBucket<K, V, FuncModle> h);
	bool Insert(const K& key, const V& value);
	Node* Find(const K& key);
	bool Remove(const K& key);
	//bool Alter(const K& key);//用Find实现
	void Print();
protected:
	void _CheckExpand();//检查是否需要扩容
	size_t _GetNextPrime(size_t size);//从素数表中得到比当前素数大的素数
	size_t _HashFunc(const K& key,size_t mod);//哈希函数
protected:
	vector<Node*> _table;
	size_t _size;//记录的个数
};