#include<iostream>  
#include<stdlib.h>  
using namespace std;  
  
template<class K,class V>  
struct BSTNode  
{  
    K _key;  
    V _value;  
    BSTNode* _left;  
    BSTNode* _right;
	BSTNode* _parent;
	int bf ;
  
    BSTNode(const K& key, const V& value)  
        : _key(key)  
        , _value(value)  
        , _left(NULL)  
        , _right(NULL)  
    {}  
};  
template<class K, class V>  
class BSTree  
{  
    typedef BSTNode<K, V> Node;  
public:  
    BSTree()  
        :_root(NULL)  
    {}  
    //∑«µ›πÈ≤Â»Î  
	
    bool Insert(const K & key, const V & value)  
    {  
        if (_root == NULL)  
        {  
            _root = new Node(key, value);
            return true;  
        }  
        Node *parent = NULL;  
        Node *cur = _root;  
        while (cur)  
        {  
            if (key > cur->_key)  
            {  
                parent = cur;  
                cur = cur->_right;  
            }  
            else if (key < cur->_key)  
            {  
                parent = cur;  
                cur = cur->_left;  
            }  
            else  
            {  
                return false;  
            }  
        }  
        cur = new Node(key, value);  
        if (parent->_key > key)  
        {  
            parent->_left = cur; 
			cur->_parent = parent;
        }  
        else  
        {  
            parent->_right = cur; 
			cur->_parent = parent;
        }
		bool IsRotate = false;
		while(parent)
		{
			if(parent->_left == cur)
				parent->bf--;
			else
				parent->bf++;
			if(parent->bf == 0)
				return true;
			else if(1 == parent->bf || -1 == parent->bf)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				IsRotate = true; 
				if(2 == parent->bf)
				{	if(cur->bf == 1)
						rotatepLeft(parent);
					else
						rotatepLR(parent);	
				}
				else
				{
					if(-1 == cur->bf)
						rotatepright(parent);
					else
						rotatepLR(parent);
						
				}
			}
			break;
		}
		if(IsRotate)
		{
			Node * pparent = parent->_parent;
			if(pparent == NULL)
			{
				_root = parent;
			}
			else
			{
				if(pparent->_key < parent->_key)
					pparent->_right = parent;
				else
					pparent->_left = parent;
			}
		}


        return true;  
    }  
   //µ›πÈ≤Â»Î  
    bool Insert_R(const K & key, const V & value)  
    {  
        return _Insert_R(_root, key, value);  
    }
	void rotatepRL(Node * parent)
	{
		rotatepLeft(parent->_left);
		rotatepRight(parent);
	}

	void rotatepLR(Node * parent)
	{
		rotatepRight(parent->_right);
		rotatepLeft(parent);
	}

	void rotatepRight(Node * parent)//”“–˝
	{
		Node * SubR = parent->_right;
		Node * SubRL = SubR->_left;
		parent->_right = SubRL;
		if(SubRL)
			SubRL->_parent = parent;
		SubR->_left = parent;
		Node * pparent = parent->_parent;
		pparent->_parent = SubR;
		if(pparent == NULL)
			_proot = SubR;
		else
		{
			if (pparent->_left = parent)
			pparent->_parent = SubR;
			else
				pparent->_right = SubR;

		}
		parent->bf = SubR->bf = 0;
	}
	void rotatepLeft(Node * parent)//◊Û–˝
	{
		Node*SubL = parent->_left;
		Node*SubLR = SubL->_right;
		parent->_right = SubLR;
		if(SubLR)
			SubLR->_parent = parent;
		SubL->_right = parent;
		Node*pparent = parent->_parent;
		pparent->_parent = SubL;
		if(pparent == NULL)
			_proot = SubL;
		else
		{
			if (pparent->_right = parent)
			pparent->_parent = SubR;
			else
				pparent->_left = SubR;

		}
		parent->bf = SubL->bf = 0;
	
	}
    //≤È’“  
    void Find(const K& key)  
    {  
        if (_Find(key))  
            cout << "À—À˜∂˛≤Ê ˜÷–¥Ê‘⁄" << key << endl;  
        else  
            cout << "À—À˜∂˛≤Ê ˜÷–≤ª¥Ê‘⁄" << key << endl;  
    }  
	int height(Node * _root)
	{
		return _height(_root);
	}
//∑«µ›πÈ…æ≥˝  
    //bool Remove(const K& key)  
    //{  
    //    if (_root == NULL)  
    //    {  
    //        return false;  
    //    }  
    //    if (_root->_left == NULL && _root->_right == NULL)  
    //    {  
    //        delete _root;  
    //        _root = NULL;  
    //        return true;  
    //    }  
  
    //    Node *parent = _root;  
    //    Node *del = _root;  
    //    while (del)  
    //    {  
    //        if (key < del->_key)  
    //        {  
    //            parent = del;  
    //            del = del->_left;  
    //        }  
    //        else if (key > del->_key)  
    //        {  
    //            parent = del;  
    //            del = del->_right;  
    //        }  
    //        else  
    //        {  
    //            break;  
    //        }  
    //    }  
    //    if (del == NULL)  
    //    {  
    //        return false;  
    //    }  
  
    //    if (del->_left == NULL)  
    //    {  
    //        if (del->_key = key)  
    //        {  
    //            _root = del->_right;  
    //            delete del;  
    //            del = NULL;  
    //            return true;  
    //        }  
    //        else if (parent->_left == del)  
    //        {  
    //            parent->_left = del->_right;  
    //        }  
    //        else  
    //        {  
    //            parent->_right = del->_right;  
    //        }  
    //    }  
    //    else if (del->_right == NULL)  
    //    {  
    //        if (del->_key = key)  
    //        {  
    //            _root = del->_left;  
    //            delete del;  
    //            del = NULL;  
    //            return true;  
    //        }  
    //        else if (parent->_right == del)  
    //        {  
    //            parent->_right = del->_left;  
    //        }  
    //        else  
    //        {  
    //            parent->_left = del->_left;  
    //        }  
    //    }  
    //    else  
    //    {  
    //        Node* sub = del;  
    //        Node* First = del->_right;  
    //        if (First->_left)  
    //        {  
    //            sub = First;  
    //            First = First->_left;  
    //        }  
    //        swap(del->_key, First->_key);  
    //        swap(del->_value, First->_value);  
    //        del = First;  
    //        if (del->_left == NULL)  
    //        {  
    //            if (sub->_left == del)  
    //            {  
    //                sub->_left = del->_right;  
    //            }  
    //            else  
    //            {  
    //                sub->_right = del->_right;  
    //            }  
    //        }  
    //        else if (del->_right == NULL)  
    //        {  
    //            if (sub->_left == del)  
    //            {  
    //                sub->_left = del->_left;  
    //            }  
    //            else  
    //            {  
    //                sub->_left = del->_left;  
    //            }  
    //        }  
    //    }  
    //    delete del;  
    //    del = NULL;  
    //    return true;  
    //}  
//µ›πÈ…æ≥˝  
    bool Remove_R(const K& key)  
    {  
        return _Remove_R(_root, key);  
    }  
    //≤È’“  
    Node* _Find(const K& key)  
    {  
        if (_root == NULL)  
        {  
            return NULL;  
        }  
        Node* cur = _root;  
        while (cur)  
        {  
            if (key < cur->_key)  
            {  
                cur = cur->_left;  
            }  
            else if (key > cur->_key)  
            {  
                cur = cur->_right;  
            }  
            else  
            {  
                break;  
            }  
        }  
        return cur;  
    }  
//«∞–Ú±È¿˙  
    void InOrder()  
    {  
        _InOrder(_root);  
        cout << endl;  
    }  
protected:  
	int _height(Node * _root)
	{
		return _root->bf;
	}

    bool _Insert_R(Node*&root,const K & key, const V & value)  
    {  
        if (root == NULL)  
        {  
            root = new Node(key, value);  
            return true;  
        }  
        if (key < root->_key)  
        {  
            return _Insert_R(root->_left, key, value);  
        }  
        else if (key > root->_key)  
        {  
            return _Insert_R(root->_right, key, value);  
        }  
        else  
        {  
            return false;  
        }  
    }  
    bool _Remove_R(Node *&root, const K&key)  
    {  
        if (root == NULL)  
        {  
            return false;  
        }  
        if (key < root->_key)  
        {  
            return _Remove_R(root->_left, key);  
        }  
        else if (key > root->_key)  
        {  
            return _Remove_R(root->_right, key);  
        }  
        else  
        {  
            Node* del = root;  
            if (root->_left == NULL)  
            {  
                root = root->_right;  
            }  
            else if (root->_right == NULL)  
            {  
                root = root->_left;  
            }  
            else  
            {  
                Node* First = root->_right;  
                while (First->_left)  
                {  
                    First = First->_left;  
                }  
                swap(del->_key, First->_key);  
                swap(del->_value, First->_value);  
                return _Remove_R(root->_right, key);  
            }  
            delete del;  
            del = NULL;  
            return true;  
        }  
    }  
    void _InOrder(Node* root)  
    {  
        if (root == NULL)  
        {  
            return;  
        }  
        _InOrder(root->_left);  
        cout << root->_key << " ";  
        _InOrder(root->_right);  
    } 
 
private:  
    BSTNode<K, V>* _root;  
};  
  
void test()  
{  
    int a[10] = { 5, 2, 4, 8, 7, 1, 9, 0, 6, 3 };  
    BSTree<int, int> bstree;  
    for (int i = 0; i < 10; i++)  
    {  
        bstree.Insert_R(a[i], a[i]);  
    }  

}  
  
int main()  
{  
    test();  
    system("pause");  
    return 0;  
}  