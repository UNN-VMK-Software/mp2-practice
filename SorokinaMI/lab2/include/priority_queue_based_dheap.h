#pragma once
#include "priority_queue.h"
#include "dheap.h"
#include "graph.h"

template <typename T>
class PriorityQueueBasedDHeap: public PriorityQueue<T>
{
public:
	DHeap<T>* H;
	PriorityQueueBasedDHeap(int n);
	~PriorityQueueBasedDHeap();
	void push(T val);
	 T pop();
	// T get();
	 bool IsEmpty();
	 void refresh();
};


template <typename T>
PriorityQueueBasedDHeap<T>::PriorityQueueBasedDHeap(int n)
{
	H = new DHeap<T>(n);
}

template <typename T>
PriorityQueueBasedDHeap<T>::~PriorityQueueBasedDHeap()
{

}

template <typename T>
void PriorityQueueBasedDHeap<T>::push(T val)
{
	H->insert(val);
}

template <typename T>
void PriorityQueueBasedDHeap<T>::refresh()
{
	H->makeitheap();
}

template <typename T>
T PriorityQueueBasedDHeap<T>::pop()
{
	T tmp = H->deleteminkey();
	return tmp;
}

//template <typename T>
//T PriorityQueueBasedDHeap<T>::get()
//{
//}

template <typename T>
bool PriorityQueueBasedDHeap<T>::IsEmpty()
{
	if( H->GetCurrSize() == 0 )return true;
	else return false;
}
