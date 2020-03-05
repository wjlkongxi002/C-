#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s1;
	while (cin >> s2)
		s1 = s2 + " " + s1;
	cout << s1 << endl;
	return 0;
}
/*
int main()
{
	string s1,s2;
	
	cin >> s1;
	while (cin >> s2)
	{
		s1 = s2 + " " + s1;
	}
	cout << s1 <<endl; 
	return 0;
}
/*
class CPeople
{
	//friend ostream& operator<<(ostream &out, const CPeople &s);
public:
	CPeople(const std::string& name, int age)
		: mName(name), mAge(age){}
	~CPeople();

	void Print()
	{
		std::cout << "show people info:" << std::endl;
	}

	void PrintInfo()
	{
		std::cout << "name:" << mName << std::endl;
		std::cout << "age:" << mAge << std::endl;
	}


private:

	std::string mName;
	int mAge;

};

//ostream& operator<<(ostream &out, const CPeople &s)
//{
//	out << s.mAge;
//	return out;
//}
int main()
{
	CPeople* jon = NULL;
	jon->Print();  // 程序正常运行
	jon->PrintInfo();  // 程序崩溃，访问非法地址，此时mName和mAge并没有分配空间
	return 0;
}


/*
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year, int month, int day)
		: _year(year) , _month(month)  , _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, const Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}


/*
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void Test()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
}
int main()
{
	Test();
}
/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// bool operator==(Date* this, const Date& d2)
	// 这里需要注意的是，左操作数是this指向的调用函数的对象
	bool operator==(const Date& d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}
int main()
{
	Test();
	return 0;
}



/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//private:
	int _year;
	int _month;
	int _day;
};
// 这里会发现运算符重载成全局的就需要成员变量是共有的，那么问题来了，封装性如何保证？
// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
	       && d1._month == d2._month
		&& d1._day == d2._day;
}
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}
int main()
{
	Test();
	return 0;
}

/*
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2(s1);
}

/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	// 这里d2调用的默认拷贝构造完成拷贝，d2和d1的值也是一样的。
	Date d2(d1);
		return 0;
}


/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}

/*
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Person p;
	return 0;
}
/*
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	/*Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
}

int main()
{

}
/*

class Date
{
public:
	// 1.无参构造函数
	Date()
	{}
	// 2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1; // 调用无参构造函数
	Date d2(2015, 1, 1); // 调用带参的构造函数
	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
	
}

int main()
{

}

/*
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	return 0;
}
*/
//namespace N
//{
//	int a=10;
//	double b = 3.14;
//	char c = 'asrf';
//
//}
//
//using N::b;
//int main()
//{
//	//printf("%d\n", N::a);
//	//printf("%f", b);
//	int a;
//	double b;
//	char c;
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a<<endl;
//	cout << b   << "     "<<  c << endl;
//
//	cout << "hello bit??" << endl;
//	return 0;
//}
/*
int TestFunc(int a, int b=10, int c = 30);

 int TestFunc(int a , int b , int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}//全缺省参数


short TestFunc(double a, int b, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}//无法重载只按返回类型区分的函数，必须是缺省参数的个数
 //类型，顺序不同
int main()
{
	TestFunc(100,200,300);
	TestFunc(100, 200, 300);
	return 0;
}
*/
/*
int Add(int left, int right)
{
	cout << right + left << endl;
	return 0;
}
double Add(double left, double right)
{
	cout << right + left << endl;
	return 0;
}
*/
//void Add (int a = 10)
//{
//	cout << "void Add(int)" << endl;
//}
//void Add(int a=20)
//{
//	cout << "void Add(int)" << endl;
//}//两个函数不能重载
//int main()
//{
//	Add(1);
//	return 0;
//}



//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====定义引用类型
//	int& rb =a;
//	printf("%d\n", a);
//	printf("%d\n", ra);
//	printf("%d\n", rb);
//}

//
//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常量
//	const int& ra = a;
//	// int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;
//	printf("%d %d %d %.2f %d", a, ra, b, d, rd);
//}
//int main()
//{
//	//TestRef();
//	TestConstRef();
//	return 0;
//}