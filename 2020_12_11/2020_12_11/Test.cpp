#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <time.h>
using namespace std;

/*
//  ц╟ещеепР
int main()
{
	int a[10] = { 9, 5, 6, 4, 8, 2, 3, 7, 1, 0 };
	int startime, endtime;
	for (int i = 0;i< 10; i++)
	{
		int tmp = 0;
		for (int j = 0; j < 10-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	startime = clock();
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	endtime = clock();
	cout << "T=" << (double)(endtime - startime) / CLOCKS_PER_SEC;
	return 0;
}
*/

/*
struct Test
{
	Test(int) {}
	Test(){}
	void fun(){}
};

void main(void)
{
	Test a(1);
	a.fun();
	Test b();
	b.fun();
}
*/

//int main(void)
//{
//	const int a = 10;
//	int *p = (int *)(&a);
//	*p = 20;
//	cout << a << *p << endl;
//	return 0;
//}



//int swap_int(int *a, int *b){
//	*a = *a + *b;
//	*b = *a - *b;
//	*a = *a - *b;
//	return *a;
//}
//
//int main()
//{
//	int a = 2147483649;
//	int b = 2;
//	swap_int(&a, &b);
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}


class A
{
public:
	 virtual void fun1()
	{
		cout << "funA1" << endl;
	}
	virtual void fun2()
	{
		cout << "funA2" << endl;
	}
};

class B:public A
{
public:
	void fun1()
	{
		// A::fun1();
		cout << "funB1" << endl;
	}
	 void fun2()
	{
		cout << "funB2" << endl;
	}
};

int main()
{
	B b;
	A *pa;
	pa = &b;
	A*pb = new A;
	pa->fun1();
	pa->fun2();
	pb->fun1();
	pb->fun2();
	return 0;
}
