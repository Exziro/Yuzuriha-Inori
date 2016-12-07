#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <search.h>

#pragma warning(disable:4996)

int mypow(int n, int k)
{
	if (k == 0 ){
		return 1;
	}

	return n*mypow(n, k-1);
}

int DigitSum(int data)
{
	if (data == 0){
		return 0;
	}

	return data % 10 + DigitSum(data/10);
}

static void swap(int *x, int *y)
{
	assert(x);
	assert(y);

	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

static void show(int arr[], int len)
{
	int i = 0;
	for (; i < len; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

static void fshow(float arr[], int len)
{
	int i = 0;
	for (; i < len; i++){
		printf("%.2f ", arr[i]);
	}

	printf("\n");
}

static void stringShow(char* arr[], int len)
{
	int i = 0;
	for (; i < len; i++){
		printf("%s\n", arr[i]);
	}

	printf("\n");
}

void selectSort(int arr[], int n)
{
	assert(arr);

	int i = 0;
	for (; i < n; i++){
		int minPos = i;
		int j = i;
		for (; j < n; j++){
			if ( arr[j] < arr[minPos] ){
				minPos = j;
			}
		}
		if (minPos != i){
			swap(&arr[i], &arr[minPos]);
		}
	}
}

static int fcmp(void *x, void *y)
{
	return (*(float*)x) > (*(float*)y) ? -1 : 1;
}

void fSort(float arr[], int len)
{
	assert(arr);

	qsort(arr, len, sizeof(float), fcmp);
}

static void stringCmp(void *x, void *y)
{
	return strcmp((char*)x, (char *)y);//X
	//return strcmp(*((char **)x), *((char **)y));
}

void stringSort(char *arr[], int len)
{
	assert(arr);
	qsort(arr, len, sizeof(char*), stringCmp);
}

int main()
{
	char *carr[] = { "bbb", "ccc", "aaa", "zzz", "xxx" };
	int len = sizeof(carr) / sizeof(carr[0]);
	stringShow(carr, len);
	stringSort(carr, len);
	stringShow(carr, len);
	//float arr[] = { 12.1, 15.6, 1.2, 13.2, 14.3, 15.6, 1.2,5.6, 8.9 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//fshow(arr, len);
	//fSort(arr, len);
	//fshow(arr, len);
	//static void fshow(float arr[], int len);
	/*int arr[] = { 12, 23,21,23,1,22,1,43,0,4,56,56,5,45,34,34};
	int len = sizeof(arr) / sizeof(arr[0]);
	show(arr, len);
	selectSort(arr, len);
	show(arr, len);*/
	//printf("%d\n", DigitSum(1927));
	//int n, k;
	//printf("Please Enter <n, k>: ");
	////Sleep(3000);
	//scanf("%d%d", &n, &k);
	//printf("res : %d\n", mypow(n, k));
	system("pause");
	return 0;
}