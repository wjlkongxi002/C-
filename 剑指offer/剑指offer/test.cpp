#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;



/*
Solution {
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
}*/
//1.�滻�ո�

class Solution {
public:
	void replaceSpace(char *str, int length) {   //��char* ����ת��string���ͣ��ȽϺ���
		string str1;
		for (int i = 0; i <= length; i++)//��strѭ��д��str1
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