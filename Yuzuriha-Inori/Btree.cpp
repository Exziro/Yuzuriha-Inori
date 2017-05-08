#include<iostream>
using namespace std;
#include<string.h>
#include<queue>
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T& value)
		: _value(value)
		, _pLeft(NULL)
		, _pRight(NULL)
	{}

	T _value;
	BinaryTreeNode<T>* _pLeft;   // 左孩子
	BinaryTreeNode<T>* _pRight;  // 右孩子
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

	BinaryTree<T>& operator=(const BinaryTree<T>& bt)
	{
		if(this!=bt)
		{
			std::swap(_pRoot,bt._pRoot);
		}
		return *this;
	}

	~BinaryTree()
	{
		_DestroyBinaryTree(_pRoot);
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

	// 哪一种快？
	void InOrder_Nor();

	void PostOrder()
	{
		cout<<"PostOrder:"<<endl;
		_PostOrder(_pRoot);
		cout<<endl;
	}

	// 层序遍历
	void LevelOrder()
	{
		cout<<"PostOrder:"<<endl;
		_LevelOrder(_pRoot);
		cout<<endl;
		
	}


	Node* Find(const T& value)
	{
		return _Find(_pRoot, value);
	}

	// 先C++  再用C语言
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
	// 学生信息-->
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

	// pRoot-->被拷贝树的根节点
	Node* _CopyBirnaryTree(Node* pRoot)
	{
		if(pRoot==NULL)
		{
			return NULL;
		}
		Node*root=new Node(pRoot->_value);
		pRoot->_pLeft=_CopyBirnaryTree(pRoot->_pLeft);
		pRoot->_pRight=_CopyBirnaryTree(pRoot->_pRight);
		return pRoot;
	}

	void _DestroyBinaryTree(Node*& pRoot)
	{
		Node*tmp=pRoot;
		if(NULL==tmp)
			return;
		_DestroyBinaryTree(tmp->_pLeft);
		_DestroyBinaryTree(tmp->_pRight);
		delete tmp;
	}

	////////////////////////////////////////////////////////////////
	// 前序：访问根节点--->访问根节点的左子树--->访问根节点的右子树
	void _PreOrder(Node* pRoot)//时间复杂度：
	{
		if(pRoot)
		{
			cout<<pRoot->_value<<" ";
			_PreOrder(pRoot->_pLeft);
			_PreOrder(pRoot->_pRight);
		}
		
	}
	// 前序：访问根节点的左子树--->访问根节点--->访问根节点的右子树
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
	// 后续遍历：遍历根的左子树-->遍历根的右子树-->遍历根节点
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
	void _LevelOrder(Node*proot)
	{
		Node*tmp=proot;
		queue<Node*>q;
		q.push(tmp);
		while(!q.empty())
		{
			Node*top=q.front;
			q.pop;
			cout<<top->_value<<"　";
			if(top->_pRight)
			{
				q.push(top->_pRight);
			}
			if(top->_pLeft)
			{
				q.push(top->_pLeft);
			}
		}
	}
		

	Node* _Find(Node* pRoot, const T& value)//查找特定参数
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
			

	Node* _Parent(Node* pRoot, Node* pCur)//找出当前节点的父子树
	{
		if(pRoot->_pLeft||pRoot->_pRight){
		if(pRoot->_pRight==pCur)
			return pRoot;
		if(pRoot->_pLeft==pCur)
			return pRoot;
		_Parent(pRoot->_pLeft,pCur);
		_Parent(pRoot->_pRight,pCur);
		}

	}

	size_t _Height(Node* pRoot)
	{
		if(pRoot==NULL)
		{
			return 0;
		}
		int left=_Height(pRoot->_pLeft)+1;
		int right=Height(pRoot->_pRight)+1;
		return left<right ? right:left;
	}


	size_t _GetLeefCount(Node* pRoot)
	{
		if(pRoot==NULL)
		{
			return 0;
		}
		int left=_Height(pRoot->_pLeft)+1;
		int right=Height(pRoot->_pRight)+1;
		return left+right;
	}

	size_t _GetKLevelCount(Node* pRoot, size_t k)
	{
		if(pRoot==NULL||k<0)
		{
			return 0;
		}
		if(k==1)
		{
			return 1;
		}
		rsize_t right=GetKLevelCount(pRoot->_pRight,k-1);
		rsize_t left=GetKLevelCount(pRoot->_pLeft,k-1);
		return left+right;
	}

	void _BinaryMirror(Node* pRoot);

private:
	Node* _pRoot;   // 指向树的根节点
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