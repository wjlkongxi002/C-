#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

//1.�滻�ո�  https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

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
}
//1.�滻�ո�


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

*/

#if 0
// 2. ��һ��ֻ����һ�ε��ַ�   https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/


class Solution {
public:
	char firstUniqChar(string s) {
		if (s.empty())  //�пգ�
			return ' ';
		int count[256] = { 0 };
		for (int i = 0; i < s.size(); i++)//����  ����
		{
			count[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++)//Ѱ��ֻ����һ�ε�
		{
			if (count[s[i]] == 1)
				return s[i];
		}
		return ' ';//�������껹û�з��أ���˵��û��ֻ����һ�ε��ַ����ͷ��ء� ��
	}
};

#endif

// 3. �ַ����е�һ��Ψһ�ַ�  https://leetcode-cn.com/problems/first-unique-character-in-a-string/

class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };//����һ�����飬��С256����ӦASCI���ʾ������±�
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
