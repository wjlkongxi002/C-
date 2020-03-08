#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

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