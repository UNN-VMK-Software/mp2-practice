#pragma once

#include <iostream>
using namespace std;


template <class DataType>
struct Node
{
	DataType data;
	Node* next;

	Node(DataType d = 0, Node<DataType>* n = nullptr) { data = d; next = n; }
	Node(const Node<DataType>& node2) { data = node2.data; next = nullptr; }
	bool operator==(const Node<DataType>& node2) const { if (data == node2.data && next == node2.next) return true; else return false; }
	~Node() {}
};


template <class DataType>
class List
{
	// любые поля
	Node<DataType>* head;
	Node<DataType>* cur;
public:
	List() { head = nullptr; }
	List(const List<DataType>& list2);
	List<DataType>& operator=(const List<DataType>& list2);
	~List() { Clean(); }

	void InsertToHead(const DataType& d);                                        // вставить элемент d первым
	void InsertToTail(const DataType& d);                                        // вставить элемент d последним
	void InsertAfter(Node<DataType>* node, const DataType& d);                   // вставить элемент d после звена node
	void Delete(const DataType& d);                                              // удалить звено со значением data = d
	Node<DataType>* Search(const DataType& d);                                   // найти указатель на звено со значением data = d
	void Clean();                                                                // удалить все звенья
	int GetSize();                                                               // узнать число звеньев в списке
	Node<DataType>* GetHead() { return head; }                                   // получить указатель на первое звено списка
	void Inverse();                                                              // инвертировать список, т.е. звенья должны идти в обратном порядке
	List<DataType> Merge(Node<DataType>* node, const List& list2);               // создать список3, добавив список2 в текущий список после указателя node  
	List<DataType> Merge(const List<DataType>& list2);                           // создать список3, добавив в конец текущего списка список2

	friend ostream& operator<<(ostream& os, const List& l);
	bool operator==(const List& list2) const;                                    // списки равны, если элементы в них идут в одинаковом порядке

	bool IsEmpty() const { return head == nullptr; }
	void Reset() { cur = head; }
	void GetNext() { cur = cur->next; }
	bool IsEnded() const { return cur == nullptr; } //
	Node<DataType>* GetCur() { return cur; }

};

template <class DataType>
List<DataType>::List(const List<DataType>& list2)
{
	if (list2.head)
	{
		head = new Node<DataType>(list2.head->data, list2.head);
		Node<DataType> *u = head;
		Node<DataType> *u2 = list2.head->next;
		while (u2 != nullptr)
		{
			u->next = new Node<DataType>(u2->data, u2->next);
			u = u->next;
			u2 = u2->next;
		}
	}
	else
		head = list2.head;;
}

template <class DataType>
List<DataType>& List<DataType>:: operator=(const List<DataType>& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head)
		{
			head = new Node<DataType>(list2.head->data, list2.head);
			Node<DataType> *u = head;
			Node<DataType> *u1 = list2.head->next;
			while (u1)
			{
				u->next = new Node<DataType>(u1->data);
				u = u->next;
				u1 = u1->next;
			}
		}
		else
		{
			Clean();
			head = list2.head;
		}
	}
	return *this;
}

template <class DataType>
void List<DataType>::InsertToHead(const DataType& d)
{
	if (head != nullptr)
	{
		Node<DataType>* u = new Node<DataType>(d, head);
		head = u;
	}
	else
		head = new Node<DataType>(d, nullptr);
}

template <class DataType>
void List<DataType>::InsertToTail(const DataType& d)
{
	Node<DataType>*u = head;
	if (u)
	{
		while (u->next)
			u = u->next;
		u->next = new Node<DataType>(d);
	}
	else
		head = new Node<DataType>(d, nullptr);
}

template <class DataType>
void List<DataType>::InsertAfter(Node<DataType>* node, const DataType& d)
{
	if (node && head)
	{
		Node<DataType>* u = node->next;
		node->next = new Node<DataType>(d, u);
	}
	else
		if (head == nullptr)
			throw 1;
}

template <class DataType>
void List<DataType>::Delete(const DataType& d)
{
	Node<DataType>* u = head;
	Node<DataType>* u2 = u;
	if (u)
	{
		while ((u->next) && (u->data != d))
		{
			u2 = u;
			u = u->next;
		}

		if (u->data == d)
		{
			u2->next = u->next;
			if (u == head)
				head = head->next;
			delete u;
		}
	}
}

template <class DataType>
Node<DataType>* List<DataType>::Search(const DataType& d)
{
	Node<DataType>* u = head;
	while (u)
	{
		if (u->data == d)
			return u;
		u = u->next;
	}
	return nullptr;
}

template <class DataType>
void List<DataType>::Clean()
{
	Node<DataType>* u = head;
	Node<DataType>* u2;
	if (u != nullptr)
	{
		while (u->next != nullptr)
		{
			u2 = u->next;
			delete u;
			u = u2;
		}
		delete u;
		head = nullptr;
	}
}

template <class DataType>
int List<DataType>::GetSize()
{
	int res = 0;
	Node<DataType>* u = head;
	while (u)
	{
		res++;
		u = u->next;
	}
	return res;
}

template <class DataType>
void List<DataType>::Inverse()
{
	if (head)
	{
		Node<DataType>* u = head->next;
		head->next = nullptr;
		Node<DataType>* u2 = head;
		Node<DataType>* u3;
		while (u)
		{
			u3 = u->next;
			u->next = u2;
			u2 = u;
			u = u3;
		}
		head = u2;
	}
	else
		head = nullptr;
}

template <class DataType>
List<DataType> List<DataType>::Merge(Node<DataType>* node, const List<DataType>& list2)
{
	List res;
	Node<DataType>* u = head;
	if (head)
	{
		res.head = new Node<DataType>(head->data);
		Node<DataType>* u1 = res.head;
		while (u->next && u != node)
		{
			u1->next = new Node<DataType>(u->next->data);
			u = u->next;
			u1 = u1->next;
		}
		if (u == node)
		{
			if (list2.head)
			{
				Node<DataType>* u2 = list2.head;
				while (u2)
				{
					u1->next = new Node<DataType>(u2->data);
					u2 = u2->next;
					u1 = u1->next;
				}
			}
			while (u->next)
			{
				u1->next = new Node<DataType>(u->next->data);
				u = u->next;
				u1 = u1->next;
			}
		}
		u1->next = nullptr;
	}
	return res;
}

template <class DataType>
List<DataType> List<DataType>::Merge(const List<DataType>& list2)
{
	List res(*this);
	if (res.head && list2.head)
	{
		Node<DataType>* u = res.head;
		while (u->next)
			u = u->next;
		Node<DataType>* u1 = list2.head;
		while (u1)
		{
			u->next = new Node<DataType>(u1->data);
			u = u->next;
			u1 = u1->next;
		}
		u->next = nullptr;
	}
	else
		if (!(res.head))
			res = List(list2);
	return res;
}

template <class DataType>
ostream& operator<<(ostream& os, const List<DataType>& l)
{
	Node<DataType>* u = l.head;
	while (u)
	{
		os << u->data << " ";
		u = u->next;
	}
	return os;
}

template <class DataType>
bool List<DataType>:: operator==(const List<DataType>& list2) const
{
	Node<DataType>* u = head;
	Node<DataType>* u1 = list2.head;
	bool res = true;

	if ((u && !u1) || (!u && u1))
		res = false;
	if (res)
	{
		while (u && u1)
		{
			if (u->data != u1->data)
			{
				res = false;
				u = u->next;
				u1 = u1->next;
			}
			else
			{
				u = u->next;
				u1 = u1->next;
			}
		}
	}
	return res;
}

