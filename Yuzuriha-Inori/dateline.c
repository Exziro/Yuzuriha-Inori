#include<stdio.h>
#include<windows.h>
#include"test.h"
typedef int DateType;
#define Maxsize 10
typedef struct SeqList 
{
	DateType *arr;
	int size;
}Seqlist;
void InitSqlist(Seqlist * seq)
{
	seq->size=0;
}
//void insert(Seqlist * seq)
//{
//	//int i;
	seq->arr=malloc(1*sizeof(int));

}

