#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
template<class T>
class myhead
{
private:
	vector<T> headdatec;
	int size;
public:
	void inithead(const size,const T arry[])
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
	}
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
	void adjust_heap(size_t parent)  
	{  
		size_t child=parent*2+1;      
		while(child < size&&(child+1)>size)  
		{  
			if(headdatec[child] > headdatec[child+1])  
        {  
            child++;  
        }
			if(headdatec[parent]>headdatec[child])
			{
				swap(headdatec[parent],headdatec[child]);  
				parent=child;
				child=parent*2+1;
			}
		}
		 else return;
    }  
	void adjustup_heap()  
	{  
		rsize_t child=headdatec[size-1];
		size_t child=parent*2+1;      
		while(child < size&&(child+1)>size)  
		{  
			if(headdatec[child] > headdatec[child+1])  
        {  
            child++;  
        }
			if(headdatec[parent]>headdatec[child])
			{
				swap(headdatec[parent],headdatec[child]);  
				parent=child;
				child=parent*2+1;
			}
			else return;
		}
		 
    }
  
};
int main()
{
	int arry[5]={1,2,3,4,5};
	myhead<int> a;
	a.inithead(5,arry);
	a.adjust_heap(1);
	system("pause");
	return 0;
}
