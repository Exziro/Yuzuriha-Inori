#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	char bar[102];
	memset(bar,0,102*sizeof(char));
	bar[0]=0;
	while(i<=100)
	{
		printf("[%s][-][/][/]\r",bar);//������ˢ��
		fflush(stdout);//����ˢ�»���
		bar[i]='*';
		i++;
		bar[i]=0;
	}
	return 0;
}
