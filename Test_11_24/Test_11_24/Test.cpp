#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
	int main()
	{
		int &ret = Add(1, 2);
		Add(3, 4);
		cout << "Add(1,2)=" << ret << endl;
		return 0;
	}


/*
void main()
{
	//const int &a = 10;
	////a = 12;���ܶԳ����ñ��������޸�
	//const int &b = 10;
	//double d = 12.34;
	////int &rd = d;�������rdΪd�����ã������������ܻ����d��ֵ����d��һ��������
	//const int &rd = d;
	const int &d = 20;   
	printf("d = %d\n", d);


	int *p = (int*)&d;
	*p = 40;
	printf("d = %d\n", d);


}

void main()
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
		return name;//this���Բ�Ҫ
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
	g.RegisterGoods("ˮ", 2, 10);
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