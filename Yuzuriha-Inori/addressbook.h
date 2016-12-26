#include<stdio.h>
#include<windows.h>
typedef struct person
{
//	char name[256];
//	char sex;
//	unsigned char age;
//	char phone[16];
//	char address[256];
//}person_t,*person_p,**person_pp;
//typedef struct contact 
//{
//	int cap;
//	int size;
//	person_p contactlist;
//}contact_t,*contact_p,**contact_pp;

void menue();
void initcontact(contact_pp p);//初始化
static int isful(contact_p p);//判断创建的内容是否已满
static int  aadcontact(contact_p p);//自增一个新的存储空间
void Destorycontact(contact_p p);//清空
int Add(contact_p p1,person_t p2 );//添加通讯录
//void Find(contact_p p);
//void Show(contact_p p);
//void Empty(contact_p p);
//void Sort();
//void Change();
