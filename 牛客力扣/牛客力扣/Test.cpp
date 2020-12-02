#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//  未解决

//  数组中出现次数超过一半的数字
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

///////////////////////////////////////////
//  求最小公倍数
// https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking



int main()
{
	int A, B;
	cin >> A >> B;
	int max;
	if (A >= B)
		max = A;
	else
		max = B;
	for (int i = max; i <= A*B; i++)
	{
		if ((i%A == 0) && (i%B == 0))
		{
            cout << i;
			break;
		}
			
	}
	return 0;
}

/*
int main()
{
	int A, B;
	cin >> A >> B;
	int min, max, tmp;
	max = (A>B) ? A : B;
	min = (A>B) ? B : A;
	tmp = max;
	while (1)
	{
		if (max % min == 0)
		{
			cout << max;
			break;
		}
		else
			max += tmp;
	}
	return 0;
}
*/


////////////////////////////////////////////////////
//  合法括号序列判断
//   https://www.nowcoder.com/questionTerminal/d8acfa0619814b2d98f12c071aef20d4

/*
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> s;
		for (auto it = A.begin(); it != A.end(); it++)
		{
			if (*it == '(')
			{
				s.push(*it);
			}
			else
			{
				if (*it != ')' || s.empty())
					return false;
				else
					s.pop();
			}
		}
		if (s.empty())
			return true;
		else
			return false;
	}
};
*/




///////////////////////////////////////
//  斐波拉契数列，求一个数离他最近斐波拉契数的距离
//
//  https://exam.nowcoder.com/cts/17107720/summary?id=8930AAC2D789E146#4/{%22uid%22%3A%228930AAC2D789E146%22%2C%22type%22%3A%224%22%2C%22index%22%3A0}

/*
//    思想：计算出Fib 将他和N比较，F在他左边的时候：l=N-F，右边的时候：r=F-N  
//    找出l和r的最小值就可以了
int main()
{
	int N, f, l = 0, r = 0;
	int f0 = 0, f1 = 1;
	cin >> N;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;

		if (f < N)
		{
			l = N - f;
		}
		else if (f > N)
		{
			r = f - N;
			break;
		}
	}
	cout << min(l, r) << endl;
	return 0;
}

*/



//      还没有做出来 自己的思想：先判断是不是Fib，是的话 通过计数器算出离他最近的
//  现在的问题是：判断出了问题，还有是计数器的实现不对


/*
bool IsFib(int n)
{
	if (n == 0 || n == 1)
		return true;
	else
	{
		int n0 = 0, n1 = 1;
		while (n == n1 + n0)
		{

		}
	}
}
int main()
{
	int N;
	cin >> N;
	int count = 0;
	if (IsFib(N))
	{
		cout << 0;
	}
	else if (!IsFib(N))
	{
		while (!IsFib(N))
		{
			count++;
			N--;
		}
		cout << count;
	}
	return 0;
}
*/



//  求输出a ，b ， c
/*
#include <stdio.h>
int main()
{
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
	if (b != 2 || c-- != 3)  //  || 前面的运算结果成立（为1），后面的就不用计算了，C值不变
		printf("%d,%d,%d\n", a, b, c);
	else
		printf("%d,%d,%d\n", a, b, c);
	else
		printf("%d,%d,%d\n", a, b, c);
	return 0;
}

*/



//  输入一个字符串，求出该字符串包含的字符集合
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
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。
你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
*/


/*
#include<iostream>
#include<string>
using namespace std;
// 判断是否是回文
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


// 查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
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




//  计算糖果
//  A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
//  A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
//  现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
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





//  排序子序列
//  定义连续子序列：非递增或者非递减排序最少可以分为多少个子序列
//  把一个长度为n的整数数组分成若干段子序列，至少可以分为多少个子序列
//  https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

/*
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






// https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
//查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
//注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！

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





// 组队竞争
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

