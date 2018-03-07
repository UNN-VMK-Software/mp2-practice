#include "list.h"

Ringlist::Ringlist()
{
	Monom m;
	head = new Node<Monom>(m, head);
	curr = head;
}

Ringlist::Ringlist(const Ringlist &l)
{
	head = new Node<Monom>(l.head->data, head);
	curr = head;
	Node<Monom>* temp = l.head;
	while (temp->next != l.head)
	{
		curr->next = new Node<Monom>(temp->next->data, head);
		curr = curr->next;
		temp = temp->next;
	}
}

Ringlist::~Ringlist()
{
	curr = head->next;
	Node<Monom>* temp;
	while (curr != head)
	{
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	head = NULL;
}

void Ringlist::InsertToTail(const Monom &a)
{
	curr = head;
	while (curr->next != head)
		curr = curr->next;
	curr->next = new Node<Monom>(a, head);
}

void Ringlist::InsertToOrdered(const Monom &a)
{
	curr = head;
	while ((curr->next->data.abc > a.abc) && (curr->next != head))
		curr = curr->next;
	if (curr->next->data.abc == a.abc)
		curr->next->data.coeff += a.coeff;
	else
	{
		Node<Monom>* temp = curr->next;
		curr->next = new Node<Monom>(a, temp);
	}
}

void Ringlist::Ordering()
{
	curr = head;
	Ringlist l;
	l.head->data = head->data;
	while (curr->next != head)
	{
		l.InsertToOrdered(curr->next->data);
		curr = curr->next;
	}
	head = l.head;
}

void Ringlist::reset()
{
	curr = head;
}

Monom& Ringlist::GetNext()
{
	curr = curr->next;
	return curr->data;
}

int Ringlist::isended()
{
	return (curr->next == head);
}