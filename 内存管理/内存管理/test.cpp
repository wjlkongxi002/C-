#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include<vld.h>  //����ڴ�й©
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
	Test* ptr1 = new Test;  // ���뵥��Test���͵Ķ���
	Test* ptr2 = new Test();  // ���뵥��Test���͵Ķ���
	Test* ptr3 = new Test(20);  //���뵥��Test���͵Ķ�����20��ʼ��
	
	delete ptr1;
	delete ptr2;
	delete ptr3;
	
	return 0;
}
*/

void MemoryLeaks()
{
	// 1.�ڴ������������ͷ�
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.�쳣��ȫ����
	//int* p3 = new int[10];
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
	//delete[] p3;
}

int main()
{
	MemoryLeaks();

	return 0;
}