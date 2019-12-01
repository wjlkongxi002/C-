#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Int
{
	friend ostream&operator<<(ostream &out, const Int &x);
	friend iostream&operator<<(iostream &out,Int &x);
public:
	Int(int i = 0) :m_i(i)
	{}
	~Int()
	{}
public:
	Int operator+(const Int &x);
	Int operator-(const Int &x);
	Int operator*(const Int &x);
	Int operator/(const Int &x);
	Int operator%(const Int &x);
public:
	Int& operator+=(const Int &x);
	Int& operator-=(const Int &x);
	Int& operator*=(const Int &x);
	Int& operator/=(const Int &x);
	Int& operator%=(const Int &x);
public:
	Int& operator++();
	Int operator--();
private:
	int m_i;
};

ostream&operator<<(ostream &out, const Int &x)
{
	out << x.m_i;
	return out;
}
iostream&operator<<(iostream &in, Int &x)
{
	in << x.m_i;
	return in;
}
Int Int::operator+(const Int &x)
{
	Int tmp = m_i + x.m_i;
	return tmp;
}

void main()
{

	Int a=10;
	Int b=2;
    Int v = a + b;


	cout << v << endl;

}