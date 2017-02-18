#include<iostream>
using namespace std;
class Complex
{
public:
	Complex();
	Complex(int r,int i):
		real(r),
		image(i)
	{}
	Complex operator+(Complex&c2);
	Complex operator-(Complex&c2);
    Complex& operator=(const Complex& complex);
    //Complex operator+(const Complex& complex);
    //Complex operator-(const Complex& complex);
    Complex operator*(const Complex& complex);
    Complex operator/(const Complex& complex);

    Complex& operator+=(const Complex& c2);
	Complex& operator-=(const Complex& C2);
    Complex& operator*=(const Complex& c2);
    Complex& operator/=(const Complex& c2);

	friend bool operator >(const Complex& complex,const Complex& c2);
    friend bool operator >=(const Complex& complex,const Complex& c2);
    friend bool operator <(const Complex& complex,const Complex& c2);
    friend bool operator <=(const Complex& complex,const Complex& c2);
    friend bool operator ==(const Complex& complex,const Complex& c2);
    friend bool operator !=(const Complex& complex,const Complex& c2);

	friend ostream &operator<<(ostream &out,Complex &obj);

private:
	int real;
	int image;
};
Complex Complex::operator+(Complex&c2)
{
	Complex c;
	c.real=c2.real+real;
	c.image=c2.image+image;
	return c;
}
Complex Complex::operator-(Complex&c2)
{
	Complex c;
	c.real=real-c2.real;
	c.image=image-c2.image;
	return c;
}
Complex Complex::operator*(const Complex& c2)
 {
	 Complex c;
	 c.real=real*c2.real-image*image;
	 c.image=real*c2.image+image*c2.real;
	 return c;
 }
 Complex Complex::operator/(const Complex& c2)
 {
	 Complex c;
	 if (c2.image == 0)
	 {
		 c.real=real / c2.real;c.image=image / c2.real;
	 }
	 else
	 {
		 return (*this)*Complex(c2.real, -c2.image) / Complex(c2.real*c2.real + c2.image*c2.image, 0);
	 }
 }
 Complex &Complex::operator+=(const Complex& c2)
 {
	Complex c;
	c.real=c2.real+real;
	c.image=c2.image+image;
	return c;
 }
Complex &Complex::operator-=(const Complex&c2)
{
	Complex c;
	c.real=real-c2.real;
	c.image=image-c2.image;
	return c;
}
Complex &Complex::operator*=(const Complex& c2)
 {
	 Complex c;
	 c.real=real*c2.real-image*image;
	 c.image=real*c2.image+image*c2.real;
	 return c;
 }
 Complex &Complex::operator/=(const Complex& c2)
 {
	 Complex c;
	 if (c2.image == 0)
	 {
		 c.real=real / c2.real;c.image=image / c2.real;
	 }
	 else
	 {
		 return (*this)*Complex(c2.real, -c2.image) / Complex(c2.real*c2.real + c2.image*c2.image, 0);
	 }
 }
bool operator>(const Complex& c1,const Complex& c2)
{
	if(c1.real>=c2.real)
	{
		return 1;
	}
	else
		return 0;
}
bool operator<(const Complex& c1,const Complex& c2)
{
	if(c1.real<c2.real)
	{
		return 1;
	}
	else
		return 0;
}
bool operator >=(const Complex& c1,const Complex& c2)
{
		if(c1.real<=c2.real)
	{
		return 1;
	}
	else
		return 0;
}
bool operator <=(const Complex& c1,const Complex& c2)
{
		if(c1.real>=c2.real)
	{
		return 1;
	}
	else
		return 0;
}
bool operator ==(const Complex& c1,const Complex& c2)
{
		if(c1.real==c2.real)
	{
		return 1;
	}
	else
		return 0;
}
bool operator !=(const Complex& c1,const Complex& c2)
{
		if(c1.real!=c2.real)
	{
		return 1;
	}
	else
		return 0;
}
Complex&Complex::operator=(const Complex& complex)
{
	Complex c;
	real=complex.real;
	image=complex.image;
	return *this;

}
