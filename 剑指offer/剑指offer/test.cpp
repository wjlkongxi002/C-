#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  ��ָ Offer 15. ��������1�ĸ���   https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
/*
��ʵ��һ������������һ��������������������Ʊ�ʾ�� 1 �ĸ�����
���磬�� 9 ��ʾ�ɶ������� 1001���� 2 λ�� 1����ˣ�������� 9����ú������ 2
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






// ��ָoffer 06 ��β��ͷ��ӡ����   https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
/*

����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

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


// ��ָ Offer 57. ��Ϊs����������  https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
/*
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {  //˫ָ��
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






//1.�滻�ո�  https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

/*

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


// 2. ��һ��ֻ����һ�ε��ַ�   https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/

/*
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
*/


// 3. �ַ����е�һ��Ψһ�ַ�  https://leetcode-cn.com/problems/first-unique-character-in-a-string/

/*
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
*/

//4.�ҳ��������ظ�������  https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

/*

//�������ķ�������������ÿ�����ֳ��ֵĸ�����¼������Ȼ��������������
// ���������д���1 �ģ��Ͱ������Ӱ�����ַ���

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
// ���򷨣��������ٱ����������������ͬ�ģ��ͷ��ظ�����
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
		v.resize(nums.size());  //resize()��������Ĵ�С��reserve()���������������
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

// ��ָ Offer 04. ��ά�����еĲ���
//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
//����������һ����ά�����һ���������ж��������Ƿ��и�������

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
