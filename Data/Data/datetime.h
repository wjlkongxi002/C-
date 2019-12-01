#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	//Date& operator=(const Date& d);
	//Date operator+(int days); 
	//Date operator-(int days);
	//int operator-(const Date& d);
	//Date& operator++();
	//Date operator++(int);
	//Date& operator--();
	//Date operator--(int);
	//bool operator>(const Date& d)const;
	//bool operator>=(const Date& d)const;
	//bool operator<(const Date& d)const;
	//bool operator<=(const Date& d)const;
	//bool operator==(const Date& d)const;
	//bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};