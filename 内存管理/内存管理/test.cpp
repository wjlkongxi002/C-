#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

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
