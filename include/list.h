#pragma once
#include "node.h"
template <typename T>
class list {
private:
	node<T>* ptr;
	node<T>* Head;
public:
	list();
	list(const list<T> &list2);      //конструктор копирования
	bool IsEmpty();
	void Insert_to_tail(const T con);
	void Insert_to_tail(const node<T>* con);
	void Insert_after(const node<T>* con,T A);

};

template <typename T>
list<T>::list() {
	Head = NULL;
	ptr = NULL;
}
template <typename T>
bool list<T>::IsEmpty() {
	if (Head == NULL) return true; else return false;
}
template <typename T>
void list<T>::Insert_to_tail(const node<T>* con) {
	if (Head == NULL) {
		Head = new node<T>(con);
		Head->next = Head;
	}
	else {
		ptr->next = new node<T>(con->date, Head);
		ptr = ptr->next;
	}
}
template <typename T>
void list<T>::Insert_to_tail(const T con) {
	if (Head == NULL) {
		Head = new node<T>(con);
		Head->next = Head;
		ptr = Head;
	}
	else {
		ptr->next = new node<T>(con, Head);
		ptr = ptr->next;
	}
}

template <typename T>
void list<T>::Insert_after(const node<T>* con, T A) {
	if (Head == NULL) {
		throw "netu";
	}
	else {
		node<T>* ptr = Head;
		while ((ptr != con) && (ptr->next != Head)) ptr = ptr->next;
		if (ptr = con) {
			node<T>* ptr2 = ptr->next;
			ptr->next = new node<T>(A, ptr2);
		}
		else throw "netu";
	}
}

template <typename T>
list<T>::list(const list<T> &list2) {
	if (list2.IsEmpty()) {
		Head = NULL;
	}
	else {
		node<T>* ptr2 = list2.Head->next;
		Head = new node<T>(list2.Head->date);
		ptr = Head;
		while (ptr2 != list2.ptr) {
			ptr->next = new node<T>(ptr2->date);
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
		ptr->next = new node<T>(ptr2->date, Head);
		ptr = ptr->next;
	}
}