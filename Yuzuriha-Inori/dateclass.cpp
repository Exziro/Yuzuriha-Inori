#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year,int month,int day);
	Date& operator=(const Date& d);
	int monthday(int year,int month);
	Date operator-(int days);  
    int operator-(const Date& d);  
    Date& operator++();  
    Date operator++(int);  
    bool operator>(const Date& d);  
    bool operator<(const Date& d);  
    bool operator==(const Date& d);  
    bool operator!=(const Date& d); 
private:
	int _year;
	int _month;
	int _day;
};
Date::Date(int year,int month,int day)
{
	if()
	_year=year;
	_month=month;
	_day=day;

}
Date &Date::operator=(const Date&d)
{
	if(this!=&d)
	{
		_year=d._year;
		_day=d._day;
		_month=d._month;
		
	}
	else
		return *this;
}
