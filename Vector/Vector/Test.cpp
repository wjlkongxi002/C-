#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;

void Test1()//构造函数
{
	vector<int> v1;
	vector<int> v2{1,2,3,4,5};
	
	vector<int> v3(v2);//拷贝构造
	vector<int> v4(10, 1);//10个1
	int arr[] = { 1, 2, 3, 4, 5 };  //定义数组
	vector<int> v6(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int> v5(v2.begin(), v2.end());//迭代器
	
	string s("hello");
	vector<char> v(s.begin(), s.end());

	cout << v2[0] << endl;
}
void Test2()
{
	// 循环打印
	vector<int> v = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] <<" ";
	}
	cout << endl;

	//e是对v中每一个元素的引用，会改变元素的值
	for (auto& e : v)
	{
		cout << e*2 << " ";
	}
	cout << endl;

	// 范围for的原理与采用与迭代器的原理是一样的，完全相同的
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	auto rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void Test3()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	if (v.empty())
		cout << " v empty " << endl;
	cout << v.size()<< endl;
	cout << v.capacity() << endl;

	/*
	void resize(size_type sz, T c = T())
	将vector中的有效元素个数调整到sz个，如果多出，就会用c元素来填充
	假设：原始空间大小为oldsize，底层容量为oldcapa
     如果sz< oldsize ，newsize就是sz大小，newcapa=oldcapa
	 如果sz> oldsize
	     sz < oldcapa 将有效空间扩充到sz，多出的用c填充
		 sz > oldcapa 扩容，开辟空间
		                    拷贝元素
							释放原有空间
	*/
	v.resize(10, 0);

}
class A
{
public:
	
	//A() 无参的构造函数只能有一个，出现多个就会产生二义性，导致在构造时不知道使用哪一个
	//{}

	A(int a = 10)
		: _a(a)
	{}

	A(const A& a)
		: _a(a._a)
	{
		cout << "A(const A&)" << endl;
	}
private:
	int _a;
};

void Test4()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	v.reserve(10);
	v.reserve(20);
	v.reserve(15);
	//reserve 在底层扩充容量，当扩充的容量比上一次的少的时候
	//容量大小不变还是上一次的容量
	//当扩充的容量n比之前的容量大的时候，开辟n个空间，将旧元素拷贝到心得空间中，释放原来的空间

}
void Test5()
{
	vector<int> v{};
	cout << v[0] << endl;
	cout << v.at(0) << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	/*
	下标访问或者at访问时，front back访问数组函数时，vector中
	必须有元素，不能是空的，否则会出现越界访问的错误
	*/
}

void Test6()
{
	vector<int> v{ 1, 2, 3, 4 };
	v.push_back(5);
	v.push_back(6);
	v.pop_back();//pop_back()是无参的
	vector<int>::iterator it = v.begin();
	v.insert(it,0);
	//v.insert(v.begin(), 5, 9);
	// 需求在元素2的位置插入10个值为5的元素
	//v.insert(v.begin() + 2, 10, 5);
	//v.insert(find(v.begin(), v.end(), 2), 10, 5);
	//将数组array中的元素插入到v的尾部
	int arr[] = { 5, 6, 7, 8 };
	//代码错误，不知道啥原因：原因是 数组名就是数组首元素的地址，
	// arr[0] 指的是首元素，不是地址
	// v.insert(v.end(), arr[0], arr[0] + sizeof(arr) / sizeof(arr[0])-1);
	v.insert(v.end(), arr, arr + sizeof(arr) / sizeof(arr[0]));
}
void Test7()
{
	vector<int> v{ 1, 2, 3, 4 };

	//v.erase(v.begin());
	v.erase(v.end()-1);
	// v.erase(v.end());
	/*
	该函数的返回值是，删除的元素的下一个元素的地址
	不能删除最后一个元素，原因是最后一个元素没有下一个元素
	*/
}
void Test8()
{
	vector<int> v1{ 1, 2, 3, 4 };
	vector<int> v2{ 5, 6, 7, 8 };
	v1.swap(v2);//通过交换指向两个空间的指针来进行空间的交换，可能会存在迭代器的失效问题
	swap(v1, v2);//实现原理是在底层创建了一个临时空间，通过临时空间进行交换
}
void Test9(size_t n)
{
	//打印杨辉三角
	//1
	//1 1
	//1 2 1
	//1 3 3 1
	//1 4 6 4 1
	vector<vector<int>> vv;//二维数组
	
	// 开辟保存每行vector元素的空间
	vv.resize(n);
	
	// 开辟每行的空间
	for (size_t i = 0; i < n; ++i)
	{
		vv[i].resize(i + 1, 1);//第几行就有第几个元素，每个元素置为1
	}

	// 计算出第0行和对角线之外的元素

	for (size_t i = 2; i < n; ++i) //前两行都是1,从第三行开始，下标从0开始
	{
		for (size_t j = 1; j < i; ++j)//第0行全是1，从第1行开始
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];//该元素等于它上一行的元素+上一行元素左边一个
		}
	}
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			printf("%3d", vv[i][j]);
		}
		printf("\n");
	}
}

//创建二维数组，二级指针
	int **Create(int row, int col)
	{
		int **p = new int*[row]; //开辟row行，每一行是一个int*类型
		for (int i = 0; i < row; ++i)
		{
			p[i] = new int[col];//开辟列空间，每一行有col个元素
		}
		return p;
	}


int main()
{
	// Test1();
	// Test2();
	// Test3();
	// Test4();
	// Test5();
	// Test6();
	//Test7();
	// Test8();
    // A b;
	Test9(5);

	return 0;
}




/*
namespace bit
{
	template <typename T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{}
		vector(size_t n, const T &value = T())
			:start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{
			reserve(n);
			while (n-- != 0)
				push_back(value);
		}
		~vector()
		{
			delete[]start;
			start = finish = end_of_storage = nullptr;
		}
	public:
		void push_back(const T &x)
		{
			insert(end(), x);
		}
	public:
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T *new_start = new T[n];
				if (start)
				{
					for (int i = 0; i < oldsize; ++i)
					{
						new_start[i] = start[i];
					}
				}

				if (start)
					delete[]start;

				start = new_start;
				finish = start + oldsize;
				end_of_storage = start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				finish = start + n;
				return;
			}
			if (n > capacity())
				reserve(n * 2);

			iterator p = finish; 定义一个迭代器p，指向finish的位置
				finish = start + n;
			while (p != finish)
			{
				*p = value;
				p++;
			}
		}

		//在POS位置上插入X  返回插入元素后迭代器所指的位置
		iterator insert(iterator pos, const T &x)
		{
			if (finish >= end_of_storage)
			{
				size_t oldpos = pos - start;
				size_t new_cpt = capacity() ? capacity() * 2 : 1;
				reserve(new_cpt);

				//重新定位迭代器
				pos = start + oldpos;
			}

			iterator p = finish;
			while (p != pos)
			{
				*p = *(p - 1);
				p--;
			}
			*p = x;
			finish++;
			return pos;
		}


		iterator erase(iterator pos)
		{
			iterator p = pos;
			while (p != finish - 1)
			{
				*p = *(p + 1);
				p++;
			}
			finish--;
			return pos;
		}
	public:
		size_t size()
		{
			return finish - start;
		}
		size_t capacity()
		{
			return end_of_storage - start;
		}
		bool empty()
		{
			return finish == start;
		}
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}
	void main()
	{
		bit::vector<int> v = (10, 1);
		cout << "size =" << v.size() << endl;
		cout << "capacity =" << v.capacity() << endl;
		for (auto &e : v)
			cout << e << " ";
		cout << endl;
	}
*/




	/*void main()
	{
	bit::vector<int> v;
	cout << "size =" << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	v.insert(v.begin(), 1);
	v.insert(v.begin(), 2);
	v.insert(v.begin(), 3);
	v.insert(v.begin(), 4);
	v.insert(v.end(), 0);

	auto p = find(v.begin(), v.end(), 3);
	v.insert(p, 10);
	v.push_back(200);
	for (auto &e : v)
	cout << e << " ";
	cout << endl;

	//p = find(v.begin(), v.end(), 10);
	//v.erase(p);
	v.erase(v.end());

	for (auto &e : v)
	cout << e << " ";
	cout << endl;
	/*
	v.resize(15, 1);
	cout << "size =" << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	for (auto &e : v)
	cout << e << " ";
	cout << endl;
	/*
	v.reserve(2);
	cout << "size =" << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	v.reserve(20);
	cout << "size =" << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	v.reserve(2);
	cout << "size =" << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	*/




/*
void main()
{
	vector<int> v;
	v.reserve(100);
	for (int i = 0; i<100; ++i)
	{
		cout << "capacity = " << v.capacity() << endl;
		v.push_back(i);
	}
} 



void Print(vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;
}

void main()
{
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v(ar, ar + 10);
	//cout << "size = " << v.size() << endl;
	//cout << "capacity = " << v.capacity() << endl;
	Print(v);
	v.resize(6);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	Print(v);


}
/*
void main()
{

	int ar[3] = { 1, 2, 3 };
	vector<int> v(ar, ar + 3);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	Print(v);
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(100);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(50);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	Print(v);
}

/*
void main()
{
	vector<int> v;
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	v.push_back(1);
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;

	v.push_back(2);
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";
	cout << endl;

	v.push_back(20);
	cout << "size = " << v.size() << endl;
	cout << "capacity =" << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";
	cout << endl;
}

/*
void main()
{
	//vector的使用

	//[]  operator[]重载[]
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v4(ar, ar + 10);
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;

	//at() 输出，会检测下标
	for (int i = 0; i < v4.size(); i++)
		cout << v4.at(i) << " ";
	cout << endl;

	//利用迭代器iterator
	vector<int>::iterator it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//反向迭代器
	vector<int>::reverse_iterator rit = v4.rbegin();
	while (rit != v4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout<<endl;

}
/*
void main()
{
	//默认构造
	vector<int> v1;
	//构造并初始化n个val值
	vector<int> v2(10,1);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	
	//拷贝构造
	vector<int> v3(v2);
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	//以数组形式构造
	//vector( value_type *first, value_type *last);
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v4(ar, ar + 10);
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;

	//vector (InputIterator first, InputIterator last);
	vector<int> v5(v4.begin(),v4.end());
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;
}
	*/
