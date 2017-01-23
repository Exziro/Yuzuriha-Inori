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
void Pushback(Pnode* phead,Datetype data)//尾插
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
void Pusherase(Pnode* phead)//删除尾链表
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
void PushFront(Pnode * phead,Datetype date)//头插
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
void Insert(Pnode*phead,Pnode pos,Datetype date)//插入到pos位置的数据
{
	Pnode mid;
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
	if((*phead)==NULL)
	{
		_new=(*phead)->next;
	}
	else
	{
		while((*phead)!=pos)//未判断pos点问题
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
		while((*phead)!=NULL)//未判断pos点问题
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
			break;//找到后直接跳出

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
int size(Pnode phead)//链表的大小
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
Pnode Front(Pnode head)//返回第一个节点地址
{
	if(head!=NULL)
		return head->next;
	else 
		return ;
}

Pnode last(Pnode phead)//返回最后一个节点位置
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
int empty(Pnode head)//判空 空返回1 非空返回0
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
