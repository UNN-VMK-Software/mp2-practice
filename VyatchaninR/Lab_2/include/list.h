#pragma once
#include "Table.h"

template <class DT>
class node
{
public:
	DT data;
	node* next;
	node(DT d, node<DT>* n) { data = d; next = n; }
	node(const node<DT>& node2) { data = node2.data; next = NULL; }
	bool operator==(const node<DT>& node2) const
	{
		int i = 0;
		if (data != node2.data)
			i++;
		if (next != node2.next)
			i++;
		if (i == 0)
			return true;
		else
			return false;
	}
	bool operator!=(const node<DT>& node2)const { return !(*this == node2); }
};

template <class DT>
class List
{
	// любые поля
	node<DT>* head;
	node<DT>*curr;
public:
	List() { head = NULL; }
	List(const List<DT>& list2);
	List<DT>& operator=(const List<DT>& list2);
	~List();

	void InsertToHead(const DT& d); // вставить элемент d первым
	void InsertToTail(const DT& d); // вставить элемент d последним
	void InsertAfter(node<DT>* node, const DT& d); // вставить элемент d после звена node
	void Delete(const DT& d); // удалить звено со значением data = d
	node<DT>* Search(const DT& d); // найти указатель на звено со значением data = d
	void Clean(); // удалить все звенья
	bool Empty() { return head == NULL; }
	bool End() { return curr->next == NULL; }
	void First() { curr = head; }
	void Next() { curr = curr->next; }
	node<DT>* GetHead()const { return head; } // получить указатель на первое звено списка
	node<DT>* GetCurr() { return curr; }
	int GetSize();
	void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
	List<DT> Merge(node<DT>* node, const List<DT>& list2); // создать список3, добавив список2 в текущий список после указателя node  
	List<DT> Merge(const List<DT>& list2); // создать список3, добавив в конец текущего списка список2
	bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

template<class DT>
inline List<DT>::List(const List<DT>& list2)
{
	if (list2.head != NULL)
	{
		head = new node<DT>(list2.head->data, list2.head);
		node<DT>*tmp = head;
		node<DT>*tmp2 = list2.head->next;
		while (tmp2 != NULL)
		{
			tmp->next = new node<DT>(tmp2->data, tmp2->next);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}
	else
	{
		head = list2.head;
	}
}

template<class DT>
inline List<DT>& List<DT>::operator=(const List<DT>& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head != NULL)
		{
			head = new node<DT>(list2.head->data, list2.head);
			node<DT>*tmp = head;
			node<DT>*tmp2 = list2.head->next;
			while (tmp2 != NULL)
			{
				tmp->next = new node<DT>(tmp2->data, tmp2->next);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
	}
	return*this;
}

template<class DT>
inline List<DT>::~List()
{
	node<DT>*tmp = head;
	if (head != NULL)
	{
		node<DT>*tmp2 = tmp->next;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp2 = tmp->next;
				delete tmp;
				tmp = tmp2;
			}
			delete tmp;
		}
	}
}

template<class DT>
void List<DT>::InsertToHead(const DT & d)
{
	if (head == NULL)
	{
		head = new node<DT>(d, NULL);
	}
	else
	{
		node<DT>* tmp = new node<DT>(d, head);
		this->head = tmp;
	}
}

template<class DT>
void List<DT>::InsertToTail(const DT & d)
{
	if (head == NULL)
	{
		head = new node<DT>(d, NULL);
	}
	else
	{
		node<DT>*tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new node<DT>(d, NULL);
	}
}

template<class DT>
void List<DT>::InsertAfter(node<DT>* node, const DT& d)
{
	if (head == NULL)
		throw"Head NULL";
	if (node != NULL)
	{
		node<DT>*n = new node<DT>(d, node->next);
		node->next = n;
	}
}

template<class DT>
inline void List<DT>::Delete(const DT & d)
{
	node<DT>*tmp = head, *prev = head;
	if (tmp != NULL)
	{
		while ((tmp->next != NULL) && (tmp->data != d))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp->data == d)
		{
			prev->next = tmp->next;
			if (tmp == head)
				head = head->next;
			delete tmp;
		}
	}
}

template<class DT>
inline node<DT>* List<DT>::Search(const DT & d)
{
	node<DT>*tmp = head;
	if (tmp != NULL)
	{
		while ((tmp->next != NULL) && (tmp->data != d))
		{
			tmp = tmp->next;
		}
		if (tmp->data == d)
			return tmp;
		else
			return NULL;
	}
	else
		return NULL;
}

template<class DT>
inline void List<DT>::Clean()
{
	node<DT>*tmp = head;
	node<DT>*tmp2 = head;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
		delete tmp;
		head = NULL;
	}
}

template<class DT>
inline int List<DT>::GetSize()
{
	node<DT>*tmp = head;
	int k = 0;;
	if (head == NULL)
		return k;
	while (tmp != NULL)
	{
		k++;
		tmp = tmp->next;
	}
	return k;
}

template<class DT>
inline void List<DT>::Inverse()
{
	if (head != NULL)
	{
		node<DT>*tmp, *tmp2, *tmp3;
		tmp = head;
		tmp2 = NULL;
		tmp3 = head->next;
		if ((tmp != NULL) && (tmp->next != NULL))
		{
			do
			{
				tmp3 = tmp->next;
				tmp->next = tmp2;
				tmp2 = tmp;
				tmp = tmp3;
			} while (tmp != NULL);
			head = tmp2;
		}
	}
	else
		head = NULL;
}

template<class DT>
inline List<DT> List<DT>::Merge(node<DT>* node, const List<DT>& list2)
{
	if (node == NULL)
		return *this;
	if ((head == NULL) || (head == node))
	{
		List<DT> list;
		node<DT>* tmp = list2.head;

		while (tmp != NULL)
		{
			list.InsertToTail(tmp->data);
			tmp = tmp->next;
		}
		return list;
	}
	else
	{
		List<DT> list;
		node<DT>* tmp = head;

		while (tmp != node)
		{
			list.InsertToTail(tmp->data);
			tmp = tmp->next;
		}

		if (tmp != NULL)
		{
			list.InsertToTail(tmp->data);
			node<DT>* tmp2 = tmp->next;
			tmp = list2.head;

			while (tmp != NULL)
			{
				list.InsertToTail(tmp->data);
				tmp = tmp->next;
			}

			tmp = tmp2;
			while (tmp != NULL)
			{
				list.InsertToTail(tmp->data);
				tmp = tmp->next;
			}
			return list;
		}
		else
		{
			node<DT>* tmp2 = tmp;
			tmp = list2.head;

			while (tmp != NULL)
			{
				list.InsertToTail(tmp->data);
				tmp = tmp->next;
			}
			return list;
		}
	}
}

template<class DT>
inline List<DT> List<DT>::Merge(const List<DT>& list2)
{
	if (head != NULL)
	{
		if (list2.head == NULL)
			return *this;
		List<DT> list(*this);
		node<DT>* tmp = list.head;
		node<DT>*tmp2 = list2.head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(list2.head->data, NULL);
		tmp = tmp->next;
		tmp2 = tmp2->next;
		while (tmp2)
		{
			tmp->next = new Node(tmp2->data, NULL);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		return list;
	}
	else
	{
		List<DT> list3(list2);
		return list3;
	}
}

template<class DT>
inline bool List<DT>::operator==(const List & list2) const
{
	node<DT>*tmp = head;
	node<DT>*tmp2 = list2.head;
	bool k = true;
	while ((tmp != NULL) && (tmp2 != NULL) && (k))
	{
		if (tmp->data != tmp2->data)
			k = false;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if ((tmp != NULL) || (tmp2 != NULL))
		k = false;
	return k;
}