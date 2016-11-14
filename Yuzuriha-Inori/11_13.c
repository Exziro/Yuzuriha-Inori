#include<stdio.h>
#include<windows.h>
#include<stdarg.h>
void myprintf(char*fmt,...)
{
	va_list pArg;
	char c;
	va_start(pArg,fmt);
	do
	{
		c=*fmt;
		if(c!='%')
		{
			putchar(c);
		}
		else
		{
			switch(*++fmt)
			{
			case 'd':
				printf("%d",*((int*)pArg));
				break;
			case 'f':
				printf("%f",*((float*)pArg));
				break;
			default:
				break;
			}
		}
		++fmt;
	}while(*fmt!='\0');
	va_end(pArg);
	return;
}
int main()
{	int i=1234;
	int j=5678;
	myprintf("test one:=%d",i);
	myprintf("test one:=%f",j);
	system("pause");
	return 0;
}
