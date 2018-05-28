#pragma once
#include "node.h"

template <class T>
class TRinglist
{
private:
	Node<T>* head;
	Node<T>* curr; //ходилка
	Node<T>* tail; //указатель на последний эл-т спика
public:
	TRinglist();
	TRinglist(const TRinglist<T> &l);
	~TRinglist();
	void Clean(); //очистить список
	void Reset(); //curr станет head
	void Getnext(); //curr перейдет на следующий
	bool Isended() const; //дошли ли до конца?
	void del(Node<T> *l); ////////////////////////
	T & Getdata() const; //вернет данные у curr
	Node<T>* search(const T &d);
	void Insert_to_tail(const T &d); //вставка в конец
	void Insert_Up(const T &d); //вставка в упорядоченный список
	bool operator==(const TRinglist<T> &l) const; //сравнение списков
	const TRinglist<T> & operator=(const TRinglist<T> &l);/////////
	friend ostream& operator<<(ostream &out, const TRinglist<T> &n)
	{
		Node<T>* t = n.head->next;
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

template<class T> 
inline TRinglist<T>::TRinglist() 
{ 
	head = new Node<T>(); 
	tail = head; 
	head->next = head; 
} 

template<class T> 
inline TRinglist<T>::TRinglist(const TRinglist<T>& l) 
{ 
	head = new Node<T>(); 
	Node<T>* t = head; 
	Node<T>* tt = l.head->next; 
	while (tt != l.head) 
	{ 
		t->next = new Node<T>(tt->data); 
		tail = t->next; /////////
		t = t->next; 
		tt = tt->next; 
	} 
	tail->next = head; 
} 

template<class T> 
inline TRinglist<T>::~TRinglist() 
{ 
	Clean(); 
	delete head; //////////
} 

template<class T> 
inline void TRinglist<T>::Clean() 
{ 
	Node<T>* t = head->next; 
	while (t != head) 
	{ 
		Node<T>* tt = t->next; 
		delete t; 
		t = tt; 
	} 
	head->next = head; ////// 
	tail = head; ///////
} 

template<class T>  ////////////////////////////
inline void TRinglist<T>::del(Node<T> *l) 
{
	Node<T> *t = head;
	while(t->next != l)
		t = t->next;
	t->next = l->next;
	delete l;
}

template<class T> 
inline void TRinglist<T>::Reset() 
{ 
	curr = head; 
} 

template<class T> 
inline void TRinglist<T>::Getnext() 
{ 
	curr = curr->next; 
} 

template<class T> 
inline bool TRinglist<T>::Isended() const 
{ 
	return (curr == head); 
} 

template<class T> 
inline T & TRinglist<T>::Getdata() const
{ 
	return curr->data; 
} 

template<class T> 
inline Node<T>* TRinglist<T>::search(const T &d) 
{ 
	Node<T>* t = head->next; 
	while ((t != head) && (t->data != d)) 
	{ 
		t = t->next; 
	} 
	if (t == head) 
		return NULL; 
	else 
		return t; 
} 

template<class T> 
inline void TRinglist<T>::Insert_to_tail(const T & d) 
{ 
	Node<T>* t = new Node<T>(d); 
	tail->next = t;
	tail = t;
	tail->next = head;; 
} 

template<class T> 
inline void TRinglist<T>::Insert_Up(const T & d) 
{ 
	Node<T>* t = new Node<T>(d); 
	Node<T>* tt = head->next; 
	Node<T>* pred = head; 
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

template<class T>
inline bool TRinglist<T>::operator==(const TRinglist<T> &l) const
{
	bool flag = true;
	if (this != &l)
	{
		Node<T>* t = head->next;
		Node<T>* tt = l.head->next;
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

template<class T>
const TRinglist<T> & TRinglist<T>::operator=(const TRinglist<T> &l)
{
	Clean();
	head = new Node<T>();
	Node<T>* t = head;
	Node<T>* tt = l.head->next;
	tail = head;
	while(tt != l.head)
	{
		t->next = new Node<T>(tt->data);
		tail = t->next;
		t = t->next;
		tt = tt->next;
	}
	tail->next = head;
	return *this;
}
