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
	int size;//�ռ��С
	int longside;//ʵ��ռ�г���
}Seqlist;
DateType InitSqlist(Seqlist *seq)//��ʼ������ռ�
{
	seq->arr=(DateType*)malloc(MAX*sizeof(DateType));
	if(!seq->arr)
		exit(erro);
	seq->longside=0;
	seq->size=MAX;
	return 0;

}
DateType Full(Seqlist *seq)//����
{
	if(seq->longside==seq->size)
		return 1;
	else
		return 0;
}
DateType Addspace(Seqlist *seq)//�Զ���������
{
	DateType *newspace;
	if (Full(seq))
	{
		newspace=(DateType*)realloc(seq->arr,(seq->longside+MAX)*sizeof(DateType));
	if(!newspace)  exit(erro);
	seq->arr=newspace;
	seq->size+=MAX;//��������

	}
		return 0;
}


DateType pushback(Seqlist * seq,DateType _date)//β��
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
void Pushifront(Seqlist * seq,DateType _data)//ͷ��
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
	for(i=seq->longside+1;i>0;i--)
	{
		seq->arr[i+1]=seq->arr[i];
	}
	seq->arr[0]=_data;
	seq->longside++;//�ȼӺ���Ƿ���������
	}
}
void PopFront(Seqlist *seq)//ͷɾ
{
	int i =0;
	assert(seq);
	
	if(seq->longside!=0)
	{
		for(i=0;i<seq->longside-1;i++){//��Ҫȷ���Ӽ�
			seq->arr[i]=seq->arr[i+1];
		}

	}
	else
		return ;
}
void InsertPos(Seqlist *seq,int _size,DateType _date)
{
	int i =0;
	assert(seq);
	assert(_date);
	if(_size<1||_size>seq->longside+2){
		printf("erro!!");
	}
	if(_size==seq->longside+1)
	{
		Addspace(seq);
	}
	{
		for(i=seq->longside;i<_size;i--){
			seq->arr[i+1]=seq->arr[i];
	}
	seq->arr[_size]=_date;
	seq->longside++;
	}
}
void Erase(Seqlist *seq,int _size)
{
		int i =0;
	assert(seq);
	if(_size<1||_size>seq->longside){
		printf("erro!!");
	}
	{
		if(seq->longside!=0)
	{
		for(i=0;i<seq->longside-1;i++)//��Ҫȷ���Ӽ�
			seq->arr[i]=seq->arr[i+1];
		
	}
	seq->longside--;
	if(seq->longside==0)
	{
		printf("No number!!!");
	}
}
}

int Find(Seqlist *seq,DateType _date)
{
	int i;
	assert(seq);
	for(i=0;i<seq->longside;i++){
		if(_date==seq->arr[i]){
			return 1;
			break;
		}
	}
	return -1;
}
void RemoveAll(Seqlist *seq,DateType _date)
{
		int i;
	assert(seq);
	if(Find(seq,_date)==1)
	for(i=0;i<seq->longside;i++){
		if(_date==seq->arr[i]){
			Erase(seq,i);
		}
	}
	else
	{
		printf("NO number!!");
	}
}

void Bubblesort(Seqlist *seq)
{
	int i= 0;
	int j= 0;
	int mid=0;
	assert(seq);
	for(i=0;i<seq->longside-1;i++){
		for(j=0;j<seq->longside-1-i;j++)
		{
			if(seq->arr[j]>seq->arr[i])
				{seq->arr[j]=mid;
				seq->arr[j]=seq->arr[i];
				seq->arr[i]=mid;
		}
		}
	}
}
void Quicksort(Seqlist *seq)
{
	int i;
	int j=0;
	int n=0;
	int mid=seq->arr[0];
	assert(seq);
	for(n=0;n<seq->longside;n++){
	for(i=n;i<seq->longside;i++){
		if(seq->arr[i]>mid)
		{
			mid=seq->arr[i];
	}
	}
	seq->arr[n]=mid;
	}
}
int Binaryserch(Seqlist *seq,DateType date)
{
	int e=seq->longside;
	int mid =0;
	int s=0;
	assert(seq);
	while(seq->arr[s]<seq->arr[e]){
	if(date==seq->arr[e])
	{
		return 1;
	}
	if(date==seq->arr[s])
	{
		return 1;
	}
	mid=(s+e)/2;
	if(seq->arr[mid]==date)
          return 1;             //���ҳɹ�����
        if(seq->arr[mid]==date)
          e=mid+1;              //������R[mid+1..high]�в���
        else
          s=mid-1;  
	}
	return -1;
}
/////////////////////////////////////////////////////////////
int main()
{
	Seqlist test;
//	seqlist*p=test;
	InitSqlist(&test);
	pushback(&test,1);
	return 0;
}
