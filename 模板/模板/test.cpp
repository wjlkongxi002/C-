#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//
template <class T>  //ģ������б���������
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
	cout << left + right << endl;
}

int main()
{
	Add(10, 20);
	Add<int>(1.0, 2);//��ʽ

	return 0;
}