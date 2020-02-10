#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//namespace N
//{
//	int a=10;
//	double b = 3.14;
//	char c = 'asrf';
//
//}
//
//using N::b;
//int main()
//{
//	//printf("%d\n", N::a);
//	//printf("%f", b);
//	int a;
//	double b;
//	char c;
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a<<endl;
//	cout << b   << "     "<<  c << endl;
//
//	cout << "hello bit??" << endl;
//	return 0;
//}
/*
int TestFunc(int a, int b=10, int c = 30);

 int TestFunc(int a , int b , int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}//全缺省参数


short TestFunc(double a, int b, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}//无法重载只按返回类型区分的函数，必须是缺省参数的个数
 //类型，顺序不同
int main()
{
	TestFunc(100,200,300);
	TestFunc(100, 200, 300);
	return 0;
}
*/
/*
int Add(int left, int right)
{
	cout << right + left << endl;
	return 0;
}
double Add(double left, double right)
{
	cout << right + left << endl;
	return 0;
}
*/
//void Add (int a = 10)
//{
//	cout << "void Add(int)" << endl;
//}
//void Add(int a=20)
//{
//	cout << "void Add(int)" << endl;
//}//两个函数不能重载
//int main()
//{
//	Add(1);
//	return 0;
//}



//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====定义引用类型
//	int& rb =a;
//	printf("%d\n", a);
//	printf("%d\n", ra);
//	printf("%d\n", rb);
//}


void TestConstRef()
{
	const int a = 10;
	//int& ra = a; // 该语句编译时会出错，a为常量
	const int& ra = a;
	// int& b = 10; // 该语句编译时会出错，b为常量
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // 该语句编译时会出错，类型不同
	const int& rd = d;
	printf("%d %d %d %.2f %d", a, ra, b, d, rd);
}
int main()
{
	//TestRef();
	TestConstRef();
	return 0;
}