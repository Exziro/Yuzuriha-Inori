//#include<iostream>
//using namespace std;
//class Base1 {
//
//public:
//
//            virtual void f() { cout << "Base1::f" << endl; }
//
//            virtual void g() { cout << "Base1::g" << endl; }
//
//            virtual void h() { cout << "Base1::h" << endl; }
//
// 
//
//};
//
// 
//
//class Base2 {
//
//public:
//
//            virtual void f() { cout << "Base2::f" << endl; }
//
//            virtual void g() { cout << "Base2::g" << endl; }
//
//            virtual void h() { cout << "Base2::h" << endl; }
//
//};
//
// 
//
//class Base3 {
//
//public:
//
//            virtual void f() { cout << "Base3::f" << endl; }
//
//            virtual void g() { cout << "Base3::g" << endl; }
//
//            virtual void h() { cout << "Base3::h" << endl; }
//
//};
//
// 
//
// 
//
//class Derive : public Base1, public Base2, public Base3 {
//
//public:
//
//            virtual void f() { cout << "Derive::f" << endl; }
//
//            virtual void g1() { cout << "Derive::g1" << endl; }
//			
//};
//void f(Base1&b)
//{
//	b.f();
//}
//
// 
//
//typedef void(*Fun)(void);
//
// 
//
//int main()
//
//{
//
//	Derive d;
//	Base1 b1;
//	Base2 b2;
//	Base3 b3;
//	f(d);
//	f(b1);
//	system("pause");
//
//            //Fun pFun = NULL;
//
// 
//
//            //Derive d;
//
//            //int** pVtab = (int**)&d;
//
// 
//
//            ////Base1's vtable
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);
//
//            //pFun = (Fun)pVtab[0][0];
//
//            //pFun();
//
// 
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);
//
//            //pFun = (Fun)pVtab[0][1];
//
//            //pFun();
//
// 
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);
//
//            //pFun = (Fun)pVtab[0][2];
//
//            //pFun();
//
// 
//
//            ////Derive's vtable
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);
//
//            //pFun = (Fun)pVtab[0][3];
//
//            //pFun();
//
// 
//
//            ////The tail of the vtable
//
//            //pFun = (Fun)pVtab[0][4];
//
//            //cout<<pFun<<endl;
//
// 
//
// 
//
//            ////Base2's vtable
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
//
//            //pFun = (Fun)pVtab[1][0];
//
//            //pFun();
//
// 
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
//
//            //pFun = (Fun)pVtab[1][1];
//
//            //pFun();
//
// 
//
//            //pFun = (Fun)pVtab[1][2];
//
//            //pFun();
//
// 
//
//            ////The tail of the vtable
//
//            //pFun = (Fun)pVtab[1][3];
//
//            //cout<<pFun<<endl;
//
// 
//
// 
//
// 
//
//            ////Base3's vtable
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
//
//            //pFun = (Fun)pVtab[2][0];
//
//            //pFun();
//
// 
//
//            ////pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
//
//            //pFun = (Fun)pVtab[2][1];
//
//            //pFun();
//
// 
//
//            //pFun = (Fun)pVtab[2][2];
//
//            //pFun();
//
// 
//
//            ////The tail of the vtable
//
//            //pFun = (Fun)pVtab[2][3];
//
//            //cout<<pFun<<endl;
//
// 
//
//            return 0;
//
//}
#include<iostream>
using namespace std;
class A {

public:

            virtual void f() { cout << "A::f" << endl; }
			int a;
            //virtual void g1() { cout << "A::g" << endl; }
           // virtual void h() { cout << "A::h" << endl; }
 

};
class Base1:virtual public A
{

public:

            virtual void f() { cout << "Base1::f" << endl; }
			int a;
            virtual void g1() { cout << "Base1::g" << endl; }
            virtual void h() { cout << "Base1::h" << endl; }
 

};
class Base2:virtual public A 
{

public:

            virtual void f() { cout << "Base2::f" << endl; }
			int a;
            virtual void g1() { cout << "Base2::g" << endl; }
            virtual void h() { cout << "Base2::h" << endl; }
 

};
class Derive : public Base1,public Base2
{
public:

             void f() { cout << "Derive::f" << endl; }
			 void g1() { cout << "Derive::g" << endl; }
             //void h() { cout << "Derive::h" << endl; }
			 int b;
};

typedef void(*Fun)(void);
int main()

{
	Base1 b1;
	b1.a=1;
	Derive D;
	D.b=2;

        
 system("pause");
           return 0;

}