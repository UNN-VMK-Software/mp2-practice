#pragma once
#include "node.h"

template <class val>
class ringlist
{
	node<val>* head;
	node<val>* current;
	node<val>* tail;
public:
	ringlist();
	ringlist(const ringlist<val> &l);
	~ringlist();
	void cleanlist();
	void reset(); //current = head
	void gonext();
	bool isended(); // проверка на конец списка
	val getdata();
	node<val>* search(const val &d);
	void insert_to_tail(const val &d);//вставка в конец
	void insertup(const val &d);// вставка в упорядоченный список
	friend ostream & operator<<(ostream &out, const ringlist<val> &n)
	{
		node<val>* t = n.head->next;
		while (t != head)
		{
			out << t->data << " ";
		}
	}
};

template<class val>
inline ringlist<val>::ringlist()
{
	head = new node<val>();
	tail = head;
	head->next = head;
}

template<class val>
inline ringlist<val>::ringlist(const ringlist<val>& l)
{
	head = new node<val>();
	node<val>* t = head;
	node<val>* tt = l.head->next;
	while (tt != l.head)
	{
		t->next = new node<val>(tt->data);
		t = t->next;
		tt = tt->next;
	}
	tail = t;
	tail->next = head;
}

template<class val>
inline ringlist<val>::~ringlist()
{
	cleanlist();
}

template<class val>
inline void ringlist<val>::cleanlist()
{
	node<val>* t = head->next;
	while (t != head)
	{
		node<val>* tt = t->next;
		delete t;
		t = tt;
	}
	delete head;
	head = NULL;
	tail = NULL;
}

template<class val>
inline void ringlist<val>::reset()
{
	current = head;
}

template<class val>
inline void ringlist<val>::gonext()
{
	current = current->next;
}

template<class val>
inline bool ringlist<val>::isended()
{
	return (current == head); //
}

template<class val>
inline val ringlist<val>::getdata()
{
	return current->data;
}

template<class val>
inline node<val>* ringlist<val>::search(const val & d)
{
	node<val>* t = head->next;
	while ((t != head) && (t->data != d))
	{
		t = t->next;
	}
	if (t == head)
		return NULL;
	else
		return t;
}

template<class val>
inline void ringlist<val>::insert_to_tail(const val & d)
{
	node<val>* t = new node<val>(d);
	tail->next = t;
	t->next = head;
	tail = t;
}

template<class val>
inline void ringlist<val>::insertup(const val & d)
{
	node<val>* t = new node<val>(d);
	node<val>* tt = head->next;
	node<val>* pred = head;
	while ((tt != head) && (tt->data > t->data))
	{
		pred = tt;
		tt = tt->next;
	}
	pred->next = t;
	t->next = tt;
	if (tt == head)
	{
		tail = t;
	}
}
