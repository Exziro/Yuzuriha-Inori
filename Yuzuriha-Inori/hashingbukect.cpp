template<class K, class V, class FuncModle = DefaultFunc<K>>
class HashBucket
{
	typedef HashBucketNode<K, V> Node;
public:
	HashBucket();
	~HashBucket();
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
template<class K, class V, class FuncModle>  
bool HashBucket<K, V, FuncModle>::Insert(const K& key, const V& value)  
{  
    _CheckExpand();  
    //使用头插法插入  
    size_t index = _HashFunc(key,_table.size());  
    Node* tmp=new Node(key, value);//一定要用new出结点  
    if (_table[index] == NULL)  
    {  
        _table[index] = tmp;  
    }  
    else  
    {  
        //不为NULL则使用头插法插入新结点  
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
        size_t newsize = _GetNextPrime(_size);//从素数表中取出下一个素数  
        if (newsize == _size)  
            return;  
        vector<Node*> newtable;  
        newtable.resize(newsize);  
        for (size_t i = 0; i < _size; ++i)  
        {  
            size_t index = _HashFunc(_table[i]->_key,newsize);  
            if (_table[i])  
            {  
                Node* head = _table[i];//保存头节点  
                newtable[index] = head;//摘下vector的第一个指针为新表的头节点  
                _table[i] = _table[i]->_next;  
                while (_table[i])//依次摘结点  
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
template<class K, class V, class FuncModle>
bool HashBucket<K, V, FuncModle>::Remove(const K& key)
{
	//不能用find找到，然后删。
	size_t index = _HashFunc(key,_table.size());
	if (_table[index] == NULL)
		return false;
	Node* cur = _table[index];
	if (cur->_key==key)
	{
		Node* del = cur;
		_table[index] = cur->_next;
		delete del;
		_size--;
		return true;
	}
	else
	{
		Node* prev = NULL;
		while (cur)
		{
			if (cur->_key == key)
			{
				prev->_next = cur->_next;
				delete cur;
				_size--;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}
}
