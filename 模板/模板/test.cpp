#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//
/*
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
*/

/*
template <class T1,class T2>  //模板参数列表：声明类型
T2 Add(T1 left, T2 right)
{
	cout << typeid(left + right).name() << endl;
	cout << left + right << endl;

	return left + right;
}
int main()
{
	Add(1, 1.1);
}
*/
//普通函数可以实现自动类型强转
/*
 double Add(int a,double b)
{
    int c= a + b;
	cout << c ;
	return c;
}
int main()
{
	Add(1, 2.3);  //  3  返回值类型和定义的类型值不一样？
}
*/


// 模板化各种类型的数组
template<class T>
void PrintArray(T array[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

int main()
{
	int array1[] = { 1, 2, 3, 4, 5 };
	PrintArray(array1, sizeof(array1) / sizeof(int));

	double array2[] = { 1.1, 2.2, 3.3 };
	PrintArray(array2, sizeof(array2) / sizeof(double));

	return 0;
}

