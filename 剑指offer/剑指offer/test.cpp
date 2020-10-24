#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

//1.替换空格  https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

/*
Solution {
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
//1.替换空格


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

#if 0
// 2. 第一个只出现一次的字符   https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/


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

#endif

// 3. 字符串中第一个唯一字符  https://leetcode-cn.com/problems/first-unique-character-in-a-string/

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
