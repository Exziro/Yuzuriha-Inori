enum COLOR{RED, BLACK};
#include<iostream>
using namespace std;

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode(const K& key = K(), const V& value = V(), const COLOR& color = RED)
		:_pLeft(NULL)
		, _pRight(NULL)
		, _pParent(NULL)
		, _key(key)
		, _value(value)
		, _color(color)
	{}

	RBTreeNode<K, V>* _pLeft;
	RBTreeNode<K, V>* _pRight;
	RBTreeNode<K, V>* _pParent;
	K _key;
	V _value;
	COLOR _color;
};


template<class K, class V, class Ref, class Pointer>
class RBTreeIterator
{
	typedef RBTreeNode<K , V> Node;
	typedef RBTreeIterator<K, V, Ref, Pointer> Self;
public:
	RBTreeIterator()
		: _pNode(NULL)
	{}

	RBTreeIterator(Node* pNode)
		: _pNode(pNode)
	{}

	RBTreeIterator(RBTreeIterator& it)
		: _pNode(it._pNode)
	{}

	Self& operator++();
	Self operator++(int);
	Self& operator--();
	Self operator--(int);
	Ref operator*();
	const Ref operator*()const ;
	Pointer operator->();
	const Pointer operator->()const;
	bool operator==(const Self& it);
	bool operator!=(const Self& it);
protected:
	void _Increment();
	void _Decrement();
protected:
	Node* _pNode;
};

// µü´úÆ÷
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

public:
	typedef RBTreeIterator<K, V, K&, K*> Iterator;
public:
	RBTree();
	Iterator Begin();
	Iterator End();
	bool Empty()const;
	size_t Size()const;
	Iterator Find(const K& key);

	// Ê×ÏÈ£ºËÑË÷Ê÷
	bool Insert(const K& key, const V& value);
	void InOrder()
	{
		cout<<"InOrder: ";
		_InOrder(_GetRoot());
		cout<<endl;
	}

	bool CheckRBTree();

private:
	bool _CheckRBTree(Node* pRoot, const size_t blackCoount, size_t k);
	void _RotateL(Node* parent);
	void _RotateR(Node* pParent);
	void _InOrder(Node* pRoot)
	{
		if(pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout<<pRoot->_key<<" ";
			_InOrder(pRoot->_pRight);
		}
	}

	Node* &_GetRoot()
	{
		return _pHead->_pParent;
	}

	Node* _GetMinNode();
	Node* _GetMaxNode();
private:
	Node* _pHead;
	size_t _size;
};


void TestRBTree()
{
	int a[] = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	RBTree<int, int> t;
	for(int idx = 0; idx < sizeof(a)/sizeof(a[0]); ++idx)
		t.Insert(a[idx], idx);

	t.InOrder();

	if(t.CheckRBTree())
	{
		cout<<"ÊÇºìºÚÊ÷"<<endl;
	}
	else
	{
		cout<<"²»ÊÇºìºÚÊ÷"<<endl;
	}
}

void TestIterator()
{
	int a[] = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	RBTree<int, int> t;
	for(int idx = 0; idx < sizeof(a)/sizeof(a[0]); ++idx)
		t.Insert(a[idx], idx);
	t.InOrder();

	RBTree<int, int>::Iterator it = t.Begin();
	while(it != t.End())
	{
		cout<<*it<<" ";
		++it;
	}

	RBTree<int, int>::Iterator itEnd = t.End();
	--itEnd;
	cout<<*itEnd<<endl;
}