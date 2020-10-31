#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;

void Test1()//���캯��
{
	vector<int> v1;
	vector<int> v2{1,2,3,4,5};
	
	vector<int> v3(v2);//��������
	vector<int> v4(10, 1);//10��1
	int arr[] = { 1, 2, 3, 4, 5 };  //��������
	vector<int> v6(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int> v5(v2.begin(), v2.end());//������
	
	string s("hello");
	vector<char> v(s.begin(), s.end());

	cout << v2[0] << endl;
}
void Test2()
{
	// ѭ����ӡ
	vector<int> v = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] <<" ";
	}
	cout << endl;

	//e�Ƕ�v��ÿһ��Ԫ�ص����ã���ı�Ԫ�ص�ֵ
	for (auto& e : v)
	{
		cout << e*2 << " ";
	}
	cout << endl;

	// ��Χfor��ԭ����������������ԭ����һ���ģ���ȫ��ͬ��
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
	��vector�е���ЧԪ�ظ���������sz�������������ͻ���cԪ�������
	���裺ԭʼ�ռ��СΪoldsize���ײ�����Ϊoldcapa
     ���sz< oldsize ��newsize����sz��С��newcapa=oldcapa
	 ���sz> oldsize
	     sz < oldcapa ����Ч�ռ����䵽sz���������c���
		 sz > oldcapa ���ݣ����ٿռ�
		                    ����Ԫ��
							�ͷ�ԭ�пռ�
	*/
	v.resize(10, 0);

}
class A
{
public:
	
	//A() �޲εĹ��캯��ֻ����һ�������ֶ���ͻ���������ԣ������ڹ���ʱ��֪��ʹ����һ��
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
	//reserve �ڵײ��������������������������һ�ε��ٵ�ʱ��
	//������С���仹����һ�ε�����
	//�����������n��֮ǰ���������ʱ�򣬿���n���ռ䣬����Ԫ�ؿ������ĵÿռ��У��ͷ�ԭ���Ŀռ�

}
void Test5()
{
	vector<int> v{};
	cout << v[0] << endl;
	cout << v.at(0) << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	/*
	�±���ʻ���at����ʱ��front back�������麯��ʱ��vector��
	������Ԫ�أ������ǿյģ���������Խ����ʵĴ���
	*/
}

void Test6()
{
	vector<int> v{ 1, 2, 3, 4 };
	v.push_back(5);
	v.push_back(6);
	v.pop_back();//pop_back()���޲ε�
	vector<int>::iterator it = v.begin();
	v.insert(it,0);
	//v.insert(v.begin(), 5, 9);
	// ������Ԫ��2��λ�ò���10��ֵΪ5��Ԫ��
	//v.insert(v.begin() + 2, 10, 5);
	//v.insert(find(v.begin(), v.end(), 2), 10, 5);
	//������array�е�Ԫ�ز��뵽v��β��
	int arr[] = { 5, 6, 7, 8 };
	//������󣬲�֪��ɶԭ��ԭ���� ����������������Ԫ�صĵ�ַ��
	// arr[0] ָ������Ԫ�أ����ǵ�ַ
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
	�ú����ķ���ֵ�ǣ�ɾ����Ԫ�ص���һ��Ԫ�صĵ�ַ
	����ɾ�����һ��Ԫ�أ�ԭ�������һ��Ԫ��û����һ��Ԫ��
	*/
}
void Test8()
{
	vector<int> v1{ 1, 2, 3, 4 };
	vector<int> v2{ 5, 6, 7, 8 };
	v1.swap(v2);//ͨ������ָ�������ռ��ָ�������пռ�Ľ��������ܻ���ڵ�������ʧЧ����
	swap(v1, v2);//ʵ��ԭ�����ڵײ㴴����һ����ʱ�ռ䣬ͨ����ʱ�ռ���н���
}
void Test9(size_t n)
{
	//��ӡ�������
	//1
	//1 1
	//1 2 1
	//1 3 3 1
	//1 4 6 4 1
	vector<vector<int>> vv;//��ά����
	
	// ���ٱ���ÿ��vectorԪ�صĿռ�
	vv.resize(n);
	
	// ����ÿ�еĿռ�
	for (size_t i = 0; i < n; ++i)
	{
		vv[i].resize(i + 1, 1);//�ڼ��о��еڼ���Ԫ�أ�ÿ��Ԫ����Ϊ1
	}

	// �������0�кͶԽ���֮���Ԫ��

	for (size_t i = 2; i < n; ++i) //ǰ���ж���1,�ӵ����п�ʼ���±��0��ʼ
	{
		for (size_t j = 1; j < i; ++j)//��0��ȫ��1���ӵ�1�п�ʼ
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];//��Ԫ�ص�������һ�е�Ԫ��+��һ��Ԫ�����һ��
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

//������ά���飬����ָ��
	int **Create(int row, int col)
	{
		int **p = new int*[row]; //����row�У�ÿһ����һ��int*����
		for (int i = 0; i < row; ++i)
		{
			p[i] = new int[col];//�����пռ䣬ÿһ����col��Ԫ��
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

			iterator p = finish; ����һ��������p��ָ��finish��λ��
				finish = start + n;
			while (p != finish)
			{
				*p = value;
				p++;
			}
		}

		//��POSλ���ϲ���X  ���ز���Ԫ�غ��������ָ��λ��
		iterator insert(iterator pos, const T &x)
		{
			if (finish >= end_of_storage)
			{
				size_t oldpos = pos - start;
				size_t new_cpt = capacity() ? capacity() * 2 : 1;
				reserve(new_cpt);

				//���¶�λ������
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
	//vector��ʹ��

	//[]  operator[]����[]
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v4(ar, ar + 10);
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;

	//at() ����������±�
	for (int i = 0; i < v4.size(); i++)
		cout << v4.at(i) << " ";
	cout << endl;

	//���õ�����iterator
	vector<int>::iterator it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//���������
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
	//Ĭ�Ϲ���
	vector<int> v1;
	//���첢��ʼ��n��valֵ
	vector<int> v2(10,1);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	
	//��������
	vector<int> v3(v2);
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	//��������ʽ����
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
