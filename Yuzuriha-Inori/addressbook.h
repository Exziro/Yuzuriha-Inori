#include<stdio.h>
#include<windows.h>
typedef struct person
{
	char name[256];
	char sex;
	unsigned char age;
	char phone[16];
	char addre[256];
}person_t,*person_p,**person_pp;
typedef struct contact 
{
	int cap;
	int size;
	person_p contactlist;
}contact_t,*contact_p,**contact_pp;

void menue();
void Add();
void Find();
void Show();
void Empty();
void Sort();
void Change();
