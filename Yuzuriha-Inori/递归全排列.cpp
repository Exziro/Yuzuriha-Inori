#include<iostream>
using namespace std;
void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=a;
}
void printfreverse(int *arry,int size,int N)
{
	if(size==N)
	{
		for(size_t idx;idx<size;idx++)
		{
			cout<<arry[idx]<<" ";
			cout<<endl;
		}
	}
	else
	{
		for(size_t idx=N;idx<size;++idx)
		{
			Swap(arry[idx],arry[N]);
			printfreverse(arry,size,(N+1));
			Swap(arry[idx],arry[N]);
		}
	}
}
int main()
{
	int arr[3];
	arr[1]=1;
	arr[2]=3;
	arr[0]=2;
	arr[3]=4;
	printfreverse(arr,4,3);
	return 0;
}

