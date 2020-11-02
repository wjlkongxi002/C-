#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// ���������ɵ�Ĭ�Ͽ������캯��---ǳ����
	String(const String& s)
		: _str(s._str)
	{}


	// ���������ɵ�Ĭ�ϸ�ֵ���������---ǳ����
	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	//String s2(s1);
	String s3("hello");
	s1 = s3;
	return 0;
}


/*

int main()
{
	string s("12345");
	int  value = atoi(s.c_str());

	string s1("hello");
	char* p = (char*)s1.c_str();
	*p = 'H';

	cout << sizeof(string) << endl;
	return 0;
}

*/




//��ʼ��
/*
void Teststring()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	cout << s[0] << endl;
	cout << s[8] << endl;
	cout << s << endl;
	cout << s.at(0) << endl;
	s.at(0) = 'h';
	cout << s << endl;
}

void Teststring1()
{
	string s;
	//cin >> s;
	//cout << s << endl;//cout�����ո�ͻ�ֹͣ���

	string s1("hello world !!!");
	s1.insert(s1.find(' ', 7), "$$$");//���ַ����ĵ��߸�λ�ÿ�ʼ��ѯ�� �������ز��ҵ���λ��
	cout << s1 << endl;
}
void Teststring2()
{
	string s;
	getline(cin, s);
	cout << s << endl;
	cout << s.rfind(' ') + 1 << endl;
	cout << s.substr(s.rfind(' ') + 1).size() << endl;
}

int main()
{
	Teststring2();
	//Teststring1();
	//Teststring();
	return 0;
	
}
*/
