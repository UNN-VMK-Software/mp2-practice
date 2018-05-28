#ifndef _NODE_
#define _NODE_


#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
public:
	T data; //данные
	Node<T>* next; //указатель на звено
	Node()
	{
		next = NULL;
	}
	Node(const Node<T> &n);
	Node(const T & d);
	~Node()
	{
	}
	const Node<T>&operator=(const Node<T> &n); 
	bool operator==(const Node<T> &n) const;
	friend ostream & operator<<(ostream &os, const Node<T> &n)
	{
		os << n.data;
		return os;
	}
};

template<class T>
inline Node<T>::Node(const Node<T> &n)
{
	data = n.data;
	next = n.next;
}

template<class T>
inline Node<T>::Node(const T &d)
{
	data = d;
	next = NULL;
}

template<class T>
inline const Node<T>& Node<T>::operator=(const Node<T> &n)
{
		data = n.data;
		next = n.next;
		return *this;
}

template<class T>
inline bool Node<T>::operator==(const Node<T>& n) const
{
	if ((data == n.data) && (next == n.next))
		return true;
	else
		return false;
}

#endif