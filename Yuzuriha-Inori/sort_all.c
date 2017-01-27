#include<stdio.h>
int sequence(int s[],int n,int key)//顺序查找改良型
{
	int i;
	for(i=0;s[i]!=key;i++)
	{
		if(i<n)
			return 1;
		else
			return -1;
	}
}//将需要查找的目的数据放在数组的最后一个 省去比较步骤
int midsort(int s[])
{
