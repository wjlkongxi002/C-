#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace N
{
	int a=10;
	double b = 3.14;
	char c = 'asrf';

}

using N::b;
int main()
{
	printf("%d\n", N::a);
	printf("%f", b);
	/*int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;

	cout << a<<endl;
	cout << b   << "     "<<  c << endl;

	cout << "hello bit??" << endl;*/
	return 0;
}