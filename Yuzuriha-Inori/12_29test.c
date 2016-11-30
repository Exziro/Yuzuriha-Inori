//#include <stdio.h>
//
//#pragma pack(16)
//
////16 4
//struct A{
//    char a;
//    double b;
//    int c;
//};

//struct B{
//    int a1;
//    char b1;
//    double c1;
//    struct A obj;
//    struct A *objp;
//    struct A objarr[2];
//    char *d1;
//};

//int main()
//{
//	struct B obj;
//    printf("%d %d\n", sizeof(struct B), sizeof(obj));
//}

///#define D_T double*
///
///typedef double* d_t; 
///
///typedef struct A{
///int a;
///char b;
///float c;
///} A_t, *A_p, **A_pp, A_arr[20], (*A_arrp)[20];
///
///typedef char *(*(*p)[20])(char *, int *);
///
///typedef int myint;
///
///int main()
///{
///d_t a, b;
///
///printf("%d, %d\n", sizeof(a), sizeof(b));
/////p f;
/////myint a;
/////printf("%d\n", sizeof(f));
///////struct A x;
///////struct A y[20], *z;
///////z = &x;
/////A_t x;
/////A_p z;
/////z = &x;
/////A_pp y = &z;
/////
/////A_arr arr;
/////printf("%d\n", sizeof(arr));
/////
/////A_arrp arrp = &arr;
/////
/////printf("%u, %u\n", arrp, arrp+1);
///return 0;
///}
#include <stdio.h>
#include <windows.h>

#pragma pack(4)
#pragma pack()

struct A{
	char a;
	double b;
	int c;
};

struct B{
	int a1;
	char b1;
	double c1;
	struct A obj;
	struct A *objp;
	struct A objarr[2];
	char *d1;
};

int main()
{
	struct B obj;
	printf("%d\n", sizeof(struct B));
	system("pause");
	return 0;
}
//struct B;
//
//struct A{
//	int a;
//	char b;
//	double c;
//	struct B *d;
//};
//
//struct B{
//	int x;
//	double y;
//	struct A *z;
//};
//
//struct C{
//	int a;
//	char b;
//	int c[10];
//	char *d;
//};
//
//int main()
//{
//	struct C obj = {10,'b',{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },"hello world",};
//	//struct A obj;
//	printf("%p, %p, %p, %p, %p\n",&obj, &(obj.a),\
//		&(obj.b), obj.c, &(obj.d));
//	system("pause");
//	return 0;
//}