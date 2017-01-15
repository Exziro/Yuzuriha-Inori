#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>
#define MAX 10
#define erro 1
typedef int DateType;
typedef struct SeqList
{
	DateType *arr;
	int size;//空间大小
	int longside;//实际占有长度
}Seqlist;
DateType InitSqlist(Seqlist *seq)//初始化分配空间
{
	seq->arr=(DateType*)malloc(MAX*sizeof(DateType));
	if(!seq->arr)
		exit(erro);
	seq->longside=0;
	seq->size=MAX;
	return 0;

}
DateType Full(Seqlist *seq)//判满
{
	if(seq->longside==seq->size)
		return 1;
	else
		return 0;
}
DateType Addspace(Seqlist *seq)
{
	DateType *newspace;
	if (Full(seq))
	{
		newspace=(DateType*)realloc(seq->arr,(seq->longside+MAX)*sizeof(DateType));
	if(!newspace)  exit(erro);
	seq->arr=newspace;
	seq->size+=MAX;//增加上限

	}
}


DateType pushback(Seqlist * seq,DateType _date)
{
	if(Full(seq))
	{
		Addspace(seq);
	}
	else
	{
		if(seq->longside==0)
		{
			seq->arr[seq->longside]=_date;
		}
		else
		{
			seq->arr[seq->longside+1]=_date;
		}
	}
	return 0;
}
void Popback(Seqlist *seq)
{
	assert(seq);
	seq->longside-=1;
}
void Pushifront(Seqlist * seq,DateType _data)
{
	int i =0;
	assert(seq);
	assert(_data);
	if(Full(seq))
	{
		Addspace(seq);
	}
	else
	{
	for(i=0;i<seq->longside+1;i++)
	{
		seq->arr[i+1]=seq->arr[i];
	}
	seq->arr[0]=_data;
	seq->longside++;//先加后加是否会出现问题
	}
}
void PopFront(Seqlist *seq)
{

