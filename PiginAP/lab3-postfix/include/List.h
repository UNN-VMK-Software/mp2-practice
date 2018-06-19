#ifndef LIST_H
#define LIST_H

#include "Obj.h"
#include <iostream>

template <typename L>
class List 
{
private:
	Obj<L>* root;
public:
	List();	//+
	List(const List<L>& list);	//+
	~List();	//+
	void push_back(const L &l);	//+
	void push_up(const L &l);	//+
	void push_under(L key, const L &l);	//+
	L pop_up();	//+
	L pop_back();	//+
	size_t get_size()const;	//+
	List<L>& operator=(const List<L>& list);	//+
};
//==========================================================||==========================================================
template <typename L>
List< L >::List() : root(NULL) {}
//==========================================================
template<typename L>
List<L>::~List() 
{
	while (root) 
	{
		pop_up();
	}
}
//==========================================================
template<typename L>
List<L>::List(const List<L>& list):root(NULL)
{
	if (list.root) 
	{
		root = new Obj<L>(list.root->val);
		Obj<L>* buf = root;
		Obj<L>* buffer = list.root->next;
		while (buffer) 
		{
			buf->next = new Obj<L>(buffer->val);
			buf = buf->pNext;
			buffer = buffer->pNext;
		}
	}
}
//==========================================================
template<typename L>
void List<L>::push_back(const L & l) 
{
	Obj<L>* temp = NULL;
	if (temp = new Obj<L>(l))
	{
		if (root == NULL) {
			root = temp;
		}
		else {
			Obj<L>* buf = root;
			while (buf->pNext) 
			{
				buf->pNext;
			}
			buf->pNext = temp;}
	}
	else {
		throw "List is FULL";}
}
//==========================================================
template<typename L>
void List<L>::push_up(const L & l) 
{
	Obj<L>* obj = NULL;
	if (obj = new Obj<L>(l)) 
	{
		Obj<L>* buf = root;
		root = obj;
		obj->pNext = buf;
	}
	else {
		throw "ERROR List is FULL";
	}

}
//==========================================================
template<typename L>
void List<L>::push_under(L key, const L & l) 
{
	Obj<L>* Obj = NULL;
	if (Obj = new Obj<L>(l)) 
	{
		if (!root->pNext)
		{
			root->pNext = Obj;
		}
		else {
			Obj<L>* buf = root;
			while (buf->val != key) 
			{
				buf = buf->pNext;
			}
			Obj<L>* temp = buf->pNext;
			buf->pNext = Obj;
			buf->pNext->pNext = temp;}
		
	}
	else {
		throw "List is FULL";}
}
//==========================================================
template<typename L>
L List<L>::pop_up() 
{
	if (!root) { throw "List is Empty"; }
	Obj<L>* buf = root;
	L dat = buf->val;
	root = buf->pNext;
	delete buf;
	return dat;
}
//==========================================================
template<typename L>
L List<L>::pop_back()
{

	if (!root) { throw "List is Empty"; }
	else if (!root->next) 
		{
			L val = root->val;
			delete root;
			root = NULL;
			return val;
		}
	else 
	{
		Obj<L>* buf = root;
		while (buf->next->next) 
		{
			buf = buf->next;
		}
		L val = buf->next->val;
		Obj<L>* temp = buf->next;
		buf->next = NULL;
		delete temp;
		return val;
	}
	return L();
}
//==========================================================
template<typename L>
inline size_t List<L>::get_size() const
{
	size_t size = 0;
	Obj<L>* root_buf = root;
	while (root_buf) 
	{
		root_buf = root_buf->pNext;
		size++;
	}
	return size;
}
//==========================================================
template<typename L>
List<L>& List<L>::operator=(const List<L>& list)
{
	if (list.root) 
	{
		root = new Obj<L>(list.root->val);
		Obj<L>* buf = root;
		Obj<L>* buffer = list.root->next;
		while (buffer) 
		{
			buf->next = new Obj<L>(buffer->val);
			buf = buf->next;
			buffer = buffer->next;
		}
	}
	return *this;
}
//==========================================================
#endif