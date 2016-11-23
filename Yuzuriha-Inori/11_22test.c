#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <string.h>

void *my_memmove(void *dst, void *src, int count)
{
	assert(dst);
	assert(src);

	char *_dst = (char*)dst;
	char *_src = (char*)src;
	char *ret = _dst;

	if (_src < _dst && _src + count > _dst){//ºó-¡·Ç°
		char *_dst_end = _dst + count - 1;
		char *_src_end = _src + count - 1;
		while (count--){
			*_dst_end = *_src_end;
			_dst_end--, _src_end--;
		}

	}else{
		while (count--){
			*_dst = *_src;
			_dst++, _src++;
		}
	}
	return ret;
}

int main()
{
	char name[] = "abcdef";
	printf("%d\n", sizeof(name[0]));
	printf("%d\n", sizeof(&name));
	printf("%d\n", sizeof(*name));
	printf("%d\n", sizeof(&name + 1));
	printf("%d\n", sizeof(name + 1));
	printf("%d\n", sizeof(name));
	printf("%d\n", strlen(name));
	printf("%d\n", strlen(&name));
	printf("%d\n", strlen(&name + 1));
	printf("%d\n", strlen(name + 1));
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a)); 
	//printf("%d\n", sizeof(a + 0));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(a[1]));
	//printf("%d\n", sizeof(&a));
	//printf("%d\n", sizeof(&a + 1));
	//printf("%d\n", sizeof(&a[0]));
	//printf("%d\n", sizeof(&a[0] + 1));
	//printf("%d\n", sizeof(*&a));

	//printf("%p\n", a);
	//printf("%p\n", &a);
	//printf("%p\n", a+1);
	//printf("%p\n", &a+1);
	//printf("%d\n", sizeof(void*));
	//printf("%d\n", sizeof(void));
	//int a = 0;
	/*char src[32] = "hello bit";
	char dst[32];
	my_memmove(src+1, src, strlen(src) + 1);
	printf("%s\n", src);*/
	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

static int add(int a, int b)
{
	return a + b;
}

static int sub(int a, int b)
{
	return a - b;
}

static int mul(int a, int b)
{
	return a * b;
}

static int mydiv(int a, int b)
{
	if( b == 0 ){
		printf("warning : div data is zero!\n");
		return -1;
	}
	return a / b;
}

static void  usage(const char *proc)
{
	printf("Usage: %s -[a|s|m|d] data1 data2\n", proc);
}

int main(int argc, char *argv[])
{
	if( argc != 4 ){
		usage(argv[0]);
		return 1;
	}

	int data1 = atoi(argv[2]);
	int data2 = atoi(argv[3]);

	if(0 == strcmp("-a", argv[1])){
		printf("res : %d\n", add(data1, data2));
	}else if(0 == strcmp("-s", argv[1])){
		printf("res : %d\n", sub(data1, data2));
	}else if(0 == strcmp("-m", argv[1])){
		printf("res : %d\n", mul(data1, data2));
	}else if(0 == strcmp("-d", argv[1])){
		printf("res : %d\n", mydiv(data1, data2));
	}else{
		usage(argv[0]);
	}
	return 0;
}
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#pragma warning(disable: 4996)
//void reverse_print(const char *msg)
//{
//	if ( *msg == '\0' ){
//		return;
//	}
//	reverse_print(msg + 1);
//	printf("%c ", *msg);
//}

//int add(int a, int b)
//{
//	return a + b;
//}

void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
//up
void bubbleSort(int arr[], int len)
{
	assert(arr);
	assert(len > 0);
	int i = 0;
	for (; i < len - 1; i++){
		int j = 0;
		int flag = 0;
		for (; j < len - 1 - i; j++){
			if (arr[j] > arr[j + 1]){
				flag = 1;
				swap(&arr[j], &arr[j + 1]);
			}
		}
		if ( flag == 0 ){
			break;
		}
	}
}
static void show(int arr[], int len)
{
	int i = 0;
	for (; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void jo_switch(int arr[], int len)
{
	assert(arr);
	assert(len > 0);

	int i = 0;
	int j = len -1;

	while (i < j){
		while(i < j && (arr[i] & 1)){ // ÆæÊý
			i++;
		}
		while (i < j && !(arr[j] & 1)){
			j--;
		}
		if (i < j){
			swap(&arr[i], &arr[j]);
			i++, j--;
		}
	}
}
int yangFind(int arr[][5]/*int (*arr)[5]*/, int rows, int data)
{
	assert(arr);
	int row = 0;
	int col = 4;

	while (row < 5 && col >= 0){
		if ( data > arr[row][col] ){
			row++;
		}
		else if (data < arr[row][col] ){
			col--;
		}
		else{
			return 1;
		}
	}

	return 0;
}

unsigned int findFirstOnly(const char *msg)
{
	int count[256];
	memset(count, 0, 256*sizeof(int));

	char *start = msg;
	while (*start != '\0'){
		count[(int)*start]++;
		start++;
	}
	start = msg;
	while (*start != '\0'){
		if (count[(int)*start] == 1){
			return *start;
		}
		start++;
	}
	return 256;
}

int main(int argc, char *argv[])
{
	//const char *str = "abcdef1234";
	//reverse_print(str);
	//printf("\n");
	//if ( argc != 4 ){
	//	printf("argv error\n");
	//	system("pause");
	//	return -1;
	//}
	//if (0 == strcmp("-a", argv[1])){
	//	printf("res : %d\n", add(atoi(argv[2]), atoi(argv[3])));
	//}
	//else{
	//	printf("error!\n");
	//}
	//int arr[] = {3200,12,34,45,56,67,78,89,67,56,1};
	//int len = sizeof(arr) / sizeof(arr[0]);
	//show(arr, len);
	//bubbleSort(arr, len);
	//show(arr, len);
	//int arr[] = {3200,12,34,45,56,67,78,89,67,56,1};
	//int len = sizeof(arr) / sizeof(arr[0]);
	//show(arr, len);
	//jo_switch(arr, len);
	//show(arr, len);

	//int arr[][5] = {
	//	{ 2, 3, 4, 5, 6 },
	//	{ 12, 34, 45, 56, 67 },
	//	{ 120, 340, 450, 560, 670 },
	//	{ 1200, 3400, 4500, 5600, 6700 },
	//	{ 1201, 3401, 4501, 5601, 6701 }
	//};
	//int data = 0;
	//printf("Please Enter : ");
	//scanf("%d", &data);

	//int ret = yangFind(arr, 5,data);
	//printf("%d\n" ,ret );

	const char *msg = "aaaabfqccrbdw";
	unsigned int only = findFirstOnly(msg);
	if (only == 256){
		printf("not found!\n");
	}
	else{
		printf("%c\n", (char)only);
	}

	system("pause");
	return 0;
}