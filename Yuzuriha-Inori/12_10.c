#include<stdio.h>
#include<windows.h>
int Change(char*p)
{
	int sum =0;
	while(*p!='\0')
	{
		sum=10*sum+*p-'0';
		p++;
	}
	return sum;
}
int main()
{
	char a[]="1234";
	int p = 0;
	p=Change(a);
	printf("%d\n",p);
	system("pause");
	return 0;
}
