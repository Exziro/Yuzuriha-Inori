int recursion(int a)
{
	int b,sum=0;
	b=a%10;
	if(a/10==0)
	{
		return a;
	}
	else
	{
		sum=b+recursion(a/10);
	}
	return sum;
}

 
int main()
{
	int a=6639;
	printf("%d",recursion(a));
	system("pause");
	return 0;
}