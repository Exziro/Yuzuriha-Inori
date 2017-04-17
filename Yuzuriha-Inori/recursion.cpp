#include<iostream>
using namespace std;
int Fib(int Fisrt,int second,int n)//斐波那契数列递归形势
{
	if(n<3)
	{
		return 1;
	}
	if(3==n)
	{
		return Fisrt+second;
	}
	return Fib(second,Fisrt+second,n-1);
}
typedef int node;
void reverseprintf(int a)
{
	a=a->next;
	while(a)
	{
		reverseprintf(a);
		cout<<a<<endl;
	}
	
}
int BinSearch(int Array[],int low,int high,int key)  //erfen
{  
       if (low<=high)  
       {  
            int mid = (low+high)/2;  
            if(key == Array[mid])  
                return mid;  
            else if(key<Array[mid])  
                return BinSearch(Array,low,mid-1,key);  
            else if(key>Array[mid])  
                return BinSearch(Array,mid+1,high,key);  
        }  
        else  
            return -1;  
}  
