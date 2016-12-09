#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#define INIT_CONTACT_SIZE 64
#define INC_SIZE 32
#define FILE_NAME "fileBak.txt"

#pragma warning(disable:4996)

typedef struct person{
	char name[32];
	char sex;
	unsigned char age;
	char phone[16];
	char addr[128];
}person_t, *person_p, **person_pp;

typedef struct contact{
	int cap;
	int size;
	person_p contactList;
}contact_t, *contact_p, **contact_pp;

void initContact(contact_pp c);
void destroyContact(contact_p c);
void addContact(contact_p c, person_p p);
void delContact(contact_p c, const char *nameKey);
//void searchContact();
//void modContact();
void showContact(contact_p c);
void clearContact(contact_p c);
//void sortContact();

int fileLoad(contact_p c);
int fileStore(contact_p c);




#endif
#include "contact.h"

static void swap(person_p xp, person_p yp)
{
	person_t tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}
// 1->full, 0->not full
static int isContactFull(contact_p c)
{
	assert(c);

	return c->size >= c->cap ? 1 : 0;
}
//1->inc success, 0->failed 
static int incContact(contact_p c)
{
	assert(c);

	person_p new_c = realloc(c->contactList,\
		(c->cap + INC_SIZE)*sizeof(person_t));
	if ( NULL == new_c ){
		perror("realloc");
		return 0;
	}
	c->contactList = new_c;
	c->cap += INC_SIZE;

	printf("room is little, inc success!\n");
	return 1;
}

void initContact(contact_pp c)
{
	assert(c);

	*c = (contact_p)malloc(sizeof(contact_t));
	if (NULL == *c){
		perror("malloc");
		exit(1);
	}

	(*c)->contactList = (person_p)malloc(sizeof(person_t)*INIT_CONTACT_SIZE);
	if (NULL == (*c)->contactList){
		perror("malloc");
		exit(2);
	}

	(*c)->cap = INIT_CONTACT_SIZE;
	(*c)->size = 0;

	fileLoad(*c);
}

int fileLoad(contact_p c)
{
	assert(c);
	FILE *fp = fopen(FILE_NAME, "rb");
	if (NULL == fp){
		perror("fopen");
		return -2;
	}

	person_t p;
	while (1){
		fread(&p, sizeof(person_t), 1, fp);
		if (feof(fp)){//?
			break;
		}
		addContact(c, &p);
	}

	fclose(fp);
}

int fileStore(contact_p c)
{
	assert(c);

	FILE *fp = fopen(FILE_NAME, "wb");
	if ( NULL == fp ){
		perror("fopen");
		return -1;
	}

	int i = 0;
	for (; i < c->size; i++){
		fwrite(c->contactList+i, sizeof(person_t), 1, fp);
	}

	fclose(fp);
}

void destroyContact(contact_p c)
{
	assert(c);

	fileStore(c); 

	free(c->contactList);
	c->contactList = NULL;
	free(c);
	c = NULL;
}

void addContact(contact_p c, person_p p)
{
	assert(c);
	assert(p);

	if (!isContactFull(c) || incContact(c)){
		int pos = c->size;
		c->contactList[pos] = *p;
		c->size++;
	}
}

void showContact(contact_p c)
{
	assert(c);
	int i = 0;
	for (; i < c->size; i++){
		printf("%-16s | %-1c | %-3d | %-16s | %-32s\n", c->contactList[i].name,\
			c->contactList[i].sex ,c->contactList[i].age ,\
			c->contactList[i].phone ,c->contactList[i].addr);
	}
}

void clearContact(contact_p c)
{
	assert(c);
	c->size = 0;
}

void delContact(contact_p c, const char *nameKey)
{
	assert(c);
	assert(nameKey);
	int i = 0;
	for (; i < c->size; i ++){
		if (strcmp(c->contactList[i].name, nameKey) == 0){
			swap(c->contactList + i, c->contactList + c->size - 1);
			c->size--;
		}
	}
}
#include "contact.h"

static void usage()
{
	printf("Usage: Please Enter Right code[0-7]!\n");
}

static void myAdd(contact_p c)
{
	assert(c);
	person_t p;
	printf("Please Enter<name, sex, age, phone, addr> ");
	scanf("%s %c %d %s %s", p.name, &p.sex, &p.age, p.phone, p.addr);
	addContact(c, &p);
}

static void myDelete(contact_p c)
{
	char name[32];
	printf("Please Enter The name which you want to delete: ");
	scanf("%s", name);
	delContact(c, name);
}

int main()
{
	contact_p myContact = NULL;
	initContact(&myContact);
	volatile int done = 0;
	int s = -1;
	while (!done){
		s = -1;
		printf("######################################\n");
		printf("##1. add    ############# 2. delete ##\n");
		printf("##3. modify ############# 4. search ##\n");
		printf("##5. show   ############# 6. clear  ##\n");
		printf("##7. sort   ############# 0. exit   ##\n");
		printf("######################################\n");
		printf("Please Select<0~7>: ");
		scanf("%d", &s);
		switch (s){
		case 0:
			printf("bye~\n");
			done = 1;
			break;
		case 1:
			myAdd(myContact);
			break;
		case 2:
			myDelete(myContact);
			break;
		case 3:
			//Modify();
			break;
		case 4:
			//mySearch();
			break;
		case 5:
			showContact(myContact);
			break;
		case 6:
			clearContact(myContact);
			break;
		case 7:
			//mySort();
			break;
		default:
			usage();
			break;
		}
	}
	destroyContact(myContact);
	system("pause");
	return 0;
}
