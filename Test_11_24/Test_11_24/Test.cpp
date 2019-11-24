#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class CGoods
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(this->name, name);
		this->count = count;
		this->price = price;
	}
	void SetName(char *name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
public:
	char *GetName()
	{
		return name;//this可以不要
	}
	int GetCount()
	{
		return this->count;
	}
	float GetPrice()
	{
		return this->price;
	}
	float GetTotalPrice()
	{
		return (this->count) * (this->price);
	}
private:
	char name[10];
	int  count;
	float price;
	float total_price;
};

void main()
{
	CGoods g;
	g.RegisterGoods("水", 2, 10);
	cout << g.GetName() << endl;
	cout << g.GetCount() << endl;
	cout << g.GetPrice() << endl;
	cout << g.GetTotalPrice() << endl;
}











//void main()
//{
//	namespace N
//	{
//	}
//}

/*void main()
{
int a= 10;
char b= 'b';
double c = 12.34;
cout << a << endl;
cout << b << endl;
cout << c << endl;
int d = 20;
cout << d << endl;
}
*/