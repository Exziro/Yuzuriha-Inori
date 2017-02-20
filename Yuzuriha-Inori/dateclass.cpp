#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& _cout,const Date& d);  
    friend istream& operator>>(istream& _cin, Date& d);  
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
    _year=year;
	_month=month;
	_day=day;
	if((day<0)&&(month<0)&&(month>13)&&(day>31)&&(day<monthday(month,year)))
	{
		cout<<"you number is wrong"<<endl;
	}
	else 
		cout<<"year:"<<year<<"month"<<month<<"day"<<day<<endl;

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
int monthday(int year,int month)
{
	int day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	if((0==year/400==0)&&((0==year/4)||(0==year/100))&&(2==month))
	{
		return day[2]=29;
	}
	else
		return day[month];
}
Date Date::operator-(int days)
{
	    if(days<0)  
    {  
        days = 0-days;  
    }  
    Date temp(*this);  
    temp._day-=days;  
    while(temp._day<0)  
    {  
        if(temp._month == 1)  
        {  
            temp._month = 12;  
            temp._day += 31;  
        }  
        else  
        {  
            --temp._month;  
			temp._day += monthday(_year,temp._month);  
        }  
          
    }  
        return temp;  
}  
int Date:: operator-(const Date& d)
{
	Date max=(*this);
	Date min=d;
	if(max._day<min._day)
	{
		swap(max._day,min._day);
	}
	return (max._day-min._day);
}
Date& Date ::operator++()//前置
{
	int day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	if(day[_month]<_day)
		++_day;
	else
		{
			++_month;
			_day=1;
	}
	return (*this);
}
Date Date ::operator++(int)//日期前置++和后置++的关系
{
	    Date temp(*this);  
    temp._day = temp._day+1;  
    //temp++;  
    return temp;  
}
bool Date::operator>(const Date& d)
{
	if(_year<d._year)
	{
		return 0;
	}
	else if(_year=d._year)
	{
		if(_month<d._month)
			return 0;
		if(_month=d._month)
			if(_day<=d._day)
			{return 0;}
			else
				return 1;
		return 1;
	}
	return 1;
}
bool Date::operator<(const Date& d)
{
	if(_year>d._year)
	{
		return 0;
	}
	else if(_year=d._year)
	{
		if(_month>d._month)
			return 0;
		if(_month=d._month)
			if(_day>=d._day)
			{return 0;}
			else
				return 1;
		return 1;
	}
	return 1;
}
bool Date::operator==(const Date& d)
{
	if((_day==d._day)&&(_month==d._month)&&(_year==d._year))
		return 1;
	else 
		return 0;
}
bool Date::operator!=(const Date& d)
{
	if((_day==d._day)&&(_month==d._month)&&(_year==d._year))
		return 0;
	else 
		return 1;
}
ostream& operator<<(ostream& _cout,const Date& d)  
{  
    _cout<<d._year<<" "<<d._month<<" "<<d._day;  
    return _cout;  
}  
istream& operator>>(istream& _cin,Date& d)  
{  
    _cin>>d._year>>d._month>>d._day;  
    return _cin;  
}  