#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void main()//�����ַ�������ȡ�ַ���
{
	string s;
	cout << "������>:";
	getline(cin, s);
	cout << "s=" << s << endl;
}

/*
void main()
{
	string email = "wangjialong@163.com";//�����ַ����ַ���
	size_t pos = email.find('@',16);
	if (pos != string::npos)
	{
		cout << "pos =" << pos << endl;
	}
	else
		cout << "not find" << endl;

	pos = email.find("jia");//�����ַ���
	if (pos != string::npos)
	{
		cout << "pos=" << pos << endl;
	}

	pos = email.rfind('m');
	if (pos != string::npos)
	{
		cout << "pos=" << pos << endl;
	}

	pos = email.find('w');
	cout << email.substr(pos, 5) << endl;
}
/*
void main()
{
	string str = "hello bit";
	int len = strlen(str.c_str());//����C��ʽ�ַ�
	cout << len << endl;
	cout << str.c_str() << endl;
}

/*
void main()
{
	//string str = "wang";
	////str.push_back(' ');
	//cout << str << endl;
	//str += ' ';
	//str += 'A';
	//cout << str << endl;


	string str1 = "wang";
	str1.append(" jialong");
	cout << str1 << endl;

	string str2 = "wang";
	str2 += "jialong";
	cout << str2 << endl;

	char *str = "C:\\C++\\STL.pdf";
	cout << str << endl;


}

/*
void main()
{
	string str = "wangjialong";
	cout << str<<endl;

	//���� operator[]
	for (int i = 0; i < str.size(); i++)
		cout << str[i];//str.operator[](i);
	cout << endl;
	
	//??????????????????????
	//C++11    
	for (auto &ele:str)
		cout << ele;
	cout << endl;

	//????????????????????????
	//������  iterator  
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

/*
void main()
{
	//string s = "hello world";
	//cout << "s = " << s << endl;
	//cout << "length = " << s.length() << endl;
	//cout << "size = " << s.size() << endl;
	//cout << "capacity = " << s.capacity() << endl;

	//string str1("wangjialong");
	//cout << "length=" << str1.length()<< endl;
	//cout << "capacity=" << str1.capacity() << endl;
	//str1 += "  kongxi";
	//cout << "str1=" << str1 << endl;
	//cout << "length=" << str1.length() << endl;
	//cout << "capacity=" << str1.capacity() << endl;
	

	//string str2("wangjialong");
	//cout << "length=" << str2.length() << endl;
	//cout << "capacity=" << str2.capacity() << endl;
	//cout << "empty=" << str2.empty() << endl;//����Ƿ�Ϊ��

	//string str3("wangjialong");
	//cout << "length=" << str3.length() << endl;
	//cout << "capacity=" << str3.capacity() << endl;
	//str3.clear();
	//cout << "size=" << str3.length() << endl;
	//cout << "capacity=" << str3.capacity() << endl;

	//string str4("wangjialong");
	//str4.reserve(20);
	//cout << "str4.length=" << str4.length() << endl;
	//cout << "str4.capacity=" << str4.capacity() << endl;

	//string str5("wangjialong");
	//cout << "str5.length=" << str5.length() << endl;
	//cout << "str5.capacity=" << str5.capacity() << endl;
	//str5.reserve(200);
	//cout << "str5.capacity=" << str5.capacity() << endl;
	//str5.reserve(20);
	//cout << "str5.capacity=" << str5.capacity() << endl;

	string str6("wangjialong");
	cout << "str6.length=" << str6.length() << endl;
	cout << "str6.capacity=" << str6.capacity() << endl;
	str6.resize(2);
	cout << "str6 " << str6 << endl;
	cout << "str6.length=" << str6.length() << endl;
	cout << "str6.capacity=" << str6.capacity() << endl;
}

/*
//string ����Ĺ���
void main()
{
	string str1;//�չ��죬���ַ���
	cout << "str1 = " << str1 << endl;

	string str2("hello"); //string(const char* s)
	cout << "str2 = "<< str2  << endl;

	const char*s = "hello";//string(const char* s)
	string str3(s);
	cout << "str3 = " << str3 << endl;

	string str4(10,'x');//string(size_t n,char c)
	cout << "str4 = " << str4 << endl;

	//��������string(const string &s)   
	string str5(str3);
	cout << "str5 = " << str5 << endl;

	string str6 = str5;
	cout << "str6 = " << str6 << endl;
}
*/