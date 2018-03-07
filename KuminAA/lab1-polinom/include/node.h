#pragma once

template <typename tkey>
class Node
{
public:
	tkey data;
	Node *next;
	Node(tkey t, Node *p = NULL) { data = t; next = p; }
	Node(const Node &l) { data = l.key; next = l.next; }
	bool operator==(const Node &l) const { return (data == l.key) && (next == l.next); };
	/*Node& operator=(const Node &l) {
	data = l.key;
	next = l.next;
	retiurn *this;
	}*/
};

//template <typename tkey>
//Node& Node<tkey>::operator=(const Node &l)
//{
//	data = l.key; 
//	next = l.next;
//	retiurn *this;
//}
