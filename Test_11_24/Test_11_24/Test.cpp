#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 1 ��������const ��ô��

// 2 GetData() �� GetData()const �ܷ񹲴�

// 3 �������캯����const 

// 4 ��ֵ��� 
//operator=    ���������
//   Test& operator=(const Test &t)

//   void  operator=(Test t)

class Student
{
public:
	char name[10]; //��Ա����  ���ݳ�Ա
private:
	char sex[3];
	int age;
protected:
	int height;
	int weight;
};

void main()
{
Student s;  // ʵ���� ����
	//s.age = 10;
	strcpy(s.name, "�żٰ�");
}

/*
void main()
{
	int ar[5] = { 1, 2, 3, 4, 5 };
	int(&br)[5] = ar; //3

	int(*par)[5] = &ar;

	cout << sizeof(br) << endl;//20
	cout << sizeof(par) << endl;//4
}


/*
int& fun(const int &a, const int &b)
{
	int v = a + b;
	return v;
}
void main()
{
	int a = 10;
	int b = 20;

	int &value = fun(a, b);
	fun(100, 200);
	cout << value << endl;//��ʦ����Ϊɶд30

}


/*
void swap(int &a, int &b)//������
{
	int tmp = a;
	a = b;
	b = tmp;



int& fun(int a, int b, int &v)
{
	v = a + b;
	return v;
}

void fun1(int a, int b, int &v)
{
	v = a + b;
}

void main()
{
	int a = 10;
	int b = 20;
	int &ra = a;//����

	int *p = &a;//ָ��
	int *&q = p;

	int ar[5] = { 1, 2, 3, 4, 5 };
	int(&br)[5] = ar;//��������

	swap(a, b);

	int res;
	int &value = fun(a, b, res);

	fun1(100, 200, res);
}

/*void main()//ɶ��˼����
{
	int *p = (int*)malloc(sizeof(int)* 3);
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;

	free(p);
}


/*int fun(int a, int b, int &c)//��ɶ��
{
	c = a + b;
	return c;
}
void swap(int &a, int &b)//������
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
	int &ra = a;//����

	int *p = &a;//ָ��
	int *&q = p;
	*p = 20;

	int ar[5] = { 1, 2, 3, 4, 5 };
	int(&br)[5] = ar;//��������

	swap(a, b);
	fun(a, b, c);
}


/*int& Add(int a, int b)//����������ֵ
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
	//a = 12;���ܶԳ����ñ��������޸�
	const int &b = 10;
	double d = 12.34;
	//int &rd = d;�������rdΪd�����ã������������ܻ����d��ֵ����d��һ��������
	const int &rd = d;
	const int &d = 20;   
	printf("d = %d\n", d);


	int *p = (int*)&d;
	*p = 40;
	printf("d = %d\n", d);


}

void main()//����ֻ��һ��������û�� �����ռ䣬��������ʵ�干��ͬһ��ռ�
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