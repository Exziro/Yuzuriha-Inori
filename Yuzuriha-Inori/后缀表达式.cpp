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
	void Top()//����ջ��Ԫ��
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
			// ����ռ�
			int a=new[_capacity*2+3];
			T* temp =a;
			memcpy(tmp,_a,sizeof(T)*_size);//memcpy
			// ����Ԫ��
			//memcpy(); ȱ�㣺ǳ���� �е㣺�ٶȿ�
			//for   // ������ȡ---Add
			for(i=0;i<_size;i++)
			{
				tmp[i]=_pData[i];
			}
			delete _pData;
			_pData=tmp��
			 ָ���¿ռ�
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
		if(exp[i]>='0' &&exp[i]<='9')  //����������ַ����ͱ��浽��׺���ʽ�ַ�����  
        {  
            _pData[j++] = exp[i];  
        }
		else if(exp[i] == '+' || exp[i] == '-')   //����ǲ����� 
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