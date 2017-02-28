#include<iostream>
using namespace std;
class A
{
public:
	A()
	{

		cout<<"establish:A()"<<endl;
	}
	~A()
   {
	   cout<<"des A()"<<endl;
	}
	int _a;
};
class B:virtual  public A
{
	public:
	B()
	{

		cout<<"establish:B()"<<endl;
	}
	~B()
   {
	   cout<<"des B()"<<endl;
	}
	int _b;
};
class C:virtual public A
{
	public:
	C()
	{

		cout<<"establish:C()"<<endl;
	}
	~C()
   {
	   cout<<"des C()"<<endl;
	}
	int _c;
};
class D:public C,public B
{
	public:
	D()
	{

		cout<<"establish:D()"<<endl;
	}
	~D()
   {
	   cout<<"des D()"<<endl;
	}
	int _d;
};
int main()
{
	D d;
	d._a=1;
	d._b=2;
	d._c=3;
	d._d=4;
	//cout<<d._a<<endl;
	//cout<<sizeof(d)<<endl;
	system("pause");
	return 0;
}