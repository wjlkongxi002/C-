#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;


//1.替换空格

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