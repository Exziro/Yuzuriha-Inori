#include<iostream>
using namespace std;
template<class T>
class Stack
{
public:
	Stack();
	
	Stack(size_t capacity = 10);
    Stack(const Stack<T>& s);
    Stack<T>& operator=(const Stack<T>& s);
	void Push(const T& x)
	{
        _CheakCapacity();
        _pData[_size]=x;
        _size++;
    }
	void Top()//返回栈顶元素
	{
		return _pData[_size];
	}
	void add(char *exp);
	//{
	//}
	void Pop()
	{
		_CheakCapacity();
        _size--;
	}
	size_t Size()const
	{
		return _size;
	}
	T& Top()
	{
		return _pData[0];
	}
	const T& Top()const;
	bool Empty()const
	{
		if(_size==0)
			return 1;
		else 
			return 0;
	}
private:
	void _CheckCapacity()
	{
		if(_size == _capacity)
		{
			int i;
			// 申请空间
			int a=new[_capacity*2+3];
			T* temp =a;
			memcpy(tmp,_a,sizeof(T)*_size);//memcpy
			// 拷贝元素
			//memcpy(); 缺点：浅拷贝 有点：速度快
			//for   // 类型萃取---Add
			for(i=0;i<_size;i++)
			{
				tmp[i]=_pData[i];
			}
			delete _pData;
			_pData=tmp；
			 指向新空间
			_capacity *= 2;

		}
	}
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};
template<typename T>
void  Stack<T>::add(char *exp)
{
	int i=0;
	int j=0;
	while(exp[i]!='\0')
	{
		if(exp[i]>='0' &&exp[i]<='9')  //如果是数字字符串就保存到后缀表达式字符串中  
        {  
            _pData[j++] = exp[i];  
        }
		else if(exp[i] == '+' || exp[i] == '-')   //如果是操作符 
        {  
            while(_pData.empty() == false)  
            {  
                char ch = Stack.Top();  
                if(ch == '+')  
                {  
  
					_pData[j++] = Stack.Top
						();  
                   s.pop();  
                }  
                else  
                    break;  
            }  
            s.Push(exp[i]);  
		}
	}