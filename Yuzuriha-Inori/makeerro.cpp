#include<iostream>
#include<stdio.h>
jmp_buf mark;
void Funtest1()
{
	longjmp(mark,1);
}
void Funtest2()
{
	longjmp(mark,2);
}
//void Funtest3()
//{
//	longjmp(mark,3);
//}
int main()
{
	int istate = setjmp(mark);
	if(0==istate)
	{
		Funtest1();
		Funtest2();
		Funtest3();
	}
	else
	{
		switch (istate)
		{
		case 1:cout<<"Funtest1 Erro"<<endl;
		break;
		case 2:cout<<"Funtest2 Erro"<<endl;
		break;		
		case 3:cout<<"Funtest3 Erro"<<endl;
		}
		
	}
	cout<<"main End"<<endl;
	return 0;
}
