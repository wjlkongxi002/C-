#define _CRT_SECURE_NO_WARNINGS 1

///////////////////////////////
//1
//转换成小写字符
//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
//https://leetcode-cn.com/problems/to-lower-case/submissions/
/*
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string toLowerCase(string str) {
		string s;
		auto it = str.begin();
		while (it != str.end())
		{
			if (*it >= 'A' && *it <= 'Z')
			{
				*it += 32;
			}
			s += *it;
			it++;
		}
		cout << s << endl;
		return s;
	}
};
int main()
{
	Solution S;
	S.toLowerCase("HellOKK");
	return 0;
}
///////////
class Solution {
public:
	string toLowerCase(string str) {
		string s;

		for (int i = 0; i <= str.size(); ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
			s += str[i];
		}
		return s;
	}
};
*/

/////////////////////////////
//2
//旋转数组
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//https://leetcode-cn.com/problems/rotate-array/
/*
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();// 让k的值范围保持在0 ~ nums.size()
		// reverse 参数范围 [first, last) ，左闭右开，
		reverse(&nums[0], &nums[nums.size()]);
		reverse(&nums[0], &nums[k]);
		reverse(&nums[k], &nums[nums.size()]);
	}
};

*/

