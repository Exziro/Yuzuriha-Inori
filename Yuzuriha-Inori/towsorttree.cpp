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

		if(key > _pRoot->_key)
			parent = _pRoot;
			_pRoot = _pRoot->_pRight;
		else if(key < _pRoot->_key)
		{
			parent = _pRoot; 
			_pRoot = _pRoot->_pLeft
		}
		if(_pRoot->_key == key)
			T = _pRoot;
			break;

			/*_pRoot->_pLeft;*/
	
		}
		if(NULL == T->_pLeft&& NULL == T->_pRight)
		{
			(parent->left==node)?(parent->left=NULL):(parent->right=NULL);//判断父节点右子树是不是该节点 是则滞空
			delete T;
			T = NULL;
			return true;
		}
		else if(NULL == T->_pRight && T->_pLeft)//有左无右
		{
			(parent->_pLeft==node)?(parent->_pLeft = T->_pLeft):(parent->right=T->_pLeft);
			delete T;
			T = NULL;
			
		}
		else if(NULL == T->_pLeft && T->_pRight)//有右无左
		{
			(parent->_pLeft==node)?(parent->_pLeft = T->_pLeft):(parent->_=T->_pRight);
			delete T;
			T = NULL;
		}
		else
		{
			Node*_parent;
			Node*tmp = T;
			Node*left = T->_pLeft;
			Node*right = T->_pRight;
			while(left->_pRight)//一直找最大
			{
				_parent = left;
				left = left->_pRight;
			}
			//while(right->_pLeft)//一直找最小
			//{
			//	right = right->_pLeft;
			//}
			//if(left->_key > right->_key)
			left->_key = T->_key;
			left->_value = T->_value;
			left->_pLeft = T->_pLeft;
			left->_pRight = T->_pRight;
			T->_pLeft = NULL;
			T->_pRight = NULL;
			delete T;
			T = NULL;
			return true;
		}
		}
		
		return false;
		

		
		
	}

	void InOrder()
	{
		cout<<"InOrder: ";
		_InOrder(_pRoot);
		cout<<endl;
	}

	//const K& GetMaxKey()const;
	//const K& GetMinKey()const;

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


// //递归版本
//template<class K, class V>
//class BSTree
//{
//	typedef BSTNode<K, V> Node;
//public:
//	BSTree()
//		: _pRoot(NULL)
//	{}
//
//	//BSTree(const BSTree& bst);
//	//BSTree<K, V>& operator=(const BSTree<K, V>& bst);
//	//~BSTree();
//
//	Node* Find(const K& key)
//	{
//		if(_pRoot->key == key)
//		{
//				return _pRoot;
//		}
//		else if(_pRoot->key > key)
//		{
//			_pRoot->
//		
//
//		}	
//		
//		return _Find(_pRoot, key);
//	}
//
//	bool Insert(const K& key, const V& value)
//	{
//		return _Insert(_pRoot, key, value);
//	}
//
//	bool Remove(const K& key)
//	{
//		return _Remove(_pRoot, key);
//	}
//
//	void InOrder()
//	{
//		cout<<"InOrder: ";
//		_InOrder(_pRoot);
//		cout<<endl;
//	}
//
//
//protected:
//	Node* _Find(Node* pRoot, const K& key)
//	bool _Insert(Node* & pRoot, const K& key, const V& value)
//	bool _Remove(Node*& pRoot, const K& key)
//
//
//	void _InOrder(Node* pRoot)
//	{
//		if(pRoot)
//		{
//			_InOrder(pRoot->_pLeft);
//			cout<<pRoot->_key<<" ";
//			_InOrder(pRoot->_pRight);
//		}
//	}
//protected:
//	Node * _pRoot;
//};



void Test()
{
	 int a [] = {5,3,4,1,7,8,2,6,0,9};
	 BSTree<int, int> bst;
}
