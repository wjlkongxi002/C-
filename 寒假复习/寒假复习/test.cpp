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
}//ȫȱʡ����


short TestFunc(double a, int b, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}//�޷�����ֻ�������������ֵĺ�����������ȱʡ�����ĸ���
 //���ͣ�˳��ͬ
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
//}//����������������
//int main()
//{
//	Add(1);
//	return 0;
//}



//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====������������
//	int& rb =a;
//	printf("%d\n", a);
//	printf("%d\n", ra);
//	printf("%d\n", rb);
//}


void TestConstRef()
{
	const int a = 10;
	//int& ra = a; // ��������ʱ�����aΪ����
	const int& ra = a;
	// int& b = 10; // ��������ʱ�����bΪ����
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
	const int& rd = d;
	printf("%d %d %d %.2f %d", a, ra, b, d, rd);
}
int main()
{
	//TestRef();
	TestConstRef();
	return 0;
}