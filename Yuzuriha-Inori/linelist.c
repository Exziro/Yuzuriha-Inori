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
void Pusherase(Pnode* phead)//ɾ��β����
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
void PushFront(Pnode * phead,Datetype date)//ͷ��
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
	(*phead)=(*phead)->next;//�˴�ʹ����������Ϊͷָ�뱻����һ����ֵ�ڵ�
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
void Insert(Pnode*phead,int pos,Datetype date)//���뵽posλ�õ�����
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
		while(i==pos)//δ�ж�pos������
		{
			i++;
			phead1=phead1->next;
		}
		mid=phead1->next;
		phead1->next=_new;
		_new->next=mid;
	}
}
void Erase(Pnode *phead,int pos)//ɾ��ָ���ڵ�
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
		while(phead1!=NULL&&(pos==i+1))//δ�ж�pos������
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
			break;//�ҵ���ֱ������
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
int size(Pnode phead)//����Ĵ�С
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
void reverse(Pnode phead)//�����ӡ
{
	if(phead==NULL)
	{
		return ;
	}                      //�˴�ֱ�Ӵ�ӡ��Ϊ˳���ӡ
	if(phead->next!=NULL){
		reverse(phead);
	}
	printf("%d",phead->date);
}
void	DeletNotTailNode(Pnode *phead)//ɾ����ͷ�����ָ���ڵ�  ������Ҫ���뵱ǰ�ڵ�
{
	assert((*phead));
	(*phead)->date=(*phead)->next->date;//����һ�ڵ��ֵ���Ƶ���ǰ�ڵ�ɾ����һ�ڵ� ����ɾ����ǰ�ڵ�
	(*phead)->next=(*phead)->next->next;
}

void InsertNotTailNode(Pnode *phead,Datetype date)//����ͷ�������ͷ�ڵ�ǰ�����½ڵ�
{
	Pnode _new;
	Pnode phead1=*phead;
	Datetype i=0;
	_new->date=date;
	_new->next=phead1->next;
	phead1->next=_new;//���½ڵ���뵽��ǰ�ڵ����һ���ڵ�
	i=phead1->date;
	phead1->date=_new->date;
	_new->date=i;//���������ڵ������ϵ�ֵ
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