#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


/*
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		vector<int> v;
		int count = 0;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size(); ++i)
		{
			while (numbers[i + 1] == numbers[i])
			{
				count++;
			}
			if (count > numbers.size() / 2)
				cout << numbers[i];
		}
		return 0;
	}
};

int main()
{
	Solution s;
	vector<int> v1{ 1, 2, 3, 2, 2, 2, 2, 5, 2 };
	s.MoreThanHalfNum_Solution(v1);

	return 0;
}


*/

int main()
{
	int n;
	cin >> n;
	// ע����������һ��ֵ���Ǵ���Խ�������ıȽϣ�����ο�����Ľ���˼·
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	//��������
	int i = 0;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n)
	{
		// �ǵݼ�������
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
		else // �ǵ���������
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





// https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
//���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
//ע���Ӵ��Ķ��壺��һ���ַ���ɾȥǰ׺�ͺ�׺��Ҳ���Բ�ɾ���γɵ��ַ�������͡������С��ĸ���ֿ���

/*
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

*/





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

