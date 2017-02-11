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
	Pnode phead1=*phead;
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
	//Node * i=(*phead);
	if(_new==NULL)
	{
		printf("wrong!!");
	}
	assert(phead);
	_new->date=data;
	if((phead1)->next==NULL)
	{
		(phead1)->next=_new;
		_new->next=NULL;
	}
	else{
		while(((phead1)->next))
		{
			(phead1)=(phead1)->next;
		}
		(phead1)->next=_new;
		_new->next=NULL;
}
}
void Pusherase(Pnode* phead)//删除尾链表
{
	//Pnode  _new=(Node*)malloc(sizeof(struct Node));
	//assert(phead);
	Pnode phead1=*phead;
	Pnode phead2=NULL;
	if((phead1)->next==NULL)
	{
		phead1=NULL;
	}
			while(phead1->next)
		{
			phead2=phead1;
			phead1=phead1->next;
		}
			phead2->next=NULL;
		free(phead1);
}
void PushFront(Pnode * phead,Datetype date)//头插
{
	Pnode phead1=*phead;
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
		if(_new==NULL)
	{
		printf("wrong!!");
	}
	_new->date=date;
	if((phead1==NULL)){
		phead1->date=date;
		phead1->next=NULL;
	}
	else{
		_new->next=(*phead)->next;
		phead1->next=_new;
	}
}
//82BEI;61BEI;69BEI;75BEI;103BEI;113BEI
void Popfront(Pnode *phead)
{
	/*Pnode _new;*/
	//Pnode phead2=NULL;
	//Pnode phead1=*phead;
	assert(phead);
	if((*phead)->next==NULL)
	{
		printf("NULL");
	}
	//_new=(*phead);
	(*phead)=(*phead)->next;
	(*phead)=(*phead)->next;//此处使用两次是因为头指针被当成一个无值节点
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
void Insert(Pnode*phead,int pos,Datetype date)//插入到pos位置的数据
{
	int i=0;
	Pnode mid;
	Pnode phead1=*phead;
	Pnode  _new=(Node*)malloc(sizeof(struct Node));
	_new->date=date;
	if(phead1==NULL)
	{
		_new=phead1->next;
	}
	else
	{
		while(i==pos)//未判断pos点问题
		{
			i++;
			phead1=phead1->next;
		}
		mid=phead1->next;
		phead1->next=_new;
		_new->next=mid;
	}
}
void Erase(Pnode *phead,int pos)//删除指定节点
{
	int i=1;
	Pnode _new;
	Pnode phead1=*phead;
		if(phead1==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while(phead1!=NULL&&(pos==i+1))//未判断pos点问题
		{
			//_new=phead1;
			//if(pos==i){
			//	phead1=phead1->next;
			//	_new->next=phead1;
			//break;}
			phead1=phead1->next;
			i++;
		}
		_new=phead1->next;
		phead1->next=_new->next;
		free(_new);
	
	}
}
void Remove(Pnode *phead,Datetype date)
{
	Pnode phead1=*phead;
		Pnode _new;
		if(phead1==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while( phead1!=NULL)
		{
			_new= phead1;
			if(date==  phead1->date){
		_new=phead1->next;
		phead1->next=_new->next;
		free(_new);
			break;//找到后直接跳出
				}
			 phead1= phead1->next;
			

		}
		}
}

void Removeall(Pnode *phead,Datetype date)
{
	Pnode phead1=*phead;
	Pnode phead2=*phead;
		Pnode _new;
		if( phead1==NULL)
	{
		printf("NO number!!");
	}
	else
	{
		while( phead1 !=NULL)
		{
			phead2=phead1;
			_new= phead1;
			if(date== phead1->date&&(phead1->next!=NULL)){
			_new=phead1->next;
		phead1->next=_new->next;
		free(_new);

		}
			else{
				phead2->next=NULL;
			}
		phead1= phead1->next;
	
			
		}
		}
}
//xbnyzxkl0308
//	QQ340032071
int size(Pnode phead)//链表的大小
{
	int n=1;
	if(phead->next==NULL)
	{
		return 1;
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
void reverse(Pnode phead)//逆序打印
{
	if(phead==NULL)
	{
		return ;
	}                      //此处直接打印即为顺序打印
	if(phead->next!=NULL){
		reverse(phead);
	}
	printf("%d",phead->date);
}
void	DeletNotTailNode(Pnode *phead)//删除无头链表的指定节点  参数需要传入当前节点
{
	assert((*phead));
	(*phead)->date=(*phead)->next->date;//将下一节点的值复制到当前节点删除下一节点 即是删除当前节点
	(*phead)->next=(*phead)->next->next;
}

void InsertNotTailNode(Pnode *phead,Datetype date)//在无头单链表非头节点前插入新节点
{
	Pnode _new;
	Pnode phead1=*phead;
	Datetype i=0;
	_new->date=date;
	_new->next=phead1->next;
	phead1->next=_new;//将新节点插入到当前节点的下一个节点
	i=phead1->date;
	phead1->date=_new->date;
	_new->date=i;//交换两个节点数据上的值
}
int main()
{
	int i=0;
	Pnode phead;
	InitList(&phead);
	Pushback(&phead,1);
	Pushback(&phead,2);
	Pushback(&phead,2);
	Pushback(&phead,4);
	Pusherase(&phead);
	PushFront(&phead,5);
	Popfront(&phead);
	Insert(&phead,3,66);
	Erase(&phead, 3);
	Remove(&phead,2);
	Pushback(&phead,2);
	Pushback(&phead,2);
	Pushback(&phead,2);
	Removeall(&phead,2);
	i=size(phead);
	last(phead);
	//i=empty(phead);
	return 0;
}
//uwcp15Ats4
//ZfBMFP4gxg
//761832
//Gc99tJ2pkw
//800021