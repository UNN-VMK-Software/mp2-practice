#pragma once
#include <iostream>

template <typename T>

class  Node
{
public:
	T data;
    Node<T>* next;
	
	Node(T d = NULL, Node<T>* l = NULL)
	{ 
		data = d; 
		next = l; 
	}

	bool operator< (const Node<T>& n) const { return (data<n.data); }
	bool operator> (const  Node<T>& n) const { return (data>n.data); }

	bool operator!= (const  Node<T>& n) const { return !(*this == n); }
	bool operator==(const Node<T>& n) const { return (data == n.data && next == n.next); }
};