#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
//���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
//ע���Ӵ��Ķ��壺��һ���ַ���ɾȥǰ׺�ͺ�׺��Ҳ���Բ�ɾ���γɵ��ַ�������͡������С��ĸ���ֿ���

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size()>b.size())
			swap(a, b);
		string str_m;
		for (int i = 0; i<a.size(); i++)
		{
			for (int j = i; j<a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp))<0)
					break;
				else if (str_m.size()<temp.size())
					str_m = temp;
			}
		}
		cout << str_m << endl;
	}
	return 0;
}


// ��Ӿ���
// https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false


/*
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < 3 * n; ++i)
		{
			cin >> v[i];
		}
		long long sum = 0; 
		std::sort(v.begin(), v.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}

*/

