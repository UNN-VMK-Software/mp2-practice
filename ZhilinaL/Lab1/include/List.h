#pragma once
#include "Node.h"
template <typename T>
class ListRing
{
private:
	Node<T>* cur;
	Node<T>* head;
public:
	ListRing();
	ListRing(const RingList<T> &CopyList);
	bool IsEmpty();
	void InsertToTail(T NewData);
	void InsertAfter(const Node<t>* A, T NewData);

};