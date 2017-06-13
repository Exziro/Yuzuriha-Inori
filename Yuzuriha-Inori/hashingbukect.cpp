//enum State
//{
//	EMPTY, EXIST, DELETE
//};
//
//template<class K, class V>
//struct HashElem
//{
//	pair<K, V>  _kv;
//	State _s;
//
//	HashElem()
//		: _s(EMPTY)
//	{}
//};
//
//
//static size_t BKDRHash(const char * str)
//{	
//	unsigned int seed = 131; // 31 131 1313 13131 131313	
//	unsigned int hash = 0;
//	while (*str )
//	{
//		hash = hash * seed + (*str++);
//	}
//	return (hash & 0x7FFFFFFF);
//}
//
//// ����̽��
//template<class K, class V, class HashFunc = _HashFun<K>, bool IsLine = true>
//class HashTable
//{
//public:
//	HashTable(size_t size = 12)
//		: _size(0)
//	{
//		_table.resize(GetNextPrime(size));
//	}
//
//	bool Insert(const K& key, const V& value);
//
//	pair<HashElem<K, V>*, bool> Find(const K& key);
//
//	bool Remove(const K& key);
//	
//private:
//	size_t _HashFunc(const K& key);
//	// ����̽�⴦����
//	size_t HashFunc1(size_t hashAddr);
//	// ����̽�⴦����
//	size_t HashFunc2(size_t hashAddr, size_t i);
//
//	void _CheckTable();
//
//	void Swap(HashTable<K, V>& ht)
//	{
//		//_table.swap(ht._table);
//		_table.swap(ht._table);
//		swap(_size, ht._size);
//	}
//
//private:
//	public:
//	std::vector<HashElem<K, V>> _table;
//	size_t _size;  // ��ЧԪ�صĸ���
//};
//#pragma once
//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//template<class T>
//struct DefaultFunc
//{
//	size_t operator()(const T& data)
//	{
//		return (size_t)data;
//	}
//};
//
//struct StringFunc
//{
//	size_t operator()(const string& str)
//	{
//		size_t sum = 0;
//		for (size_t i = 0; i < str.size(); ++i)
//		{
//			sum += str[i];
//		}
//		return sum;
//	}
//};
//
//template<class K, class V>
//struct HashBucketNode
//{
//	K _key;
//	V _value;
//	HashBucketNode<K, V>* _next;
//	HashBucketNode(const K& key, const V& value)
//		:_key(key)
//		, _value(value)
//		, _next(NULL)
//	{}
//};

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
	//bool Alter(const K& key);//��Findʵ��
	void Print();
protected:
	void _CheckExpand();//����Ƿ���Ҫ����
	size_t _GetNextPrime(size_t size);//���������еõ��ȵ�ǰ�����������
	size_t _HashFunc(const K& key,size_t mod);//��ϣ����
protected:
	vector<Node*> _table;
	size_t _size;//��¼�ĸ���
};
template<class K, class V, class FuncModle>  
bool HashBucket<K, V, FuncModle>::Insert(const K& key, const V& value)  
{  
    _CheckExpand();  
    //ʹ��ͷ�巨����  
    size_t index = _HashFunc(key,_table.size());  
    Node* tmp=new Node(key, value);//һ��Ҫ��new�����  
    if (_table[index] == NULL)  
    {  
        _table[index] = tmp;  
    }  
    else  
    {  
        //��ΪNULL��ʹ��ͷ�巨�����½��  
        tmp->_next = _table[index];  
        _table[index] = tmp;  
    }  
    _size++;  
    return true;  
}  
template<class K, class V, class FuncModle>  
size_t  HashBucket<K, V, FuncModle>::_GetNextPrime(size_t size)  
{  
    const int _PrimeSize = 28;  
    static const unsigned long _PrimeList[_PrimeSize] =  
    {  
        53ul, 97ul, 193ul, 389ul, 769ul,  
        1543ul, 3079ul, 6151ul, 12289ul, 24593ul,  
        49157ul, 98317ul, 196613ul, 393241ul, 786433ul,  
        1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,  
        50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,  
        1610612741ul, 3221225473ul, 4294967291ul  
    };  
    for (int i = 0; i < _PrimeSize; ++i)  
    {  
        if (_PrimeList[i] > size)  
            return _PrimeList[i];  
    }  
    assert(false);  
    return 4294967291ul;  
}  
template<class K, class V, class FuncModle>  
void HashBucket<K, V, FuncModle>::_CheckExpand()  
{  
    if (_size == _table.size())  
    {  
        size_t newsize = _GetNextPrime(_size);//����������ȡ����һ������  
        if (newsize == _size)  
            return;  
        vector<Node*> newtable;  
        newtable.resize(newsize);  
        for (size_t i = 0; i < _size; ++i)  
        {  
            size_t index = _HashFunc(_table[i]->_key,newsize);  
            if (_table[i])  
            {  
                Node* head = _table[i];//����ͷ�ڵ�  
                newtable[index] = head;//ժ��vector�ĵ�һ��ָ��Ϊ�±��ͷ�ڵ�  
                _table[i] = _table[i]->_next;  
                while (_table[i])//����ժ���  
                {  
                    Node* tmp = _table[i];  
                    _table[i] = _table[i]->_next;  
                    head->_next = tmp;  
                    head = head->_next;  
                }  
            }  
            else  
                newtable[index] = NULL;  
            _table[i] = NULL;  
        }  
        swap(_table, newtable);  
    }  
}
template<class K, class V, class FuncModle>  
HashBucketNode<K,V>* HashBucket<K, V, FuncModle>::Find(const K& key)  
 {  
        size_t index = _HashFunc(key, _table.size());  
        while (_table[index])  
        {  
            if (_table[index]->_key == key)  
            {  
                return _table[index];  
            }  
            _table[index] = _table[index]->_next;  
        }  
        return NULL;  
 }  