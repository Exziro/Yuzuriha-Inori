#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"addressbook.h"
#define INIT_NUMBER 128
#define MAXNAME 20
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

	person_p flash=(person_p)realloc(p->contactlist,p->cap+INIT_NUMBER);
	assert(p);
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
void Destorycontact(contact_p p)//删除通讯录
{
	assert(p);
	free(p->contactlist);
	p->contactlist=NULL;
	free(p);
	p=NULL;
}

int Add(contact_p p1,person_t p2 )//添加元素
{
	int pos;
	assert("p1");
	//printf("please enter some message:like name,sex,age,phone,address");
	/*scanf("%s%c%d%s%s",p2.name,&p2.sex,&p2.age,&p2.phone,&p2.address)*/;//第一个是数组传递的是首元素地址不需再取地址
	assert("p2");
	if(!isful(p1)||aadcontact(p1)){
		pos=p1->size;
		p1->contactlist[pos]=p2;
		p1->size++;
	}

return ;}


void Show(contact_p p)//按顺序打印
{
	int i=0;
	assert(p);
	for(i=0;i<p->size;i++)
	{
		printf("%16s | %1c | %3d | %16s | %32s\n",p->contactlist[i].name,p->contactlist[i].sex,p->contactlist[i].phone,p->contactlist[i].phone,p->contactlist[i].address);
	}
	printf("NOENE");
}
		
		//void Empty();

		//void Sort();
//void Change();
void Empty(contact_p p)//清空
{
	p->size=0;
}
void Find(contact_p p)//查找相关元素
{
	int i=0;
	char name[MAXNAME];
	assert(p);
	printf("main name :");
	scanf("%c",name);
	for(i=0;i<p->size;i++)
		if(strcmp(name,p->contactlist[i].name)==0){
	    printf("%16s | %1c | %3d | %16s | %32s\n",p->contactlist[i].name,p->contactlist[i].sex,p->contactlist[i].phone,p->contactlist[i].phone,p->contactlist[i].address);
		}
		else 
			printf("wrong name");
}
void Change(contact_p p)
{
	int i=0;
	char name[MAXNAME];
	assert(p);
	printf("main name :");
	scanf("%c",name);
	for(i=0;i<p->size;i++)
		if(strcmp(name,p->contactlist[i].name)==0){
	    printf("%16s | %1c | %3d | %16s | %32s\n",p->contactlist[i].name,p->contactlist[i].sex,p->contactlist[i].phone,p->contactlist[i].phone,p->contactlist[i].address);
			printf("please change some message:like name,sex,age,phone,address");
			scanf("%s%c%d%s%s",p->contactlist[i].name,p->contactlist[i].sex,p->contactlist[i].phone,p->contactlist[i].phone,p->contactlist[i].address);
		}
		else
			printf("wrong name");
}
