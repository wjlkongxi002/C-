#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;


//1.�滻�ո�

class Solution {
public:
	string replaceSpace(string s) {
		string s1;
		for (int i = 0; i < s.size(); i++)//��Ҫ������string��������±���ʺ�׷��
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