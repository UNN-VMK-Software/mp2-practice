#pragma once
 
#include <cstring>
#include <iostream>

using namespace std;

template <typename T>
class Monom {
	double cf; //коэффициент (может быть отрицательный)
	unsigned int abc; //степени x*100+y*10+z
public:
	Monom (int cval = 1, int ival = 0){
		cf = cval; abc = ival;
	};
	void SetCoeff(int cval) { cf = cval; }
	double GetCoeff(void) { return cf; }
	void SetIndex(int ival) { abc = ival; }
	unsigned int GetIndex(void) { return abc; }
	Monom& operator=(const Monom &m) {
		cf = m.cf; abc = m.abc;
		return *this;
	}
	int operator==(const Monom &m) {
		return (cf == m.cf) && (abc == m.abc);
	}
	int operator<(const Monom &m) {
		return abc<m.abc;
	}
};

template <typename T>
struct Link {
	T data;
	Link* pNext;
public:
	Link() {
		data = NULL;
		pNext = NULL;
	};
	Link(T val, Link* n){
		data = val;
		pNext = n;
	};
	~Link() {};
	Link(const Link<T> &node2){
		if (this != &node2){
			data = node2.data;
			pNext = node2.pNext;
		}
	};
	bool operator==(const Link<T> &node2) const {
		if (data != node2.data)
			return false;
		else return true;
	};
};

template <typename T>
struct RingList{
private:
	Link<T> *head, *current;
public:
	RingList() {
		head->data = NULL;
		head->pNext = head;
		current = head;
	};

	RingList(const RingList<T> &l1){
		if (l1.head->pNext != l1.head)
		{
			head->data = NULL;
			head->pNext = new Link<T>(l1.head->pNext->data,l1.head->pNext->pNext);
			current = head->pNext;
			Link<T> *tmp2 = l1.head->pNext->pNext;
			while (tmp2->data != NULL)
			{
				current->pNext = new Link<T>(tmp2->data, tmp2->pNext);
				current = current->pNext;
				tmp2 = tmp2->pNext;
			}
			current->pNext = head;
		}
		else {
			head->data = NULL;
			head->pNext = head;
			current = head;
		}
	};
	~RingList(){
		current = head->pNext;
		Link<T> *tmp2 = current;
		if (head->pNext!= head)
		{
			while (tmp2!=head)
			{
				tmp2 = current->next;
				delete current;
				current = tmp2;
			}
			delete current;
		}
		else
			delete head;
	};
	void Reset() { current = head; }
	bool IsEnded() {
		if (current->data == NULL)
			return true;
		else return false;
	};
	Link* GetNext() { current = current->pNext; }
	void InsertToTail(const T& d){
		current = head;
		if (head->pNext == head)
			head->pNext = new Link<T>(d, head);
		else
		{
			while (current->pNext!=head)
			{
				current = current->pNext;
			}
			current->pNext = new Link<T>(d, head);
		}
	}; // вставка в конец
	void Insert(const T& d) {
		Link *tmp;
		tmp = head;
		current = head->pNext;
		if (head->pNext== head)
			head->pNext = new Link<T>(d, head);
		else
		{
			while (current->data <= d )
			{
				tmp = tmp->pNext
				current = current->pNext;
			}
			tmp->pNext = new Link<T>(d, current);
		}
	}; // вставка в упорядоченный список
	void Delete(const T&d){
		Link *prev = head;
		current = head->pNext;
		if (current != head)
		{
			while ((current != head) && (current->data != d))
			{
				prev =current;
				current = current->pNext;
			}
			if (current != head)
			{
				prev->pNext = current->pNext;
				delete current;
			}
		}
	};
	void Sequencing() {
		RingList<T> tmp;
		Link*prev;
		current = head->pNext;
		T min = current->data;
		prev = head;
		while (current != prev) {
			while (current != head) {
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
	}; // упорядочивание
	RingList Merge(const RingList<T> &l1) {
		RingList<T> tmp;
		current = head->pNext;
		l1.current = l1.head->pNext;
		while ((current != head) && (l1.current != l1.head))
		{
			if (current > l1.current)
			{
				tmp.InsertToTail(current->data);
				current = current->pNext;
			}
			else
			{
				tmp.InsertToTail(l1.current->data);
				l1.current = l1.current->pNext;
			}
		}
		if (l1.current == l1.head)
		{
			while (current != head) {
				tmp.InsertToTail(current->data);
				current = current->pNext;
			}
		}
		if (current == head)
		{
			while (l1.current != l1.head) {
				tmp.InsertToTail(l1.current->data);
				l1.current = l1.current->pNext;
			}
		}
	}; // слияние 2-ух списков в 3-ий 
};