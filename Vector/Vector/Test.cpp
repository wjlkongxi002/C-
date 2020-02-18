#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;
/*
void main()
{
	vector<int> v;
	v.reserve(100);
	for (int i = 0; i<100; ++i)
	{
		cout << "capacity = " << v.capacity() << endl;
		v.push_back(i);
	}
}

*/

void Print(vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;
}

void main()
{
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v(ar, ar + 10);
	//cout << "size = " << v.size() << endl;
	//cout << "capacity = " << v.capacity() << endl;
	Print(v);
	v.resize(6);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	Print(v);


}
/*
void main()
{

	int ar[3] = { 1, 2, 3 };
	vector<int> v(ar, ar + 3);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	Print(v);
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(100);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(50);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	Print(v);
}

/*
void main()
{
	vector<int> v;
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	v.push_back(1);
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;

	v.push_back(2);
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";
	cout << endl;

	v.push_back(20);
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";
	cout << endl;
}

/*
void main()
{
	//vector的使用

	//[]  operator[]重载[]
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v4(ar, ar + 10);
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;

	//at() 输出，会检测下标
	for (int i = 0; i < v4.size(); i++)
		cout << v4.at(i) << " ";
	cout << endl;

	//利用迭代器iterator
	vector<int>::iterator it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//反向迭代器
	vector<int>::reverse_iterator rit = v4.rbegin();
	while (rit != v4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout<<endl;

}
/*
void main()
{
	//默认构造
	vector<int> v1;
	//构造并初始化n个val值
	vector<int> v2(10,1);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	
	//拷贝构造
	vector<int> v3(v2);
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	//以数组形式构造
	//vector( value_type *first, value_type *last);
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v4(ar, ar + 10);
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;

	//vector (InputIterator first, InputIterator last);
	vector<int> v5(v4.begin(),v4.end());
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;
}
	*/
