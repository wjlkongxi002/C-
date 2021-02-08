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
