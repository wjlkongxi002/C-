#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;



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
}*/
//1.替换空格

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