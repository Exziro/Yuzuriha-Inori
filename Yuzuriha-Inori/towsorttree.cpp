#include<iostream>
using namespace std;
template<class K, class V>
struct BSTNode
{
	BSTNode(const K& key, const V& value)
		: _pLeft(NULL)
		, _pRight(NULL)
		, _key(key)
		, _value(value)
	{}

	BSTNode<K, V>* _pLeft;
	BSTNode<K, V>* _pRight;

	K _key;
	V _value;
};

// 非递归版本
template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		: _pRoot(NULL)
	{}

	//BSTree(const BSTree& bst)
	//{
	//	i
	//BSTree<K, V>& operator=(const BSTree<K, V>& bst);
	//~BSTree();

	Node* Find(const K& key)
	{
		Node* a = _pRoot;
		if(a->key == key)
		{
			return a;
		}
		else if(key<(a->key))
		{
			a=a->_pleft;
	
		}
		else if(key<(a->key))
		{
			a=a->_pright;
		}
		else 
			return _pRoot;
	}
	bool Insert(const K& key, const V& value)
	{

		Node* T = new Node*;
		T->_key = key;
		T->_value = value;
		T->_pRight = NULL;
		T->_pLeft = NULL;
		Node* R = _pRoot;
		if(_pRoot == NULL)
		{
			_pRoot = T;
			return true;
		}
		while(_pRoot->_key != key)
		{	

		if(key>_pRoot->_key)
			if(_pRoot->_pRight)
			_pRoot = _pRoot->_pRight;
			else
				{
					_pRoot->_pRight = T;
					return true;
				}
		else
		{
			if(_pRoot->_pLeft)//判断插入点有没有子树
				_pRoot = _pRoot->_pLeft;
			else
				{_pRoot->_pLeft = T;
					return true;
				}
		}

			/*_pRoot->_pLeft;*/
	
		}

		return false;

	}
	bool Remove(const K& key)
	{
		Node * T;
		Node * parent;
		if(NULL == _pRoot)
		{
			return false;
		}
		else 
		{
		while(_pRoot->_key != key)
		{	

		if(key>_pRoot->_key)
			_pRoot = _pRoot->_pRight;
		else
		{
			parent = _pRoot;
			if(_pRoot->_pLeft)	
				_pRoot = _pRoot->_pLeft;
			else
				{
					_pRoot->_pLeft = T;
					break;
				}
		}

			/*_pRoot->_pLeft;*/
	
		}
		if(NULL == T->_pLeft&& NULL == T->_pRight)
		{
			delete T;
			return true;
		}
		}

		
		
	}

	void InOrder()
	{
		cout<<"InOrder: ";
		_InOrder(_pRoot);
		cout<<endl;
	}

	const K& GetMaxKey()const;
	const K& GetMinKey()const;

protected:
	void _InOrder(Node* pRoot)
	{
		if(pRoot)
		{

			_InOrder(pRoot->_pLeft);
			cout<<pRoot->_key<<" ";
			_InOrder(pRoot->_pRight);
		}
	}
protected:
	Node* _pRoot;
};


// 递归版本
template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		: _pRoot(NULL)
	{}

	//BSTree(const BSTree& bst);
	//BSTree<K, V>& operator=(const BSTree<K, V>& bst);
	//~BSTree();

	Node* Find(const K& key)
	{
		return _Find(_pRoot, key);
	}

	bool Insert(const K& key, const V& value)
	{
		return _Insert(_pRoot, key, value);
	}

	bool Remove(const K& key)
	{
		return _Remove(_pRoot, key);
	}

	void InOrder()
	{
		cout<<"InOrder: ";
		_InOrder(_pRoot);
		cout<<endl;
	}


protected:
	Node* _Find(Node* pRoot, const K& key)
	bool _Insert(Node* & pRoot, const K& key, const V& value)
	bool _Remove(Node*& pRoot, const K& key)


	void _InOrder(Node* pRoot)
	{
		if(pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout<<pRoot->_key<<" ";
			_InOrder(pRoot->_pRight);
		}
	}
protected:
	Node* _pRoot;
};



void Test()
{
	 int a [] = {5,3,4,1,7,8,2,6,0,9};
	 BSTree<int, int> bst;
}
