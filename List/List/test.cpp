#define _CRT_SECURE_NO_WARNINGS 1

#include <list>
#include <iostream>
#include <vector>
using namespace std;

void Test1()
{
	list<int> L1;
	list<int> L2(10, 5);
	list<int> L3{ 1, 2, 3, 4, 5 };
	
	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> L4(v.begin(), v.end());
	list<int>::iterator it = L4.begin();
	while (it != L4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int> L5(L3);
	auto rit = L5.rbegin();
	while (rit != L5.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> L6 = L5;
	for (auto e : L6)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test2()
{
	list<int> T{ 1, 2, 3, 4 };
	cout << T.front() << endl;
	cout << T.back() << endl;
	T.push_back(5);
	T.push_front(0);
	cout << T.front() << endl;
	cout << T.back() << endl;

	T.pop_front();
	T.pop_back();

	T.insert(find(T.begin(), T.end(), 2), 3);
	T.erase(T.begin());//  位置
	T.erase(T.begin(), T.end());

	T.resize(10, 5);
	T.resize(5, 0);
	T.resize(0);
	T.resize(5, 0);
	T.resize(10, 5);
}

void Test3()
{
	list<int> L1{ 1, 2, 3, 4, 5 };
	list<int> L2{ 6, 7, 8, 9, 0 };
	
	L1.swap(L2);
	//L1.clear();
	//向容器分配新内容，在调用之前删除容器对象
    //中包含的所有元素，并将它们替换为参数指定的元素:
	L1.assign(L2.begin(), L2.end());
	L1.assign(10, 0);

}

void Test4()
{
	list<int> L1{ 1, 4, 6, 2, 3 };
	list<int> L2{ 2, 5, 3, 2, 9, 7, 9 };
	// L1.remove(4);
	L1.sort();
	L2.sort();
	L1.merge(L2);  //  合并  先排序，再合并
	for (auto e : L1)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int> L{ 1, 1, 3, 5, 2, 4, 6, 5 ,6};
	L.sort();
	L.unique(); //  去重，删除相邻的重复元素，先排序
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}
bool Greater(int left, int right)
{
	return left > right;
}
bool Less(int left, int right)
{
	return left < right;
}
bool IsEven(int data)
{
	return 0 == data % 2;
}
void Test5()
{
	list<int> L{ 1, 1, 3, 5, 2, 4, 6, 5, 6 };

	L.sort(Greater);
	L.sort(Less);
	L.remove_if(IsEven);
	//L.remove_if(Is);

}

int main()
{
	// Test1();
	// Test2();
    // Test3();
	// Test4();
	Test5();
	return 0;
}



