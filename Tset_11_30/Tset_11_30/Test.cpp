#define _CRT_SECURE_NO_WARNINGS 1
// 1 常方法的const 怎么了
// 2 GetData() 与 GetData()const 能否共存
// 3 拷贝构造函数的const 
// 4 赋值语句 
//   Test& operator=(const Test &t)
//   void  operator=(Test t)

#include <iostream>
using namespace std;


class Test
{

public:
	Test(int d=0):m_data(d)        // 参数列表  初始化
	{
		//m_data = 0;  //赋值
	}
public:
	void Show()const
	{
		cout << m_data << endl;
	}
private:
	//int m_data=0;   //初始化  满足C++11
	int m_data;

};

void main()
{
	Test t;
	t.Show();
}