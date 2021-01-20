#define _CRT_SECURE_NO_WARNINGS 1




//https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// 汽水瓶
/*
#include <iostream>
using namespace std;
int count(int num)
{
	int countbottle = 0;
	while (num > 1)
	{
		//空瓶换的饮料
		int bottle = num / 3;
		//剩余空瓶
		int ret = num % 3;
		countbottle = countbottle + bottle;
		num = bottle + ret;
		if (num == 2)
		{
			++countbottle;
			break;
		}
	}
	return countbottle;
}
int main()
{
	int number;
	while (cin >> number)
	{
		if (number == 0)
			return 0;
		cout << count(number) << endl;
	}
	return 0;
}

*/


//https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。

//注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int max = 0;

		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		for (int i = 0; i < len1; ++i)
		{
			for (int j = 0; j < len2; ++j)
			{
				if (s1[i] == s2[j])
				{
					if (i >= 1 && j >= 1)
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = 1;

					if (dp[i][j] > max)
						max = dp[i][j];
				}
			}

		}
		cout << max << endl;
	}
	return 0;
}

*/
