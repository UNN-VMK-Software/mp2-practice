#pragma once
#include "node.h"

template <class val>
class ringlist
{
private:
	node<val>* head;
	node<val>* current; //текущий элемент
	node<val>* tail; 
public:
	ringlist();
	ringlist(const ringlist<val> &l);
	~ringlist();
	void clean(); //очистить список
	void reset(); //current = head
	void getnext(); //current перейдет на следующий
	bool isended() const; //проверка на конец
	void delet(node<val> *l); 
	val & getdata() const; 
	node<val>* search(const val &d);
	void insert_to_tail(const val &d); //вставка в конец
	void insert_up(const val &d); //вставка в упорядоченный список
	bool operator==(const ringlist<val> &l) const; //сравнение списков
	const ringlist<val> & operator=(const ringlist<val> &l);
	friend ostream& operator<<(ostream &out, const ringlist<val> &n)
	{
		node<val>* t = n.head->next;
		if (t == n.head)
			out << "0";     
		while (t != n.head)
		{
			out << t->data << " ";
			t = t->next;
		}
		return out;
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
		tail = t->next; 
		t = t->next;
		tt = tt->next;
	}
	tail->next = head;
}

template<class val>
inline ringlist<val>::~ringlist()
{
	clean();
	delete head; 
}

template<class val>
inline void ringlist<val>::clean()
{
	node<val>* t = head->next;
	while (t != head)
	{
		node<val>* tt = t->next;
		delete t;
		t = tt;
	}
	head->next = head; 
	tail = head; 
}

template<class val>  
inline void ringlist<val>::delet(node<val> *l)//удаление звена списка
{
	node<val> *t = head;
	while (t->next != l)
		t = t->next;
	t->next = l->next;
	delete l;
}

template<class val>
inline void ringlist<val>::reset()
{
	current = head;
}

template<class val>
inline void ringlist<val>::getnext()
{
	current = current->next;
}

template<class val>
inline bool ringlist<val>::isended() const
{
	return (current == head);
}

template<class val>
inline val & ringlist<val>::getdata() const
{
	return current->data;
}

template<class val>
inline node<val>* ringlist<val>::search(const val &d)//поиск звена с даными d
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
	tail = t;
	tail->next = head;;
}

template<class val>
inline void ringlist<val>::insert_up(const val & d)
{
	node<val>* t = new node<val>(d);
	node<val>* tt = head->next;
	node<val>* pred = head;
	while ((tt != head) && (tt->data > d))
	{
		pred = tt;
		tt = tt->next;
	}
	t->next = tt;
	pred->next = t;
	if (tt == head)
	{
		tail = t;
	}
}

template<class val>
inline bool ringlist<val>::operator==(const ringlist<val> &l) const
{
	bool flag = true;
	if (this != &l)
	{
		node<val>* t = head->next;
		node<val>* tt = l.head->next;
		while (t->data == tt->data && t != head && tt != l.head)
		{
			t = t->next;
			tt = tt->next;
		}
		if (t != head || tt != l.head)
			flag = false;
	}
	return flag;
}

template<class val>
const ringlist<val> & ringlist<val>::operator=(const ringlist<val> &l)
{
	clean();
	head = new node<val>();
	node<val>* t = head;
	node<val>* tt = l.head->next;
	tail = head;
	while (tt != l.head)
	{
		t->next = new node<val>(tt->data);
		tail = t->next;
		t = t->next;
		tt = tt->next;
	}
	tail->next = head;
	return *this;
}







