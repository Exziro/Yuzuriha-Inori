#include<stdio.h>
#include<string.h>
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
int midsort(int s[],int key)//折半查找法
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
#include <stdio.h>
struct index /*定义块的结构*/
{
int key;
int start;
int end;
} index_table[4]; /*定义结构体数组*/
int block_search(int key, int a[]) /*自定义实现分块查找*/
{
int i, j;
i = 1;
while (i <= 3 && key > index_table[i].key) /*确定在那个块中*/
i++;
if (i > 3) /*大于分得的块数，则返回0*/
return 0;
j = index_table[i].start; /*j等于块范围的起始值*/
while (j <= index_table[i].end && a[j] != key) /*在确定的块内进行查找*/
j++;
if (j > index_table[i].end) /*如果大于块范围的结束值，则说明没有要查找的数,j置0*/
j = 0;
return j;
}
main()
{
int i, j = 0, k, key, a[16];
printf("please input the number:\n");
for (i = 1; i < 16; i++)
scanf("%d", &a[i]); /*输入由小到大的15个数*/
for (i = 1; i <= 3; i++)
{
index_table[i].start = j + 1; /*确定每个块范围的起始值*/
j = j + 1;
index_table[i].end = j + 4; /*确定每个块范围的结束值*/
j = j + 4;
index_table[i].key = a[j]; /*确定每个块范围中元素的最大值*/
}
printf("please input the number which do you want to search:\n");
scanf("%d", &key); /*输入要查询的数值*/
k = block_search(key, a); /*调用函数进行查找*/
if (k != 0)
printf("success.the position is :%d\n", k); /*如果找到该数，则输出其位置*/
else
printf("no found!"); /*若未找到则输出提示信息*/
}