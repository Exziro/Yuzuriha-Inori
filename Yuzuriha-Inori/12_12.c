#include<stdio.h>
#include<windows.h>
union tag
{
	struct
	{
		char a;
		short b;
		char c;
	}half;
	short kk;
}number;
struct B
{
	char a;
	short b;
	char c;
	short d;

}half;
struct C
{
	struct
	{
		char a;
		short b;
		char c;
	}half;
	long kk;
};
