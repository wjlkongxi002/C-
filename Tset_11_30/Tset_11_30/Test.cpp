#define _CRT_SECURE_NO_WARNINGS 1
// 1 ��������const ��ô��
// 2 GetData() �� GetData()const �ܷ񹲴�
// 3 �������캯����const 
// 4 ��ֵ��� 
//   Test& operator=(const Test &t)
//   void  operator=(Test t)

#include <iostream>
using namespace std;


class Test
{

public:
	Test(int d=0):m_data(d)        // �����б�  ��ʼ��
	{
		//m_data = 0;  //��ֵ
	}
public:
	void Show()const
	{
		cout << m_data << endl;
	}
private:
	//int m_data=0;   //��ʼ��  ����C++11
	int m_data;

};

void main()
{
	Test t;
	t.Show();
}