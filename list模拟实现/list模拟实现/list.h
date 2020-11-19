#pragma once

namespace bite
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& value = T())
		:next(nullptr)
		, prev(nullptr)
		, data(value)
		{}

		ListNode<T>* next;
		ListNode<T>* prev;
		T data;
	};

	template<class T>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> Self; // list迭代器
	public:
		ListIterator(Node* ptr = nullptr)
			:_ptr(ptr)
		{} // 初始化

		// 具有指针类似的操作
		T& operator*()
		{
			return _ptr->data;
		}

		T* operator->()
		{
			return &_ptr->data;
		}

		//////////////////////
		// 迭代器要能移动
		Self& operator++() // 前置++
		{
			_ptr = _ptr->next;
			return *this;
		}

		Self operator++(int) // 后置++
		{
			Self temp(*this);
			_ptr = _ptr->next;
			return temp;
		}

		Self& operator--()
		{
			_ptr = _ptr->prev;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_ptr = _ptr->prev;
			return temp;
		}
		////////////////////////////
		// 迭代器要能进行比较
		bool operator!=(const Self& s)const
		{
			return _ptr != s._ptr;
		}

		bool operator==(const Self& s)const
		{
			return _ptr == s._ptr;
		}

		Node* _ptr;

	};

	// 反向迭代器，直接将正向迭代器进行封装
	template<class T, class Iterator>
	class ListReverseIterator
	{
		typedef ListNode<T> Node;
		typedef ListReverseIterator<T, Iterator> Self;
	public:
		ListReverseIterator(Node* pNode = nullptr)
			: _it(pNode)
		{}

		ListReverseIterator(Iterator it)
			:_it(it)
		{}

		T& operator*()
		{
			Iterator temp(_it); // 创建一个临时变量temp
			--temp;
			return *temp;
		}

		T* operator->()
		{
			return &(*_it);
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			_it++;
			return *this;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			_it++;
			return *this;
		}

		bool operator != (const Self& s)
		{
			return _it != s._it;
		}

		bool operator == (const Self& s)
		{
			return _it == s._it;
		}

	private:
		Iterator _it;

	};


	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T> iterator;
		typedef ListReverseIterator<T, iterator> reverse_iterator;
	public:
		list()
		{
			CreateHead();
		}

		list(int n, const T& data)
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(data);
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(list<T>& L)
		{
			CreateHead();
			auto it = L.begin();
			while (it != L.end())
			{
				push_back(*it);
				++it;
			}
		}

		~list()
		{
			clear();
			delete head;
			head = nullptr;
		}

		///////////////////////////
		//iterator
		iterator begin()
		{
			// 构造一个匿名对象返回了
			return iterator(head->next);
		}

		iterator end()
		{
			return iterator(head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		/////////////////////////////////////
		//capacity
		size_t size()const
		{
			size_t count = 0;
			Node* pCur = head->next;
			while (pCur != head)
			{
				++count;
				pCur = pCur->next;
			}
			return count;
		}
		bool empty()
		{
			return head->next == head;
		}



		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
			else
			{
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
			}
		}

		/////////////////////////////////
		// access
		T& front()
		{
			return *begin();
		}
		const T& front()const
		{
			return *begin();
		}

		T& back()
		{
			return head->prev->data;
		}
		const T& baack()const
		{
			return head->prev->data;
		}

		////////////////////////////////////////
		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			erase(--end());
		}

		iterator insert(iterator pos, const T& data) // 任意位置的插入
		{
			Node* newnode = new Node(data);
			pos._ptr->prev->next = newnode;
			newnode->next = pos._ptr;
			newnode->prev = pos._ptr->prev;
			pos._ptr->prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos) // 任意位置的删除
		{
			Node* posnode = pos._ptr;
			if (posnode != head)
			{
              posnode->prev->next = posnode->next;
			  posnode->next->prev = posnode->prev;
			}
			
			return iterator(posnode->next);
		}

		iterator erase(iterator first, iterator last)  // 区间删除
		{
			while (first != last)
			{
				first = erase(first);
			}
			return end();

		}

		void clear()
		{
			erase(begin(), end());
		}

		void swap(const list<T>& L)
		{
			std::swap(head, L.head);
		}

	private:
		void CreateHead()
		{
			head = new Node;
			head->next = head;
			head->prev = head;
		}
	private:
		ListNode<T>* head;
	};

}


#include <iostream>
using namespace std;

void Test1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);
	cout << L2.size() << endl;
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L3(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;

	bite::list<int> L4(L3);
}

void Test2()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	auto it = L.rbegin();
	while (it != L.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	L.resize(10, 6);
	cout << L.size() << endl;

	L.resize(3);
	cout << L.size() << endl;

}
