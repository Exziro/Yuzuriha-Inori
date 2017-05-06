#include<iostream>
using namespace std;
#include<string.h>
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T& value)
		: _value(value)
		, _pLeft(NULL)
		, _pRight(NULL)
	{}

	T _value;
	BinaryTreeNode<T>* _pLeft;   // ����
	BinaryTreeNode<T>* _pRight;  // �Һ���
};


template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		: _pRoot(NULL)
	{}

	BinaryTree(const T array[], size_t size, const T& invalid)
	{
		size_t index = 0;
		_CreateBinaryTree(_pRoot, array, size, index, invalid);
	}

	BinaryTree(const BinaryTree<T>& bt)
	{
		_pRoot = _CopyBirnaryTree(bt._pRoot);
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& bt);

	~BinaryTree()
	{
		//_DestroyBinaryTree(_pRoot);
	}


	///////////////////////////////////////////////////////////////
	void PreOrder()
	{
		cout<<"PreOrder:"<<endl;
		_PreOrder(_pRoot);
		cout<<endl;
	}

	void PreOrder_Nor();

	void InOrder()
	{
		cout<<"InOrder:"<<endl;
		_InOrder(_pRoot);
		cout<<endl;
	}

	// ��һ�ֿ죿
	void InOrder_Nor();

	void PostOrder()
	{
		cout<<"PostOrder:"<<endl;
		_PostOrder(_pRoot);
		cout<<endl;
	}

	// �������
	void LevelOrder();

	Node* Find(const T& value)
	{
		return _Find(_pRoot, value);
	}

	// ��C++  ����C����
	Node* Parent(Node* pCur)
	{
		return _Parent(_pRoot, pCur);
	}

	Node* GetLeftChild(Node* pCur)
	{
		return (pCur==NULL)? NULL:pCur->_pLeft;
	}

	Node* GetRightChild(Node* pCur)
	{
		return (pCur==NULL)? NULL:pCur->_pRight;
	}

	size_t Height()
	{
		return _Height(_pRoot);
	}

	size_t GetLeefCount()
	{
		return _GetLeefCount(_pRoot);
	}

	size_t GetKLevelCount(size_t k)
	{
		return _GetKLevelCount(_pRoot, k);
	}


	void BinaryMirror_Nor();

	void BinaryMirror()
	{
		return _BinaryMirror(_pRoot);
	}

private:
	// ѧ����Ϣ-->
	Node* _CreateBinaryTree( Node* &pRoot,const T array[], size_t size, size_t& index, const T& invalid)
	{
		
		if(index<size&& array[index]!=invalid)
		{
			pRoot=new Node(array[index]);
			//pRoot->_value=array[index];
			pRoot->_pLeft=_CreateBinaryTree(pRoot->_pLeft,array,size,++index,invalid);
			pRoot->_pRight=_CreateBinaryTree(pRoot->_pRight,array,size,++index,invalid);
		}
		return pRoot;
	}

	// pRoot-->���������ĸ��ڵ�
	//Node* _CopyBirnaryTree(Node* pRoot);

	//void _DestroyBinaryTree(Node*& pRoot);

	////////////////////////////////////////////////////////////////
	// ǰ�򣺷��ʸ��ڵ�--->���ʸ��ڵ��������--->���ʸ��ڵ��������
	void _PreOrder(Node* pRoot)//ʱ�临�Ӷȣ�
	{
		if(pRoot)
		{
			cout<<pRoot->_value<<" ";
			_PreOrder(pRoot->_pLeft);
			_PreOrder(pRoot->_pRight);
		}
		
	}
	// ǰ�򣺷��ʸ��ڵ��������--->���ʸ��ڵ�--->���ʸ��ڵ��������
	void _InOrder(Node* pRoot)
	{
		if(pRoot)
		{
			
			_InOrder(pRoot->_pLeft);
			cout<<pRoot->_value<<" ";
			_InOrder(pRoot->_pRight);
		}
		return ;
	}
	// ������������������������-->��������������-->�������ڵ�
	void _PostOrder(Node* pRoot)
	{
		if(pRoot)
		{
			
			_PostOrder(pRoot->_pLeft);
			_PostOrder(pRoot->_pRight);
			cout<<pRoot->_value<<" ";

		}
		return ;
	}

	Node* _Find(Node* pRoot, const T& value)//�����ض�����
	{
		if(pRoot)
		{
		if(value==pRoot->_value)
			return pRoot;
		else
			_Find(pRoot->_pLeft,value);
			_Find(pRoot->_pRight,value);
		}
		return pRoot;
	}
			

	Node* _Parent(Node* pRoot, Node* pCur)
	{
		Node*pvre=NULL;
	}

	size_t _Height(Node* pRoot);

	size_t _GetLeefCount(Node* pRoot);

	size_t _GetKLevelCount(Node* pRoot, size_t k);

	void _BinaryMirror(Node* pRoot);

private:
	Node* _pRoot;   // ָ�����ĸ��ڵ�
};


void Test()
{
	char* pStr = "124###35##6";

	BinaryTree<char> bt(pStr, strlen(pStr), '#');
	bt.PreOrder();
	//bt.InOrder();
	//bt.PostOrder();
	//bt.LevelOrder();

	//BinaryTree<char> bt1(bt);
	//bt1.PreOrder();
	//bt1.InOrder();
	//bt1.PostOrder();

	//BinaryTree<char> bt2;
	//bt2 = bt1;
	//bt2.PostOrder();
}
int main()
{
	Test();
	system("pause");
	return 0;
}