#pragma once

#include <string>
#include <cstdlib>
#include  <cctype>
#include <iostream>

using namespace std;

class Monom {
	double cf; //коэффициент (может быть отрицательный)
	unsigned int abc; //степени x*100+y*10+z
public:
	Monom();
	Monom(double d, unsigned int st);
	void SetCoeff(double cval) { cf = cval; }
	double GetCoeff(void) { return cf; }
	void SetIndex(int ival) { abc = ival; }
	unsigned int GetIndex(void) { return abc; }
	Monom& operator=(const Monom &m);
	Monom& operator+(const Monom &m);
	Monom& operator*(const double &d);
	Monom& operator*(const Monom &m);
	int operator==(const Monom &m);
	int operator!=(const Monom &m);
	int operator<(const Monom &m);
	friend ostream& operator<<(ostream& os, const Monom& m) {
		Monom Mon;
		int stx = (int)Mon.abc / 100;
		int sty = (int)(Mon.abc / 10 - stx * 10);
		int stz = (int)(Mon.abc % 10);
		cout << Mon.cf << 'x^' << stx << 'y^' << sty << 'z^' << stz;
		return os;
	}
};

template <class T>
struct Link {
	T data;
	Link* pNext;
public:
	Link();
	Link(T val, Link* n);
	~Link(){};
	Link(const Link<T> &node2);
	bool operator==(const Link<T> &node2);
	bool operator!=(const Link<T> &node2) { return !(*this == node2); }
};

template <class T>
struct RingList {
private:
	Link<T> *head, *current;
public:
	RingList();
	RingList(const RingList<T> &l1);
	~RingList();
	void Clean();
	T& GetValue() { return current->data; }
	RingList<T> operator=(const RingList<T> &l1);
	void Reset() { current = head; }
	bool IsEnded();
	Link<T>* GetNext() { current = current->pNext; return current; }
	void InsertToTail(const T& d); // вставка в конец
	void Insert(const T& d); // вставка в упорядоченный список
	void Delete(const T&d);
	void Sequencing(); // упорядочивание
	friend ostream& operator<<(ostream& os, const RingList<T>& l);
};

template <class T>
Link<T>::Link() {
	pNext = NULL;
}

template <class T>
Link<T>::Link(T val, Link* n) {
	data = val;
	pNext = n;
}

template <class T>
Link<T>::Link(const Link<T> &node2) {
	if (this != &node2) {
		data = node2.data;
		pNext = node2.pNext;
	}
}

template <class T>
bool Link<T>::operator==(const Link<T> &node2) {
	if (data != node2.data)
		return false;
	else return true;
}


template <class T>
RingList<T>::RingList() {
	head = new Link<T>;
	head->pNext = head;
	current = head;
}

template <class T>
RingList<T>::RingList(const RingList<T> &l1) {
	if (l1.head->pNext != l1.head)
	{
		head = new Link<T>;
		current = head;
		Link<T> *tmp2 = l1.head->pNext;
		while (tmp2 != l1.head)
		{
			current->pNext = new Link<T>(tmp2->data, tmp2->pNext);
			current = current->pNext;
			tmp2 = tmp2->pNext;
		}
		current->pNext = head;
	}
	else {
		head = new Link<T>;
		head->pNext = head;
		current = head;
	}
}

template <class T>
RingList<T>::~RingList() {
	current = head->pNext;
	Link<T> *tmp2 = current;
	if (head->pNext != head)
	{
		while (tmp2 != head)
		{
			tmp2 = current->pNext;
			delete current;
			current = tmp2;
		}
		delete current;
	}
	else
		delete head;
}

template <class T>
bool RingList<T>::IsEnded() {
	if (current == head)
		return true;
	else return false;
}

template <class T>
void RingList<T>::InsertToTail(const T& d) {
	current = head;
	if (head->pNext == head)
		head->pNext = new Link<T>(d, head);
	else
	{
		while (current->pNext != head)
		{
			current = current->pNext;
		}
		current->pNext = new Link<T>(d, head);
	}
}

template <class T>
void RingList<T>::Insert(const T& d) {
	Link<T> *tmp;
	tmp = head;
	current = head->pNext;
	if (head->pNext == head)
		head->pNext = new Link<T>(d, head);
	else
	{
		while (current->data < d)
		{
			tmp = tmp->pNext;
				current = current->pNext;
		}
		if (current->data == d) {
			current->data = current->data + d;
		}
		else {
			tmp->pNext = new Link<T>(d, current);
		}
	}
}

template <class T>
void RingList<T>::Delete(const T&d) {
	Link<T> *prev = head;
	current = head->pNext;
	if (current != head)
	{
		while ((current != head) && (current->data != d))
		{
			prev = current;
			current = current->pNext;
		}
		if (current != head)
		{
			prev->pNext = current->pNext;
			delete current;
		}
	}
}

template <class T>
void RingList<T>::Sequencing() {
	RingList<T> tmp;
	Link<T>*prev;
	current = head->pNext;
	T min = current->data;
	prev = head;
	while (current != prev) {
		while (!IsEnded()) {
			if (current->data < min)
				min = current->data;
			prev = current;
			current = current->pNext;
		}
		tmp.InsertToTail(min);
		Delete(min);
		prev = head;
		current = head->pNext;
	}
	head = tmp.head;
}


template <class T>
RingList<T> RingList<T>::operator=(const RingList<T> &l1) {
	if (this != &l1) {
		Clean();
		if (l1.head->pNext == l1.head) {
			return *this;
		}
		else {
			Link<T> *tmp2 = l1.head->pNext;
			current = head;
			while (tmp2!=l1.head)
			{
				current->pNext = new Link<T>(tmp2->data, tmp2->pNext);
				current = current->pNext;
				tmp2 = tmp2->pNext;
			}
			current->pNext = head;
		}
	}
	return *this;
}

template <class T>
void RingList<T>::Clean() {
	current = head->pNext;
	Link<T> *tmp2 = current;
	if (head->pNext != head)
	{
		while (!IsEnded())
		{
			tmp2 = GetNext();
			delete current;
			current = tmp2;
		}
		head->pNext = head;
		current = head;
	}
	else return;
}

template <class T>
ostream& operator<<(ostream& os, const RingList<T>& l)
{
	RingList<T> list;
	list.Reset();
	Link<T> *tmp = list.GetNext();
	while (!list.IsEnded())
	{
		cout << tmp->data << "+";
		tmp = list.GetNext();
	}
	cout << endl;
	return os;

}
