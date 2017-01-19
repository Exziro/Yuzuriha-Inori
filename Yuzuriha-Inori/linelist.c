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
void Pushback(Pnode* phead,Datetype data)//Î²²å
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
void Pusherase(Pnode* phead)//É¾³ýÎ²Á´±í
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
void PushFront(Pnode * phead,Datetype date)
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
