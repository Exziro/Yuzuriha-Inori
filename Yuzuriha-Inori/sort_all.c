#include<stdio.h>
int sequence(int s[],int n,int key)//˳����Ҹ�����
{
	int i;
	for(i=0;s[i]!=key;i++)
	{
		if(i<n)
			return 1;
		else
			return -1;
	}
}//����Ҫ���ҵ�Ŀ�����ݷ�����������һ�� ʡȥ�Ƚϲ���
int midsort(int s[])
{
