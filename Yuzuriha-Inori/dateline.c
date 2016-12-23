#include<stdio.h>
#include<windows.h>
typedef int DateType;
#define Maxsize 10;
typedef struct SeqList 
{
	DateType arr[Maxsize];
	int size;
}Seqlist;
void InitSqlist(Seqlist * seq);

