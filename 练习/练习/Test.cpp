#define _CRT_SECURE_NO_WARNINGS 1
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