#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
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
	jon->Print();  // ������������
	jon->PrintInfo();  // ������������ʷǷ���ַ����ʱmName��mAge��û�з���ռ�
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
	// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
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
// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
// ������ʵ���������Ǻ���ѧϰ����Ԫ��������߸ɴ����سɳ�Ա������
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
	// ����d2���õ�Ĭ�Ͽ���������ɿ�����d2��d1��ֵҲ��һ���ġ�
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
// ���²��Ժ�����ͨ��������
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
	// 1.�޲ι��캯��
	Date()
	{}
	// 2.���ι��캯��
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
	Date d1; // �����޲ι��캯��
	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
	
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
}//ȫȱʡ����


short TestFunc(double a, int b, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}//�޷�����ֻ�������������ֵĺ�����������ȱʡ�����ĸ���
 //���ͣ�˳��ͬ
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
//}//����������������
//int main()
//{
//	Add(1);
//	return 0;
//}



//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====������������
//	int& rb =a;
//	printf("%d\n", a);
//	printf("%d\n", ra);
//	printf("%d\n", rb);
//}

//
//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // ��������ʱ�����aΪ����
//	const int& ra = a;
//	// int& b = 10; // ��������ʱ�����bΪ����
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
//	const int& rd = d;
//	printf("%d %d %d %.2f %d", a, ra, b, d, rd);
//}
//int main()
//{
//	//TestRef();
//	TestConstRef();
//	return 0;
//}