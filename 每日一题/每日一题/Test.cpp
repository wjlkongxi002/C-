#define _CRT_SECURE_NO_WARNINGS 1
////////////////////////////
// 1
// https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
// 组队竞赛
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long long sum = 0;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < 3 * n; ++i)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int j = n; j <= 3 * n - 2; j += 2)
		{
			sum += v[j];
		}
		cout << sum << endl;
	}
	return 0;
}

*/

////////////////////////////
//2
//https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&tqId=29868&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2F2017test%2Fquestion-ranking&tab=answerKey
//删除公共字符
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	string s;
	getline(cin, s1);
	getline(cin, s2);
	int Hashtable[256] = { 0 };
	for (int i = 0; i < s2.size(); ++i)
	{
		Hashtable[s2[i]]++;
	}

	for (int j = 0; j < s1.size(); ++j)
	{
		if (Hashtable[s1[j]] == 0)
			s += s1[j];
	}
	cout << s << endl;
	return 0;
}

*/

/////////////////////////////
//3
//排序子序列
//定义连续子序列：非递增或者非递减排序最少可以分为多少个子序列
//把一个长度为n的整数数组分成若干段子序列，至少可以分为多少个子序列
//https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

/*
#include<iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// 注意这里多给了一个值，是处理越界的情况的比较，具体参考上面的解题思路
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	//读入数组
	int i = 0;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n)
	{
		// 非递减子序列
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++;
			i++;
		}
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else // 非递增子序列
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}


*/
