#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include<stdlib.h>

//int fun(int x, int y)
//{
//	int c = 0xcccccccc;
//	return c;
//}
//
//int main()
//{
//	int a = 0xaaaaaaaa;
//	int b = 0xbbbbbbbb;
//	int ret = fun(a, b);
//	printf("you should running here\n");
//	system("pause");
//	return 0;
//}

//int main(int argc, char *argv[])
//{
//	int i = 0;
//	for (; i < argc; i++)
//	{
//		printf("%d : %s\n",i ,argv[i]);
//	}
//	system("pause");
//	return 0;
//}

//static void myPutInt(int a)
//{
//	int prev = a / 10;
//	if ( prev != 0 ){
//		myPutInt(prev);
//	}
//	putchar(a % 10 + '0');
//}
//int my_printf(const char*format, ...)
//{
//	assert(format);
//	va_list arg_list;
//	va_start(arg_list, format);
//
//	const char *start = format;
//	while (*start != '\0'){
//		if (*start == '%'){
//			start++;
//			switch (*start){
//			case 'd':
//			{
//			    int _int = va_arg(arg_list, int);
//				myPutInt(_int);
//			}
//				break;
//			case 'c':
//			{
//				char _char = va_arg(arg_list, char);
//				putchar(_char);
//			}
//				break;
//			case 's':
//			{
//				char *_string = va_arg(arg_list, char *);
//				while (*_string){
//					putchar(*_string++);
//				}
//			}
//				break;
//			case 'f':
//			{
//				double f = va_arg(arg_list, double);
//			}
//				break;
//			default:
//			{
//
//			}
//				break;
//			}
//		}
//		else{
//			putchar(*start);
//		}		
//		start++;
//	}
//
//	va_end(arg_list);
//}
//
//int main()
//{
//	int a = -30;
//	const char *msg = "aaaaa";
//	char c = 'c';
//	my_printf("hello bit : %d, hello world : %c, hello bitworld : %s\n",\
//		a, c, msg);
//	system("pause");
//	return 0;
//}
//int main(int argc,char **argv)
//{
//	while(*++argv!=NULL)
//		printf("%s\n",*argv);
//	system("pause");
//	return EXIT_SUCCESS;
//}
int main()
{
	int a[]={1,3,4,5,6,7,8,9,21};
	int i=0;
	int j=0;
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		for(j=0;j<sizeof(a)/sizeof(a[0]);j++)
		{
			if(a[j]<a[i])
				a[i]=a[j];
				