#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <assert.h>

namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		// �޲ι��캯��
		vector()
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}
		// ����n��dataֵ
		vector(int n, const T& data = T())// ?  // ����+()�ǹ��캯��   test ��һ���Զ�������
			: start(new T[n])
			, finish(start + n)
			, endofstorage(finish)
		{
			for (int i = 0; i < n; ++i)
			{
				start[i] = data;  //*(p+i)=p[i]  �����ռ������[]����
			}
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			// ȷ���ռ����м���Ԫ��
			Iterator it = first;
			size_t count = 0;
			while (it != last)
			{
				count++;
				++it;
			}

			//����ǰ���󿪱ٿռ䣬����ʼ����Ա����
			start = new T[count];
			finish = start;
			endofstorage = start + count;

			// ��ֵ
			while (first != last)
			{
				*finish++ = *first++;
			}
		}

		vector(const vector<T>& v)
		{
			size_t vsize = v.size();
			start = new T[vsize];
			finish = endofstorage = start + vsize;
			for (size_t i = 0; i < vsize; ++i)
			{
				start[i] = v[i];
			}
		}

		~vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = endofstorage = nullptr;
			}
		}


		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return endofstorage - start;
		}

		bool empty()const
		{
			return start == finish;
		}

		// ���� 
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				finish = start + newsize;
			}
			else
			{
				if (newsize > capacity())
					reserve(newsize);  //����

				for (size_t i = oldsize; i < newsize; ++i)
				{
					start[i] = data;
				}
				finish = start + newsize;
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			size_t oldsize = size();
			if (newcapacity > oldcapacity)
			{
				//���ٿռ�
				T* temp = new T[newcapacity];

				//����Ԫ��
				for (size_t i = 0; i < oldsize; ++i)
				{
					temp[i] = start[i];
				}

				//�ͷſռ�  
				delete[] start;

				start = temp;
				finish = start + oldsize;
				endofstorage = start + newcapacity;
			}
		}
		///////////////////////////////////////////
		//access
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}
		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}
		T& front()
		{
			return start[0];
		}
		const T& front()const//()�����const����thisָ�벻�ܱ��ı�
		{
			return start[0];
		}

		T& back()
		{
			return start[size() - 1];
		}
		const T& back()const
		{
			return start[size() - 1];
		}
		//////////////////////////////////////////////

		// modify
		void push_back(const T& data)
		{
			if (size() == capacity())
				reserve(capacity() * 2 + 3);
			*finish++ = data;
		}

		void pop_back()
		{
			if (empty())
				return;
			--finish;
		}

		iterator insert(iterator pos, const T& data)
		{
			assert(pos <= end());//assert ����ֵ�����0 �ͻ����ʧ��
			if (size() == capacity())
				reserve(capacity() * 2);

			auto it = end();
			while (it > pos)
			{
				*it = *(it - 1);
				--it;
			}
			*pos = data;
			++finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos < end());
			if (size() == 1)
			{
				pop_back();
				return end();
			}
			auto it = pos;
			while (it < end())
			{
				*it = *(it + 1);
				++it;
			}
			--finish;
			return pos;
		}

		void clear()
		{
			finish = start;
		}


		void swap(const vector<T>& v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(endofstorage, v.endofstorage);
		}


	private:
		iterator start;
		iterator finish;
		iterator endofstorage;

	};
}



#include<iostream>
using namespace std;
void Test1()
{
	bite::vector<int> v1;
	bite::vector<int> v2(10, 5);

	bite::vector<int> v3(v2);
	for (size_t i = 0; i < v3.size(); ++i)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
	int arr[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v4(arr, arr + 5);
	auto it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	std::string s("wang");
	bite::vector<char> vc(s.begin(), s.end());
	for (auto e : vc)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test2()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.insert(v.begin(), 0);
	v.pop_back();
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.begin());
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//v.clear();
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;


	v.resize(10,5);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	cout << v.capacity() << endl;

	v.resize(20, 1);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

}



/*
namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}

		vector(int n, const T& data = T())
			: start(new T[n])
			, finish(start + n)
			, endofstorage(finish)
		{
			for (int i = 0; i < n; ++i)
			{
				start[i] = data;
			}
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			// ȷ�����������ж��ٸ�Ԫ��
			Iterator it = first;
			size_t count = 0;
			while (it != last)
			{
				count++;
				++it;
			}

			// ����ǰ���󿪱ٿռ䣬����ʼ����Ա����
			start = new T[count];
			finish = start;
			endofstorage = start + count;

			// ��ֵ
			while (first != last)
			{
				*finish++ = *first++;
			}
		}

		vector(const vector<T>& v)
		{
			size_t vsize = v.size();
			start = new T[vsize];
			finish = endofstorage = start + vsize;
			for (size_t i = 0; i < vsize; ++i)
				start[i] = v[i];
		}

		// �����Ҫ�Լ�ʵ�� ��ֵ���������&��������
		~vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = endofstorage = nullptr;
			}
		}

		///////////////////////////////
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		//////////////////////////////////
		// capacity
		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return endofstorage - start;
		}

		bool empty()const
		{
			return start == finish;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				finish = start + newsize;
			}
			else
			{
				if (newsize > capacity())
					reserve(newsize);

				for (size_t i = oldsize; i < newsize; ++i)
					start[i] = data;

				finish = start + newsize;
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			size_t oldsize = size();
			if (newcapacity > oldcapacity)
			{
				// �����¿ռ�
				T* temp = new T[newcapacity];

				// ����Ԫ��
				//memcpy(temp, start, oldsize*sizeof(T));
				for (size_t i = 0; i < oldsize; ++i)
					temp[i] = start[i];

				// �ͷžɿռ�
				delete[] start;

				start = temp;
				finish = start + oldsize;
				endofstorage = start + newcapacity;
			}
		}

		/////////////////////////////////////
		// acess
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return start[0];
		}

		const T& front()const
		{
			return start[0];
		}

		T& back()
		{
			return start[size() - 1];
		}

		const T& back()const
		{
			return start[size() - 1];
		}

		///////////////////////////////////////
		// modify
		void push_back(const T& data)
		{
			if (size() == capacity())
				reserve(capacity() * 2 + 3);

			*finish++ = data;
		}

		void pop_back()
		{
			if (empty())
				return;

			--finish;
		}

		iterator insert(iterator pos, const T& data)
		{
			assert(pos <= end());
			if (size() == capacity())
				reserve(capacity() * 2);

			auto it = end();
			while (it > pos)
			{
				*it = *(it - 1);
				--it;
			}

			*pos = data;
			++finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos < end());
			if (size() == 1)
			{
				pop_back();
				return end();
			}

			auto it = pos;
			while (it < end())
			{
				*it = *(it + 1);
				++it;
			}

			--finish;
			return pos;
		}

		void clear()
		{
			finish = start;
		}

		void swap(const vector<T>& v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(endofstorage, v.endofstorage);
		}

	private:
		iterator start;
		iterator finish;
		iterator endofstorage;
	};
}
*/



