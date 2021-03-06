﻿#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include<math.h>
#include <list>
using namespace std;


bool Isnum(int n)
{
	for (int i = 1; i < sqrt(n); ++i)
	{
		if (n%i == 0)
			return false;
		++i;
	}
	return true;
}
int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		for (int i = 2; i<n; ++i)
		{
			while (Isnum(i))
			{
				if (i % 10 == 1)
					v.push_back(i);
			}
			for (int i = 0; i<v.size() - 1; ++i)
			{
				cout << v[i] << " ";
			}
			cout << v[v.size()];
		}
		if (v.empty())
		{
			return -1;
		}
	}
	return 0;
}


/*

int main()

{

	int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };

	int n = sizeof(array) / sizeof(int);

	list<int> mylist(array, array + n);

	auto it = mylist.begin();

	while (it != mylist.end())

	{

		if (*it != 0)

			cout << *it << " ";

		else

			it = mylist.erase(it);

		++it;

	}

	return 0;

}*/


/*
int main()
{

	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int n = sizeof(ar) / sizeof(int);

	list<int> mylist(ar, ar + n);

	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	reverse(mylist.begin(), pos);

	reverse(pos, mylist.end());

	list<int>::const_reverse_iterator crit = mylist.crbegin();

	while (crit != mylist.crend())

	{

		cout << *crit << " ";

		++crit;

	}

	cout << endl;
	return 0;

}

/*

// 正确代码

class Solution {
public:
	
	string change(string number) {
		// write code here
		int len = number.size();
		int i = 0, j = len - 1;
		while (i < j) {
			while (i < j && (number[i] - '0') & 1)
				i++;
			while (i < j && (number[j] - '0') & 1)
				j--;
			if (i < j)
				swap(number[i++], number[j--]);
		}
		return number;
	}
};



/*
//  错误代码

class Solution {
public:
	
	string change(string number) {
		int len = number.length();
		int it = 0, rit = len - 1;
		while (it < rit)
		{
			while (it < rit && (number[it] - '0') & 1)
				it++;
			while (it < rit && (number[rit] - '0') & 1)
				rit--;
			if (it<rit)
				swap(number[it++], number[rit++]);
		}
		return number;
	}
};
*/



/*
class Solution {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
		{
			int num= (fib(n - 1) + fib(n - 2)) ;
			return num;
		}
	}
};

	int main()
	{
		Solution s;
		s.fib(5);
	}

/*
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
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

int main()
{
	Solution s;
	vector<int> v = { 2, 7, 11, 15 };
	s.twoSum(v, 20);
	return 0;
}

//double Add(int left, int right)函数重载，不考虑函数返回值类型
//{
	 //return left + right;
//}


*/
/*
int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	return 0;
}*/

/*
int main()
{
	int n, i, j = 0;
	while (cin >> n)
	{
		for (i = 2; i <= sqrt(n); i++)
		{
			while (n / i == 0)
			{
				if (n%i == 0)
					n = n / i;
			}
			j++;
		}
		
		if (n%i == 0)
			cout << j -1<< endl;
	}
	return 0;
}
*/


/*
int main()
{
	double n, r;
	while (cin >> n >> r);
	{
		if (n > (2 * 3.14*r))
			cout << "No" << endl;
		else
		cout << "Yes" << endl;
	}
	return 0;
}

/*
int main()
{
	int n, r;
	cin >> n >> r;
	if (n > 2 * 3.14*r)
		cout << 'No' << endl;
	cout << 'Yes' << endl;
		return 0;
}

/*
int getnode(int n)
{
	int node = 0;
	while (n > 0)
	{
		node += n % 10;
		n = n / 10;
	}
	while (node > 9)
	{
		node = getnode(node);
	}
	return node;
}
int main()
{
	string s;
	getline(cin, s);
	return 0;
}

/*
int getnode(int n)
{
	int node = 0;
	while (n > 0)
	{
		node += n % 10;
		n = n / 10;
	}
	while (node > 9)
	{
		node = getnode(node);
	}
	return node;
}
int main()
{
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (int i = 0; i < s.length(); i++) 
		{
			sum += s[i] - '0';
		}
		cout << getnode(sum) << endl;
	}
	return 0;
}

/*
int main()
{
	string s;
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (s[begin] < s[end])
	{
		swap(s[begin], s[end]);
		begin++;
		end--;
	}
		
	return 0;
}

/*
class Solution {
public:
	string reverseString(string s) {
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
};
int main()
{
	string s;
	cin >> s;
	return 0;
}
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

/*
int main()
{
	int n;
	while 
	{
		while (n != 0)
		{
			n = n / 2;
			cout << n << endl;
		}
	}
	return 0;
}


/*
int main()
{
	int arr[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 265 };
	int year, month, day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += arr[month - 2];
		sum += day;
		if (month>2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}
/*
class cla{
public:
	cla(int i = 0)
	{
		cout << 1;
	}
	cla(const cla&x)
	{
		cout << 2;
	}
	cla &operator=(const cla&x)
	{
		cout << 3; return *this;
	}
	~cla()
	{
		cout << 4;
	}
};
int main()
{
	cla obj1(1), obj2(2), obj3(obj1);
	return 0;
}

/*
int main()
{
	int i = 1;
	if (i <= 0)
		cout << " **** " << endl;
	else
		cout << "&&&&&&" << endl;
	return 0;
}

/*
struct A{
	void foo(){ printf("foo"); }
	virtual void bar(){ printf("bar"); }
	A(){ bar(); }

};
struct B :A{
	void foo(){ printf("b_foo"); }
	void bar(){ printf("b_bar"); }
};
int main()
{
	A *p = new B;
	p->foo();
	p->bar();
	return 0;
}

/*
int main()
{
	int **a[3][4];
	cout << sizeof(a) << endl;//48
	return 0;
}

/*
//输出&&&&&&&
int main()
{
	int i = 1;
	if (i <= 0)
		cout << " **** " << endl;
	else
		cout << "&&&&&&" << endl;
	return 0;
}


/*
//  ab
class p{
public:
	p(std::string name){ std::cout << name; }
};
class c{
public:
	c() :b("b"), a("a"){}
	p a;
	p b;
};

int main()
{
	c m;
	return 0;
}
/*
class cla{
public:
	cla(int i = 0)
	{
		cout << 1;
	}
	cla(const cla&x)
	{
		cout << 2;
	}
	cla &operator=(const cla&x)
	{
		cout << 3; return *this;
	}
	~cla()
	{
		cout << 4;
	}
};
int main()
{
	cla obj1(1), obj2(2), obj3(obj1);
	return 0;
}

/*
void func(char **m)
{
	m++;
	cout << *m << endl;//afternoon输出结果
}
int main()
{
	static char *a[] = { "morning", "aftrnoon", "evenibg" };
	char **p;
	p = a;
	func(p);
	return 0;
}
/*
class cla{
	static int n;
public:cla(){ n++; }
	   ~cla(){ n--; }
	   static int get_n(){ return n; }
};
int cla::n = 0;
int main()
{
	cla*p = new cla;
	delete p;
	cout << "n=" << cla::get_n() << endl;
	return 0;
}

/*
int main()
{
	int F1 = 0, F2 = 1;
	int F`
	return 0;

}

/*
class A
{
	friend long fun(A s)
	{
		if (s.x < 3)
		{
			return 1;
		}
		return s.x + fun(A(s.x - 1));
	}

public:
	A(long a)
	{
		x = a--;
	}
private:
	long x;
};
int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += fun(A(i));
	}
	cout << sum;
}



/*
class Solution {
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int sum = 0;
		for (int i = 0; i<str.length(); ++i)
		{
			if (str[i]<'0' || str[i]>'9')
				return sum = 0;
			sum = sum * 10 + str[i];
		}
		return sum;
	}
};
int main()
{
	string s;
	getline(cin, s);
    std::string StrToInt(s);
	cout << s << endl;
	return 0;
}

/*
char fun(char x, char y)
{
	if (x < y)
		return x;
	return y;
}
int main()
{
	int a = '1', b = '1', c = '2';
	cout << fun(fun(a, b), fun(b, c));
	cout << sizeof(int *);
	return 0;

}


/*
int main()
{
	int m = 0123, n = 123;
	printf("%o %o\n", m, n);//123 173    ???
	return 0;
}
/*
int main()
{
	string str;
	cin >> str;
	string tmp;
	string maxstr;
	int maxlen = 0;
	for (int i = 0; i<str.length(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			while (str[i] >= '0'&&str[i] <= '9')
			{
				tmp += str[i++];
			}
			if (tmp.size()>maxlen)
			{
				maxstr = tmp;
				maxlen = tmp.size();
			}
		}
		tmp.clear();
	}
	cout << maxstr;
	return 0;
}


/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1;
	while (cin >> s2)
		s1 = s2 + " " + s1;
	cout << s1 << endl;
	return 0;
}
*/