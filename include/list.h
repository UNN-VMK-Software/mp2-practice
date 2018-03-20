#pragma once
#include "node.h"

template <class type>
class list {
private:
	node<type>* head;
	node<type>* curr;
public:
	list();
	~list();
	void Clean();
	list(const list<type>& list2);
	list<type>& operator=(const list<type>& list2);
	void InsertOrd(type a);
	void Insert(node<type>*, type );
	void Reset() { curr = head->next; }
	void GetNext() { curr = curr->next; }
	node<type>* GetCurr() const { return curr; }
	bool IsEnded() const { return curr == head; }
	bool operator==(const list<type>&) const;
	bool operator!=(const list<type>& list2) const { return !(*this == list2); }
	
};

template <class type> list<type>::list() {
	head = new node<type>;
	head->next = head;
	curr = head;
}

template <class type> list<type>::~list() {
	Clean();
	delete head;
}

template <class type> void list<type>::Clean() {
	node <type>* cur = head->next;
	node<type>* temp;
	while (cur != head)
	{
		temp = cur->next;
		delete cur;
		cur = temp;
	}
	head->next = head;
}

template <class type> list<type>::list(const list<type>& list2) {	
	node<type>* curr2 = list2.head;
	head = new node<type>(curr2->data);
	head->next = head;	
	curr=head;	
	while (curr2->next != list2.head)
	{
		curr2 = curr2->next;
		curr->next = new node<type>(curr2->data);
		GetNext();
	}
	curr->next = head;
	
}

template <class type> list<type>& list<type>::operator=(const list<type>& list2) {
	Clean();
	node<type>* cur2 = list2.head;
	node<type>* cur = head;
	while (cur2->next != list2.head)
	{
		cur2 = cur2->next;
		cur->next = new node<type>(cur2->data);
		cur = cur->next;
	}
	cur->next = head;
	curr = head;
	return *this;
}

template <class type> void list<type>::InsertOrd(type a) 
{
	curr = head;
	node<type>* temp;	
		while ((curr->next->data > a) && (curr->next != head))
			GetNext();
		temp = curr->next;
		curr->next = new node<type>(a);
		curr->next->next = temp;	
}


template <class type> bool list<type>::operator==(const list<type>& list2) const {
	bool res = true;
	if (this != &list2)
	{
		node<type>* cur2 = list2.head->next;
		node<type>* cur = head->next;
		while (cur != head && cur2 != list2.head && cur->data == cur2->data)
		{
			cur = cur->next;
			cur2 = cur2->next;
		}
		if (cur->data != cur2->data)
			res = false;
	}
	return res;
}

template <class type> void list<type>::Insert(node<type>* p,type d) {	
	
		node<type>* temp = p->next;
		p->next = new node<type>(d);
		p->next->next = temp;		
	
}