#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int Datetype;
typedef struct Node
{
	struct Node* next;
	Datetype date;
}Node ,*Pnode;
void InitList(Pnode* phead)
{
	*phead=(Node*)malloc(sizeof(struct Node));
	if(phead==NULL)
		printf("init erro");
	(*phead)->next=NULL;
}
void Pushback(Pnode* phead,Datetype data)//β��
{
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
	//Node * i=(*phead);
	if(_new==NULL)
	{
		printf("wrong!!");
	}
	assert(phead);
	_new->date=data;
	if((*phead)->next==NULL)
	{
		(*phead)->next=_new;
		_new->next=NULL;
	}
	else
		while((*phead)->next)
		{
			(*phead)=(*phead)->next;
		}
		(*phead)->next=_new;
}
void Pusherase(Pnode* phead)//ɾ��β����
{
	//Pnode  _new=(Node*)malloc(sizeof(struct Node));
	assert(phead);
	if((*phead)->next==NULL)
	{
		*phead=NULL;
	}
			while((*phead)->next)
		{
			(*phead)=(*phead)->next;
		}
		(*phead)=NULL;
}
void PushFront(Pnode * phead,Datetype date)//ͷ��
{
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
		if(_new==NULL)
	{
		printf("wrong!!");
	}
	_new->date=date;
	if((*phead==NULL)){
		(*phead)->date=date;
		(*phead)->next=NULL;
	}
	else{
		_new->next=(*phead)->next;
		(*phead)->next=_new;
	}
}
//82BEI;61BEI;69BEI;75BEI;103BEI;113BEI
void Popfront(Pnode *phead)
{
	/*Pnode _new;*/
	assert((*phead));
	if((*phead)->next==NULL)
	{
		printf("NULL");
	}
	//_new=(*phead);
	(*phead)=(*phead)->next;
}
//uwcp15Ats4
Pnode Find(Pnode phead,Datetype date)
{
	Pnode _new;
	assert(phead);
	_new=phead;
	while(NULL!=phead->next)
	{
		_new=phead;
		if(date==phead->date)
		{
			
			return (_new);
		}
		else 
		{
			phead=phead->next;
		}
	}
	printf("this date is not live");
}
void Insert(Pnode*phead,Pnode pos,Datetype date)//���뵽posλ�õ�����
{
	Pnode mid;
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
	if((*phead)==NULL)
	{
		_new=(*phead)->next;
	}
	else
	{
		while((*phead)!=pos)//δ�ж�pos������
		{
			(*phead)=(*phead)->next;
		}
		mid=(*phead)->next;
		(*phead)->next=_new;
		_new->next=mid;
	}
}
void Erase(Pnode *phead,Pnode pos)
{
	Pnode _new;
		if((*phead)==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while((*phead)!=NULL)//δ�ж�pos������
		{
			_new=(*phead);
			if(pos==(*phead)){
				_new->next=(*phead)->next;}
			(*phead)=(*phead)->next;

		}
		}
}
void Remove(Pnode *phead,Datetype date)
{
		Pnode _new;
		if((*phead)==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while((*phead)!=NULL)
		{
			_new=(*phead);
			if(date==(*phead)->date){
				_new->next=(*phead)->next;}
			(*phead)=(*phead)->next;
			break;//�ҵ���ֱ������

		}
		}
}

void Removeall(Pnode *phead,Datetype date)
{
		Pnode _new;
		if((*phead)==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while((*phead)!=NULL)
		{
			_new=(*phead);
			if(date==(*phead)->date){
				_new->next=(*phead)->next;}
			(*phead)=(*phead)->next;

		}
		}
}
//xbnyzxkl0308
//	QQ340032071
int size(Pnode phead)//����Ĵ�С
{
	int n=0;
	if(phead->next==NULL)
	{
		return 0;
	}
	else
	{
		while(phead!=NULL)
		{
			phead=phead->next;
			n++;
		}
		return n;
	}
}
Pnode Front(Pnode head)//���ص�һ���ڵ��ַ
{
	if(head!=NULL)
		return head->next;
	else 
		return ;
}

Pnode last(Pnode phead)//�������һ���ڵ�λ��
{
			Pnode _new;
			if(phead==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while(phead!=NULL)
		{
			_new=phead;
			_new->next=phead->next;}
			phead=phead->next;

		}
		return _new;
}
int empty(Pnode head)//�п� �շ���1 �ǿշ���0
{
	if(head->next==NULL)
		return 0;
	else 
		return 1;
}
void print(Pnode phead)
{
	int n=0;
	if(phead->next==NULL)
	{
		return ;
	}
	else
	{
		while(phead!=NULL)
		{
			phead=phead->next;
			printf("%d",phead->date);
		}
		
	}
}
