#define _CRT_SECURE_NO_WARNINGS 1

///////////////////////////////
//1
//ת����Сд�ַ�
//ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����
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
//��ת����
//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
//https://leetcode-cn.com/problems/rotate-array/
/*
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();// ��k��ֵ��Χ������0 ~ nums.size()
		// reverse ������Χ [first, last) ������ҿ���
		reverse(&nums[0], &nums[nums.size()]);
		reverse(&nums[0], &nums[k]);
		reverse(&nums[k], &nums[nums.size()]);
	}
};

*/

