#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  剑指 Offer 15. 二进制中1的个数   https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
/*
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2
*/

/*
class Solution {
public:
	int hammingWeight(uint32_t n) {
		uint32_t count = 0;
		while (n)
		{
			if ((n & 1) == 1)
			{
				count++;
			}
			n >>= 1;
		}
		cout << count << endl;
		return count;
	}
};

int main()
{
	Solution s;
	s.hammingWeight(5);
	return 0;
}
*/






// 剑指offer 06 从尾到头打印链表   https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
/*

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> v;
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		reverse(v.begin(), v.end());
		return v;
	}
};

*/


// 剑指 Offer 57. 和为s的两个数字  https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
/*
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {  //双指针
		int i = 0, j = nums.size() - 1;
		while (i<j)
		{
			int s = nums[i] + nums[j];
			if (s == target)
				return{ nums[i], nums[j] };
			if (s>target)
				j--;
			if (s<target)
				i++;
		}
		return{};
	}
};

*/






//1.替换空格  https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

/*

class Solution {
public:
	string replaceSpace(string s) {
		string s1;
		for (int i = 0; i < s.size(); i++)//主要是利用string类的特性下标访问和追加
		{
			if (s[i] == ' ')
				s1 += "%20";
			else
				s1 += s[i];
		}
		return s1;
	}
};

int main()
{
	string replaceSpace("wang jia");
}


class Solution {
public:
	void replaceSpace(char *str, int length) {
		string str1;
		for (int i = 0; i <= length; i++)
		{
			if (str[i] == ' ')
				str1 += "%20";
			else
				str1 += str[i];
		}
		strcpy(str, str1.c_str());
	}
};


class Solution {
public:
	void replaceSpace(char *str, int length) {   //将char* 类型转成string类型，比较好做
		string str1;
		for (int i = 0; i <= length; i++)//将str循环写入str1
		{
			if (str[i] == ' ')
				str1 += "%20";
			else
				str1 += str[i];
		}
		str = (char*)str1.c_str();
		cout << str << endl;
	}
};

int main()
{
	Solution s;
	s.replaceSpace("wang jia",9);
	return 0;
}

*/


// 2. 第一个只出现一次的字符   https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/

/*
class Solution {
public:
	char firstUniqChar(string s) {
		if (s.empty())  //判空，
			return ' ';
		int count[256] = { 0 };
		for (int i = 0; i < s.size(); i++)//遍历  计数
		{
			count[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++)//寻找只出现一次的
		{
			if (count[s[i]] == 1)
				return s[i];
		}
		return ' ';//上面走完还没有返回，就说明没有只出现一次的字符，就返回‘ ’
	}
};
*/


// 3. 字符串中第一个唯一字符  https://leetcode-cn.com/problems/first-unique-character-in-a-string/

/*
class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };//定义一个数组，大小256，对应ASCI码表示数组的下标
		for (int i = 0; i<s.size(); i++)
		{
			count[s[i]]++;
		}
		for (int i = 0; i<s.size(); i++)
		{
			if (count[s[i]] == 1)
				return i;
		}
		return -1;
	}
};
*/

//4.找出数组中重复的数字  https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

/*

//计数器的方法，把数组中每个数字出现的个数记录下来，然后便利这个计数器
// 当计数器有大于1 的，就把这个随影的数字返回

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int count[100000] = { 0 };
		for (int i = 0; i<nums.size(); i++)
		{
			count[nums[i]]++;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (count[nums[i]]>1)
				return nums[i];
		}
		return -1;
	}
};
*/


/* 
// 排序法，先排序，再遍历，如果有两个相同的，就返回该数字
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		vector<int> v(nums);
		vector<int>::iterator it = nums.begin();
		sort(nums.begin(), nums.end());
		while (it != v.end())
		{
			if (*it == *(it + 1))
				return *it;
			++it;

		}

		return -1;
	}
};
*/

/*
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		vector<int> v;
		v.resize(nums.size());  //resize()重置数组的大小，reserve()是扩充数组的容量
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

// 剑指 Offer 04. 二维数组中的查找
//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，
//输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

/*
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		cout << n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (matrix[i][j] == target)
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > v = { { 1, 4, 7, 11, 15 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } };
	s.findNumberIn2DArray(v,5);
	
	return 0;
}
*/
