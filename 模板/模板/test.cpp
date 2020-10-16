#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//
template <class T>  //模板参数列表：声明类型
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
	cout << left + right << endl;
}

int main()
{
	Add(10, 20);
	Add<int>(1.0, 2);//显式

	return 0;
}