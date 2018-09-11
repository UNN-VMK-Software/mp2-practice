#pragma once
#include "PriorityQueue.h"
#include "DHeap.h"

template <typename T>
class DHeapBasePriorityQueue : public PriorityQueue<T>
{
	DHeap<T> heap;
public:
	DHeapBasePriorityQueue() = default;
	DHeapBasePriorityQueue(vector<T> elems,int d);
	bool IsFull() const override;
	bool IsEmpty() const override;
	void Push(T a) override;
	T Pop() override;
};

template<typename T>
inline DHeapBasePriorityQueue<T>::DHeapBasePriorityQueue(vector<T> elems,int d)
{
	heap = DHeap<T>(elems,d);
}

template<typename T>
inline bool DHeapBasePriorityQueue<T>::IsFull() const
{
	return false;
}

template <typename T>
bool DHeapBasePriorityQueue<T>::IsEmpty() const
{
	return heap.IsEmpty();
}

template <typename T>
void DHeapBasePriorityQueue<T>::Push(T a)
{
	heap.Insert(a);
}

template <typename T>
T DHeapBasePriorityQueue<T>::Pop()
{
	T a = heap.GetMinValue();
	return a;
}
