#pragma once
#include"tlink.h"
#include<iostream>
using namespace std;

using TElem = int;

class TList
{
private:
	TLink<TElem> *root = nullptr;
public:
	TList() = default;
	~TList();
	TList(const TList & a);
	void Insert(TElem key);
	void Insert_End(TElem key);
	void Isert_After(TElem key, TElem keyprev) const;
	void Insert_Before(TElem key, TElem keyNext);
	TLink<TElem>* Search(TElem key) const;
	void Remove(TElem key);
	int Size() const;
	//???
	TLink<TElem>* Reset() const;
	TElem GetNext() const;
	void print();
};

//
//TList::TList()
//{
//
//}

//
//TList::~TList()
//{
//	while (root != nullptr)
//	{
//		TLink<TElem>* next = root->pNext;
//		delete root;
//		root = next;
//	}
//}
//
//
////ÐÀÇÎÁÐÀÒÜ
//TList::TList(const TList& a)
//{
//	if (a.root == nulptr)
//	{
//		root = nulptr;
//		return;
//	}
//	root->key = a.root->key;
//	root->pNext = nullptr;
//	TLink<TElem> * TLink<TElem> = root;
//	for (TLink<TElem> TLink<TElem>1 = a.root->pNext; TLink<TElem>1 != nullptr; TLink<TElem>1 = TLink<TElem>1->pNext)
//	{
//		TLink<TElem>->pNext = new TLink<TElem>(TLink<TElem>1->key);
//	}
//}
//
//
//void TList::Insert(TElem key)
//{
//	TLink<TElem>* n = new TLink<TElem>(key);
//	n->pNext = root;
//	root = n;
//}
//
//
//void TList::Insert_End(TElem key)
//{
//	if (root == 0)
//	{
//		Insert(key)
//			return;
//
//	}
//	TLink<TElem> * tmp = root;
//	while (tmp->pNext != 0)
//		tmp = tmp->pNext;
//	tmp->pNext = new TLink<TElem>();
//	tmp->pNext->key = key;
//	tmp->pNext->pNext = nullptr;
//
//}
//
//
//void TList::Insert_Before(TElem key, TElem keyNext)
//{
//	//if (root == 0) return;
//	if (root->key == keyNext)
//	{
//		Insert(key);
//		return;
//	}
//	TLink<TElem>* tmp = root;
//	while ((tmp->pNext != 0) && (tmp->pNext->key != keyNext))
//		tmp = tmp->pNext;
//	if (tmp == 0) { throw "element not found"; }
//	TLink<TElem>* n = new TLink<TElem>;
//	n->key = key;
//	n->pNext = tmp->pNext;
//	tmp->pNext = n;
//}
//
//
//void TList::Isert_After(TElem key, TElem keyprev) const
//{
//	TLink<TElem>*Nroot = root;
//	while (Nroot != 0 && Nroot->key != keyprev)
//		Nroot = Nroot->pNext;
//	if (Nroot == 0)
//	{
//		throw "Element not found";
//	}
//	TLink<TElem>*n = new TLink<TElem>();
//	n->key = key;
//	n->pNext = Nroot->pNext;
//	Nroot->pNext = n;
//}
//
//
//TLink<TElem>* TList::Search(TElem key) const
//{
//	TLink*Nroot = root;
//
//	while (Nroot != 0 && Nroot->key != key)
//		Nroot = Nroot->pNext;
//	if (Nroot == 0)
//	{
//		throw "Element not found";
//	}
//	return Nroot;
//}
//
//
//void TList::Remove(T key)
//{
//	if (root == 0) return;
//	TLink* tmp = root;
//	if (root->key == key)
//	{
//		root = root->pNext;
//		delete tmp;
//		return;
//	}
//	while (tmp->pNext->key != key && tmp->pNext != 0)
//		tmp = tmp->pNext;
//	if (tmp->pNext == 0)
//	{
//		throw "Element not found";
//	}
//	TLink*n = tmp->pNext;
//	tmp->pNext = tmp->pNext->pNext;
//	delete n;
//}
//
//
//int TList::Size() const
//{
//	TLink*tmp = root;
//	int i = 0;
//	while (tmp != 0)
//	{
//		tmp = tmp->pNext;
//		i++;
//	}
//	return i;
//}
//
//
//TLink* TList::Reset() const
//{
//	return root;
//}
//
//
//T TList::GetNext() const
//{
//	TLink* tmp = root;
//	/*if (tmp == 0)
//	{
//		throw "Is empty";
//	}*/
//	T key = tmp->pNext->key;
//	return key;
//}
//
//
//inline void TList::print()
//{
//}
