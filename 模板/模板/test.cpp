#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <vector>
using namespace std;




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


template <class T1,class T2>  //模板参数列表：声明类型
T2 Add(T1 left, T2 right)
{
	cout << typeid(left + right).name() << endl;
	cout << left + right << endl;

	return left + right;
}
int main()
{
	Add(1, 1.0);
}

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


/*

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



template <class T>  //模板参数列表：声明类型
T Add(T left, T right)
{
	cout << typeid(T).name() << " ";
	cout << left + right << endl;
	return left + right;
}

int main()
{
	Add(10, 20);
	Add(1, (int)2.3);//用户自己强转

	return 0;

}
*/

// 找出数组中重复的数字
/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

链接：https ://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		vector<int> v;
		v.resize(1000000);
		for (int i = 0; i<nums.size(); i++)
		{
			v[nums[i]]++;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (v[nums[i]]>1)
				return nums[i];
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 3, 1, 0, 2, 5, 3 };
	int a = s.findRepeatNumber(v);
	return 0;
}

*/