#include<stdio.h>
#include<string.h>
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
int midsort(int s[],int key)
{
	int E=strlen(s);
	int F =0;
	int mid;
	if(key==s[E])
		return E;
	if(key==s[F])
		return F;
	while(F<=E)
	{
		mid=(E+F)/2;
		if(s[mid]==key)
			return mid;
		if(key<s[mid])
		{
			E=mid-1;
		}
		else
			F=mid+1;
	}
}