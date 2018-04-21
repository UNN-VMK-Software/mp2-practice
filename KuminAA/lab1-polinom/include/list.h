#pragma once

#include <iostream>
#include "node.h"
using namespace std;

template<typename t>
class Ringlist
{
	Node<t> *head;
	Node<t> *curr;
public:
	Ringlist();
	Ringlist(const Ringlist<t> &l);
	Ringlist<t>& operator= (const Ringlist<t> &l);
	~Ringlist();

	void InsertToOrdered(const t &a);
	//void DeliteNode(const t &a);

	void reset() { curr = head->next; };
	t& GetCurr() { return curr->data; };
	void SetNext() { curr = curr->next; }
	int isended() { return (curr->next == head->next); };

	int operator==(const Ringlist<t>& l) const;
	int operator!=(const Ringlist<t>& l) const { return !(*this == l); }
};

//......................................................................

template<typename t>
Ringlist<t>::Ringlist()
{
	head = new Node<t>(NULL);
	head->next = head;
	curr = head;
}

template<typename t>
Ringlist<t>::Ringlist(const Ringlist<t> &l)
{
	head = new Node<t>(l.head->data);
	curr = head;
	Node<t>* temp = l.head;
	while (temp->next != l.head)
	{	
		temp = temp->next;
		curr->next = new Node<t>(temp->data);
		curr = curr->next;
	}
	curr->next = head;
	curr = head;
}

template<typename t>
Ringlist<t>::~Ringlist()
{
	Node<t> *current = head->next;
	Node<t> *temp;
	while (current != head)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
	head->next = head;
	delete head;
}

template<typename t>
Ringlist<t>& Ringlist<t>::operator= (const Ringlist<t> &l)
{
	Node<t> *current = head->next;
	Node<t> *temp1;
	while (current != head)
	{
		temp1 = current->next;
		delete current;
		current = temp1;
	}
	head->next = head;

	Node<t> *temp = l.head;
	head = new Node<t>(temp->data);
	curr = head;
	while (temp->next != l.head)
	{
		temp = temp->next;
		curr->next = new Node<t>(temp->data);
		curr = curr->next;
	}
	curr->next = head;
	curr = head;

	return *this;
}

template<typename t>
void Ringlist<t>::InsertToOrdered(const t &a)
{
	curr = head;
	while ((curr->next->data > a) && (curr->next != head))
		curr = curr->next;

	Node<t>* temp = curr->next;
	curr->next = new Node<t>(a, temp);
	//curr->next->next = temp;
}

//template<typename t>
//void Ringlist<t>::DeliteNode(const t &a)
//{
//	curr = head->next;
//	Node<t> *temp;
//
//	while (curr != head)
//	{
//		if (curr->data == a)
//		{
//			temp = curr->next;
//			delete curr;
//			curr = temp;
//		}
//		curr = curr->next;
//	}
//}

template<typename t>
int Ringlist<t>::operator==(const Ringlist<t>& l) const
{
	int k = 1;
	if (this != &l)
	{
		Node<t> *temp = head->next;
		Node<t> *temp1 = l.head->next;

		while (!(temp1 == l.head || temp == head) && temp->data == temp1->data)
		{
			temp = temp->next;
			temp1 = temp1->next;
			/*if (temp1->next == l.head)
				temp1 = new Node<t>(NULL, temp1->next);
			else
				if (temp->next == head)
					temp = new Node<t>(NULL,temp->next);*/
		}
		if (temp1 != l.head || temp != head)
			k = 0;
	}
	return k;
}