#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

template <class val>
class node
{
public:
	val data;
	node<val>* next; 
	node()
	{
		next = NULL;
	}
	node(const node<val> &n);
	node(const val & d);
	~node()
	{
	}
	const node<val>&operator=(const node<val> &n);
	bool operator==(const node<val> &n) const;
	friend ostream & operator<<(ostream &os, const node<val> &n)
	{
		os << n.data;
		return os;
	}
};

template<class val>
inline node<val>::node(const node<val> &n)
{
	data = n.data;
	next = n.next;
}

template<class val>
inline node<val>::node(const val &d)
{
	data = d;
	next = NULL;
}

template<class val>
inline const node<val>& node<val>::operator=(const node<val> &n)
{
	data = n.data;
	next = n.next;
	return *this;
}

template<class val>
inline bool node<val>::operator==(const node<val>& n) const
{
	if ((data == n.data) && (next == n.next))
		return true;
	else
		return false;
}


