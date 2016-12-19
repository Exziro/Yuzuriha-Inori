#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include"addressbook.h"
#define _size 1000
int addd(contact_p p)
{
	person_t pp;
	assert(p);

	printf("please enter some message:like name,sex,age,phone,address");
	scanf("%s%c%d%s%s",pp.name,&pp.sex,&pp.age,&pp.phone,&pp.address);
    return Add(p,pp);
}
int main()
{
	int n;
	contact_p mycontact=NULL;
	initcontact(&mycontact);
	menue();
		printf("please change:");
		scanf("%d",&n);
		switch (n)
		{
		case 1:addd(mycontact);break;
		//case 2:Find();break;
		//case 3:Change();break;
		//case 4:Show();break;
		//case 5:Empty();break;
		//case 6:Sort();break;
		case 0:exit;
		default: printf("erro:please try again");
			break;
		}




		system("pause");
		return 0;
	}
