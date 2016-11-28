#include <stdio.h>
#include <assert.h>
#include <windows.h>
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int op(int a, int b, int(*p)(int, int))
//{
//	assert(p);
//	printf("%d + %d = %d\n",a, b, p(a, b));
//}

int intCmp(void *x, void *y)
{
	int *_x = (int *)x;
	int *_y = (int *)y;

	return *_x - *_y;
}

void bubbleSort(void *data, int nums, int width, int (*cmp)(void *, void*))
{
	assert(data);
	int i = 0;
	for (; i < nums - 1; i++){
		int j = 0;
		int flag = 0;
		char *start = (char*)data;
		for (; j < nums - 1 - i; j++){
			if ( cmp(start, start+width) > 0 ){
				int k = 0;
				for (; k < width; k++){
					start[k] ^= start[k+width];
					start[k + width] ^= start[k];
					start[k] ^= start[k + width];
				}
				flag = 1;
			}
			start += width;
		}
		if (!flag){
			break;
		}
	}
}

void show(int arr[], int len)
{
	assert(arr);

	int i = 0;
	for (; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

struct {
	int a;
	char b;
	float c;
}*x;

struct {
	int a;
	char b;
	float c;
}y;

int main()
{
	x = &y;
	//int arr[] = {45,4,3,23,34,4,45,5,6,75,68,9}; 
	//int len = sizeof(arr) / sizeof(arr[0]);
	//show(arr, len);
	////bubbleSort(arr, len);
	//bubbleSort(arr, len, sizeof(int), intCmp);
	//show(arr, len);
	//op(10, 20, add);
	system("pause");
	return 0;
}




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int mydiv(int a, int b)
{
	if(b == 0){
		printf("your proc is diving zero!!\n");
		return -1;
	}
	return a / b;
}

int quit(int a, int b)
{
	printf("Bye~~\n");
	exit(0);
}

int help(int a, int b)
{
	printf("Usage: use option [0, 1, 2, 3, 4, 5]\n");
	return 0;
}

int main()
{
//	int (*p[6])(int,int) = {help, add, sub, mul, mydiv, quit};
	int (*p[6])(int,int);
	int (*(*q)[6])(int, int);
	q = &p;
	printf("%p, %p\n", q, q+1);
	p[0]=&help;
	while(1){
	    printf("########################################\n");
	    printf("### 1. add ################# 2. sub ####\n");
	    printf("### 3. mul ################# 4. div ####\n");
	    printf("### 5. quit ################ 0. help ###\n");
	    printf("########################################\n");

	    int s = 0;
	    printf("Please Select<0~5>: ");
	    scanf("%d", &s);
	    if( s < 0 || s > 5 ){
	    	s = 5;
	    }

        int x, y;
	    if( s != 0 && s != 5 ){
        	printf("Please Enter Your data<x, y>: ");
        	scanf("%d%d", &x, &y);
	    }
	    printf("result> %d\n", p[s](x, y));
	}
	return 0;
}