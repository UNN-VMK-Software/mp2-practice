#pragma once

template <typename t>
class Node
{
public:
	t data;
	Node *next;
	Node(t Data = NULL, Node *Next = NULL) 
	{ 
		data = Data; 
		next = Next; 
	}
	Node(const Node &l) { data = l.data; next = NULL; }

	bool operator==(const Node<t> &l) const { return (data == l.data) && (next == l.next); };
	bool operator!= (const  Node<t>& l) const { return !(*this == l); }

	bool operator< (const Node<t>& l) const { return (data < l.data); }
	bool operator> (const Node<t>& l) const { return (data > l.data); }

};


