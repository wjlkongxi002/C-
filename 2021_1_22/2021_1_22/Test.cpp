#define _CRT_SECURE_NO_WARNINGS 1


// 小易的升级之路
//https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
/*
#include <iostream>
#include <vector>

using namespace std;

int gdc(int a, int b)
{
	int c;
	while (c = a%b)
	{
		a = b;
		b = c;
	}
	return b;
}

int main()
{
	int n, power;
	vector<int> num; //  存放怪兽能力值
	while (cin >> n >> power)
	{
		num.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> num[i];
		}

		for (int j = 0; j < n; ++j)
		{
			if (power >= num[j])
				power += num[j];
			else
				power += gdc(power, num[j]);
		}
		cout << power << endl;
	}
	return 0;
}

*/


//https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//
/*找出字符串中第一个出现一次的字符
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int Hashtable[256] = { 0 };
		for (auto &e : s)
		{
			Hashtable[e]++;
		}
		int i;
		for (i = 0; i < s.size(); i++)
		{
			if (Hashtable[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size())
			cout << -1 << endl;
	}

	return 0;
}


*/
