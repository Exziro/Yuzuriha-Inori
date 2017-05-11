#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
template<class T>
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
		size_t parent=headdatec[size-1];
		size_t child=parent*2+1;      
		while(child !=0)  
		{  
			if(headdatec[child] < headdatec[parent])  
        {  
            child++;  
        }
			if(headdatec[parent]>headdatec[child])
			{
				std::swap(headdatec[parent],headdatec[child]);  
				child=parent;
				parent=(child-1)>>1;
			}
			else return;
		}
		 
    }
	void insert(const T i)
	{
		headdatec.push_back(i);
		size++;
		int root=(headdatec.size()-2)>>1;
		for(;root>=0;--root)
			adjustdown(root);
	}
	void remove()
	{
		T tmp=headdatec[0];
		headdatec[0]=headdatec[size-1];
		headdatec[size-1]=tmp;
		size--;
		adjustup();
	}

};
int main()
{
	int arry[5]={1,4,3,2,5};
	//myhead<int> a;
	//a.inithead(5,arry);
	//a.adjust_heap(1);
	Heap<int> a(arry,5);
	a.remove();
	system("pause");
	return 0;
}
