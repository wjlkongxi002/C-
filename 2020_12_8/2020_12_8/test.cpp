#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
using namespace std;
/*
#include <iostream>
using namespace std;
class A
{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B : public A
{
public: 
	virtual void print()
    {
			cout << "B::print()" << "\n";
     }
};

class C :public A
{
public: 
	virtual void print()
	{
		cout << "C::print()" << "\n";
	}
};
void print(A a)
{
	a.print();
}
int main()
{
	A a, *aa, *ab, *ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
	return 0;
}

*/
/*

#include<iostream>
using namespace std;
class B
{
public:
	B()
	{
		cout << "default constructor" << " ";
	}

	~B()
	{
		cout << "destructed" << " ";
	} 

	B(int i) : data(i)
	{
		cout << "constructed by parameter" << data << " ";
	}
private : int data;
};
B Play(B b)
{
	return b;
} 

int main(int argc, char *argv[])
{
	B temp = Play(5);
	return 0;
}
*/

/*
int main()
{
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(unsigned int) << endl;
	int *p;
	cout << sizeof(p) << endl;

	return 0;
}
*/

/*
class A
{
public:
	A(int n)
	{
		num = n;
	}

private:
	int num;
};
int main()
{
	A a = 10;
	return 0;
}
*/

//#include <stdio.h>
//
//#define N 9
//int x[N];
//
//void dump() {
//	int i = 0;
//	for (i = 0; i < N; i++) {
//		printf("%d", x[i]);
//	} 
//	printf("\n");
//} 
//void swap(int a, int b) {
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//} 
//void run(int n) {
//	int i;
//	int count=0;
//	if (N - 1 == n) {
//		dump();
//		count++;
//		return;
//	} 
//	for(i = n; i < N; i++) {
//			swap(n, i);
//			run(n + 1);
//			swap(n, i);
//		}
//}
//int main() {
//	int i;
//	int count = 0;
//	for (i = 0; i < N; i++) {
//		x[i] = i + 1;
//	} 
//	run(0);
//	printf("* Total: %d\n", count);
//}

class PAT
{
public:
	PAT()
	{
		cout << "wangjialong" << endl;
	}
};
int main()
{
	//const int &ra;
	//int *a;
	PAT pat[3];
	PAT(*ab)[3] = &pat;// 指向数组的指针
	//extern const int a[256];
	return 0;
}