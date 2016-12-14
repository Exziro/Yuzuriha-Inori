#include<stdio.h>
#include<assert.h>
#include"addressbook.h"
#define INIT_NUMBER 128
void menue()
{
	printf("*****AddressBook****\n");
	printf("********************\n");
	printf("***1.add****2.Find**\n");
	printf("***3.change*4.show**\n");
	printf("***5.empty**6.sort**\n");
	printf("*******0.excit******\n");
}
static int isful(contact_p p)
{
	assert(p);
	if(p->size>p->cap)
		return 0;
	else 
		return 1;
}

static int  aadcontact(contact_p p)//自增一个新的存储空间
{
	assert(p);
	contact_p flash=(contact_p)realloc(p->contactlist,p->cap+INIT_NUMBER);
	if(NULL==flash)
	{
		perror("malloc");
		return 0;
	}
	p->contactlist=(person_p)flash;//erro
	p->cap+=INIT_NUMBER;
	return 1;
}


void initcontact(contact_pp p )//初始化一个通讯录
{
	*p=(contact_p)malloc(sizeof(contact_t));
	if(*p==NULL)
	{
		perror("malloc");
		exit(1);
	}
	(*p)->contactlist=(person_p)malloc(sizeof(person_t)*INIT_NUMBER);
	if(*p==NULL)
	{
		perror("malloc");
		exit(2);
	}
	(*p)->cap=INIT_NUMBER;
	(*p)->size=0;
}
void Destorycontact(contact_p p)
{
	assert(p);
	free(p->contactlist);
	p->contactlist=NULL;
	free(p);
	p=NULL;
}

void Add(contact_p p1,person_p p2 );
{
	assert("p1");
	assert("p2");
	if(!isful(p1)||aadcontact(p1))
		int

void Find();
void Show();
void Empty();
void Sort();
void Change();
