#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class String
{
	friend ostream& operator<<(ostream &out, const String &s);

public:
	String(const char*str = "")
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	String(const String &s) :m_str(nullptr)
	{
		String tmp(s.m_str);
		std::swap(this->m_str, tmp.m_str);
	}
	~String()//析构函数
	{
		if (m_str)
		{
			delete[]m_str;
			m_str = nullptr;
		}
	}
	String& operator=(const  String &s)
	{
		if (this != &s)
		{
			String tmp(s);
			std::swap(m_str, tmp.m_str);
		}
		return *this;
	}

private:
	char *m_str;
};

ostream& operator<<(ostream &out, const String &s)
{
	out << s.m_str;
	return out;
}

void main()
{
	String s="wang";
	String s2 = s;
	String s3;
	s3 = s;
	cout << "s = " << s << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;

}



/*
//传统版本的string类
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
	friend istream& operator>>(ostream &in, String &s);
public:
	String(const char *str = "")//构造函数
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	String(const String &s)//拷贝构造函数，用对象初始化对象
	{
		m_str = new char[strlen(s.m_str) + 1];
		strcpy(m_str, s.m_str);
	}
	String&operator=(const String &s)//重载=
	{
		if (this != &s)
		{
			delete[]m_str;
			m_str = new char[strlen(s.m_str) + 1];
			strcpy(m_str, s.m_str);
		}
		return *this;
	}
	~String()
	{
		if (m_str)
		{
			delete[]m_str;
			m_str = nullptr; 
		}
	}
private:
	char *m_str;
};
ostream& operator<<(ostream &out, const String &s)
{
	out << s.m_str;
	return out;
}
istream& operator>>(istream &in, String &s)
{
	char buf[100] = {};
	in >> buf;
	return in;

}
void main()
{
	String s;
	cin>>s;
	cout << "s = " << s << endl;

}

/*
void main()
{
	String s="王佳龙";
	String s1 = s;
	String s2;
	s2 = s;
	cout << "s =" << s << endl;
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;

}
*/


/*
void main()//输入字符串，获取字符串
{
	string s;
	cout << "请输入>:";
	getline(cin, s);
	cout << "s=" << s << endl;
}

/*
void main()
{
	string email = "wangjialong@163.com";//查找字符，字符串
	size_t pos = email.find('@',16);
	if (pos != string::npos)
	{
		cout << "pos =" << pos << endl;
	}
	else
		cout << "not find" << endl;

	pos = email.find("jia");//查找字符串
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
	int len = strlen(str.c_str());//返回C格式字符
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

	//重载 operator[]
	for (int i = 0; i < str.size(); i++)
		cout << str[i];//str.operator[](i);
	cout << endl;
	
	//??????????????????????
	//C++11    
	for (auto &ele:str)
		cout << ele;
	cout << endl;

	//????????????????????????
	//迭代器  iterator  
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
	//cout << "empty=" << str2.empty() << endl;//检测是否为空

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
//string 对象的构造
void main()
{
	string str1;//空构造，空字符串
	cout << "str1 = " << str1 << endl;

	string str2("hello"); //string(const char* s)
	cout << "str2 = "<< str2  << endl;

	const char*s = "hello";//string(const char* s)
	string str3(s);
	cout << "str3 = " << str3 << endl;

	string str4(10,'x');//string(size_t n,char c)
	cout << "str4 = " << str4 << endl;

	//拷贝构造string(const string &s)   
	string str5(str3);
	cout << "str5 = " << str5 << endl;

	string str6 = str5;
	cout << "str6 = " << str6 << endl;
}
*/