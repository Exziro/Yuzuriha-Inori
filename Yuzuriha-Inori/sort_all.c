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
int midsort(int s[],int key)//�۰���ҷ�
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
struct index /*�����Ľṹ*/
{
int key;
int start;
int end;
} index_table[4]; /*����ṹ������*/
int block_search(int key, int a[]) /*�Զ���ʵ�ַֿ����*/
{
int i, j;
i = 1;
while (i <= 3 && key > index_table[i].key) /*ȷ�����Ǹ�����*/
i++;
if (i > 3) /*���ڷֵõĿ������򷵻�0*/
return 0;
j = index_table[i].start; /*j���ڿ鷶Χ����ʼֵ*/
while (j <= index_table[i].end && a[j] != key) /*��ȷ���Ŀ��ڽ��в���*/
j++;
if (j > index_table[i].end) /*������ڿ鷶Χ�Ľ���ֵ����˵��û��Ҫ���ҵ���,j��0*/
j = 0;
return j;
}
main()
{
int i, j = 0, k, key, a[16];
printf("please input the number:\n");
for (i = 1; i < 16; i++)
scanf("%d", &a[i]); /*������С�����15����*/
for (i = 1; i <= 3; i++)
{
index_table[i].start = j + 1; /*ȷ��ÿ���鷶Χ����ʼֵ*/
j = j + 1;
index_table[i].end = j + 4; /*ȷ��ÿ���鷶Χ�Ľ���ֵ*/
j = j + 4;
index_table[i].key = a[j]; /*ȷ��ÿ���鷶Χ��Ԫ�ص����ֵ*/
}
printf("please input the number which do you want to search:\n");
scanf("%d", &key); /*����Ҫ��ѯ����ֵ*/
k = block_search(key, a); /*���ú������в���*/
if (k != 0)
printf("success.the position is :%d\n", k); /*����ҵ��������������λ��*/
else
printf("no found!"); /*��δ�ҵ��������ʾ��Ϣ*/
}