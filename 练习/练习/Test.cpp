#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

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