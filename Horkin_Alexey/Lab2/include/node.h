#pragma once
#include <string>
#include <sstream>
using namespace std;
template <typename T> 
class Node 
{
public:
	T Data;
	Node* Next;
	Node(T Data= 0, Node* NextPtr= NULL);
	Node(const Node<T> &NodaCopy);
	Node(const Node* con);
};

template <typename T>
Node<T> :: Node( T data, Node* NextPtr ) 
{
	Data = data;
	Next = NextPtr;
}

template <typename T>
Node<T> :: Node(const Node<T> &NodaCopy)
{
	Data = NodaCopy.Data;
}


template <typename T>
Node<T> ::Node(const Node* con)
{
	Data = con->Data;
}

