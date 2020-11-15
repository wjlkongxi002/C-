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
		typedef ListIterator<T> Self;
	public:
		ListIterator(Node* ptr = nullptr)
			:_ptr(ptr)
		{}

		// ����ָ�����ƵĲ���
		T& operator*()
		{
			return _ptr->data;
		}

		T* operator->()
		{
			return &_ptr->data;
		}

		//////////////////////
		// ������Ҫ���ƶ�
		Self& operator++() // ����++
		{
			_ptr = _ptr->next;
			return *this;
		}

		Self operator++(int) // ǰ��++
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
		// ������Ҫ�ܽ��бȽ�
		bool operator!=(const Self& s)const
		{
			return _ptr != s._ptr;
		}

		bool operator==(const Self& s)const
		{
			return _ptr == s._ptr;
		}
	private:
		Node* _ptr;

	};


	template<class T>
	calss list
	{
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


