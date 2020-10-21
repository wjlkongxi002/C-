#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include<vld.h>  //检测内存泄漏
/*
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{
	Test* ptr1 = new Test;  // 申请单个Test类型的对象
	Test* ptr2 = new Test();  // 申请单个Test类型的对象
	Test* ptr3 = new Test(20);  //申请单个Test类型的对象，用20初始化
	
	delete ptr1;
	delete ptr2;
	delete ptr3;
	
	return 0;
}
*/

void MemoryLeaks()
{
	// 1.内存申请了忘记释放
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.异常安全问题
	//int* p3 = new int[10];
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
	//delete[] p3;
}

int main()
{
	MemoryLeaks();

	return 0;
}