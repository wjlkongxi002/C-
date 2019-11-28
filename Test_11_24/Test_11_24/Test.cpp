#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int fun(int a, int b, int &c)
{
	c = a + b;
	return c;
}
void swap(int &a, int &b)//做参数
{
	int tmp = a;
	a = b;
	b = tmp;
}
void main()
{
	int a = 10;
	int b = 20;
	int c;
	int &ra = a;//引用

	int *p = &a;//指针
	int *&q = p;
	*p = 20;

	int ar[5] = { 1, 2, 3, 4, 5 };
	int(&br)[5] = ar;//数组引用

	swap(a, b);
	fun(a, b, c);
}


/*int& Add(int a, int b)//引用做返回值
{
	int c = a + b;
	return c;
}
	int main()
	{
		int &ret = Add(1, 2);
		Add(3, 4);
		cout << "Add(1,2)=" << ret << endl;//Add(1,2)=7
		return 0;
	}


/*
void main()
{
	const int &a = 10;
	//a = 12;不能对常引用变量进行修改
	const int &b = 10;
	double d = 12.34;
	//int &rd = d;编译错误，rd为d的引用（别名），可能会更改d的值（而d是一个常量）
	const int &rd = d;
	const int &d = 20;   
	printf("d = %d\n", d);


	int *p = (int*)&d;
	*p = 40;
	printf("d = %d\n", d);


}

void main()//引用只是一个别名，没有 独立空间，和其引用实体共用同一块空间
{
	int a = 10;
	int &ra = a;
	int &rb = a;
	double b = 12.34;
	
	a = 100;
	cout << a << ra << rb <<rc<< endl;
}


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


void main()
{
	namespace N
	{
	}
}

void main()
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