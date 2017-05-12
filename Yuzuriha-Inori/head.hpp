#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
template<class T,class Compare=Less<T>>
class Heap
{
private:
	vector<T> headdatec;
	int size;
public:

	Heap()
	{}
	Heap(const T array[],size_t size)
	{
		for(size_t i=0;i<size;i++)
			headdatec.push_back(array[i]);
	
		int root=(headdatec.size()-2)>>1;
		for(;root>=0;--root)
		{adjustdown(root);}
	}
	int Size()
	{
		return headdatec.size();
	}

	/*void inithead(const size,const T arry[])
	{
		for(int i=0;i<size;i++)
		{
			headdatec.push_back(arry[i]);
		}
	}
	void printfhead()
	{
		for(int i=0;i<size;i++)
		{
			
			cout<<headdatec[i]<<" ";
		}
	}*/
	//int Findrchid(size_t parent)//²éÕÒ×îÓÒ×ÓÊ÷
	//{
	//	//size_t tmp=parent;
	//	size_t rchild;
	//	if(headdatec[parent*2+1])
	//		{
	//			rchild=headdatec[parent*2+1];
	//			int a =Findrchid(rchild);
	//			return a;
	//		}
	//}
	void adjustdown(size_t parent)  
	{  size_t size=headdatec.size();

		size_t child=parent*2+1;      
		while(child < size&&(child+1)<size)  
		{  
			if(headdatec[child] > headdatec[child+1])  
        {  
            child++;  
        }
			if(headdatec[parent]>headdatec[child])
			{
				std::swap(headdatec[parent],headdatec[child]);  
				parent=child;
				child=parent*2+1;
			}
			 else return;
		}
		
    }  
	void adjustup()  
	{  
		size_t child=headdatec.size()-1;//(child-1)>>1;
		size_t parent=(child-1)>>1;/*headdatec.size()-1;*/
		      
		while(child!=0)  
		{  
			//if(headdatec[parent]<headdatec[child])
			//{
			//	child++;
			//}
			if(headdatec[parent]>headdatec[child])
			{
				std::swap(headdatec[parent],headdatec[child]);  
				child=parent;
				parent=(child-1)/2;
			}
			else return;
		}
		 
    }
	void insert(const T i)
	{
		headdatec.push_back(i);
		size++;
		if(size<1){
			adjustup();}
	}
	void remove()
	{
		size_t size=headdatec.size();
		T tmp=headdatec[0];
		headdatec[0]=headdatec[size-1];
		headdatec[size-1]=tmp;
		headdatec.pop_back();
		adjustdown(0);
	}
	const T& top()
	{
		return headdatec[0];
	}

};
	template<class T>
	struct Less
	{
		bool operator()(const T&left,const T&right)
		{
			return left<right;
		}
	};
	template<class T>
	struct Greater
	{
		bool operator()(const T&left,const T&right)
		{
			return left>right;
		}
	};
//int main()
//{
//	int arry[5]={1,4,3,2,5};
//	//myhead<int> a;
//	//a.inithead(5,arry);
//	//a.adjust_heap(1);
//	Heap<int> a(arry,5);
//	a.insert(6);
//	a.remove();
//	system("pause");
//	return 0;
//}
