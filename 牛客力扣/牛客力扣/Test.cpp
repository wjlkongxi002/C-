#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//  δ���

//  �����г��ִ�������һ�������
//  https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

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


//  ����һ���ַ�����������ַ����������ַ�����
//  https://www.nowcoder.com/questionTerminal/784efd40ed8e465a84821c8f3970b7b5

/*
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str;
	while (cin >> str)
	{
		int count[256] = { 0 };
		int size = str.size();
		for (int i = 0; i < size; ++i)
		{
			if (0 == count[str[i]])
				cout << str[i];
			count[str[i]]++;
		}
		cout << endl;
	}
	return 0;
}


*/





/*
�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
*/


/*
#include<iostream>
#include<string>
using namespace std;
// �ж��Ƿ��ǻ���
bool IsCircleText(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		++begin;
		--end;
	} 
	return true;
} 
int main()
{
	std::string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
}

*/


// ���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
// https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506


/*
#include<iostream>
#include<string>
using namespace std;
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




//  �����ǹ�
//  A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ��
//  A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
//  ������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������
//https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

/*
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int B1 = (b + d) / 2;
	int C = (d - b) / 2;
	int B2 = (c - a) / 2;
	if (B1 != B2)
		cout << "No";
	else
		cout << A << " " << B1 << " " << C;
	return 0;
}

*/





//  ����������
//  �������������У��ǵ������߷ǵݼ��������ٿ��Է�Ϊ���ٸ�������
//  ��һ������Ϊn����������ֳ����ɶ������У����ٿ��Է�Ϊ���ٸ�������
//  https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

/*
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

*/






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

