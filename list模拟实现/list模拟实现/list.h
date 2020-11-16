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


	template<class T, class Iterator>
	class ListReverseIterator
	{
		typedef ListNode<T> Node;
		typedef ListReverseIterator<T, Iterator> Self;
	public:
		ListReverseIterator(Node* pNode = nullptr)
			: _it(pNode)
		{}

		ListReverseIterator(Itertor it)
			:_it(it)
		{}

		T& operator*()
		{
			Itrator temp(_it);
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
		typedef LisIterator<T> iterator;
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
			suto it = L.begin();
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
			return reserve_iterator(begin());
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

		iterator insert(iterator pos, const T& data)
		{
			Node* newnode = new Node(data);
		
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


