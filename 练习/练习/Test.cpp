#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

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
	cout << *m << endl;//afternoonÊä³ö½á¹û
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