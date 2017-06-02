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

// 迭代器
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

	// 首先：搜索树
	bool Insert(const K& key, const V& value);
	void InOrder()
	{
		cout<<"InOrder: ";
		_InOrder(_GetRoot());
		cout<<endl;
	}

	bool CheckRBTree();

private:
	bool _CheckRBTree(Node* pRoot, const size_t blackCoount, size_t k)
	{
		int black = 0;//对照
		int cBlack = 0;//实际
		Node * cur = pRoot;
		while (cur)
		{
			if(cur->_color == black)
				black ++;
			cur = cur->_pLeft;
		}
		return isRbtree(_pRoot,black,cBlack);
	}
	bool isRbtree(Node * root,int black , int cBlack )
	{
		if(root == NULL)
			return true;
		if(root->_color == BLACK)
			cBlack ++;
		if(cBlack == black)
		{
			if(root->_pParent == NULL)
				return ture;
			else if(root->_color == RED && root->_pParent->_color == root->_color)//父子节点的颜色不能相同
				return false;
			else
				return true;

		}
		return isRbtree(root->_pLeft,black,cBlack)&&isRbtree(root->_pRight,black,cBlack);//左右寻找

	}


	void _RotateL(Node* parent)
	{
		Node * SubR = parent->_pRight;
		Node * SubRL = SubR->_pLeft;
		if(SubRL)
		{
			SubRL->_pParent = parent;
			parent->_pRight = SubRL;
		}
		SubR->_pLeft = parent;
		SubR->_pParent = parent->_pParent;
		parent->_pParent = SubR;
		if(parent->_pParent == NULL)
		{
			_pHead = SubR;
		}
		else if(parent->_pParent->_key > SubR->_key)
			parent->_pParent->_pLeft = SubR;
		else if(parent->_pParent->_key < SubR->_key)
			parent->_pParent->_pRight = SubR;

	}

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
		cout<<"是红黑树"<<endl;
	}
	else
	{
		cout<<"不是红黑树"<<endl;
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