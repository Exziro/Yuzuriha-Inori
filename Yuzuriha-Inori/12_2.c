#include<stdio.h>
#include<windows.h>
union un{
	int a;
	char b2;
	//char c[5];
	int k;
	//double d;
	float f;
}obj;
int main()
{
	//const int a = 10;
	//int b[a];
	//int *p = (int *)malloc(10 * sizeof(int));
	//printf("%d\n", sizeof(struct A));
	//printf("%p, %p, %p, %p\n", &obj, &(obj.a), &(obj.b), obj.c);
	printf("%d\n", sizeof(obj));
	//printf("%d\n", sizeof(obj));
	//obj.a = 0xf;
	//obj.y = 0xe;
	//obj.b = 0x21;
	//obj.c = 0x1def;
	//obj.x = 0x1f;
	//printf("%d, %d, %d\n", obj.a, obj.b, obj.c);
	system("pause");
	return 0;
}
