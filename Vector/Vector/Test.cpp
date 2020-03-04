#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;

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
