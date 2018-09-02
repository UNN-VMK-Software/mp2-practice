#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "dheap.h"

template <class T> class PriorityQueue
{
public:
	virtual void Push(T& t) = 0;
	virtual T Pop() = 0;
	virtual bool isEmpty() const = 0;
};

template <class T> class PriorityQueueDHeap : public PriorityQueue<T>
{
public:
	PriorityQueueDHeap(T* keys, int d, int n)
	{
		dheap = new DHeap<T>(keys, d, n);
	}

	virtual void Push(T& t) { dheap->insert(t); }
	virtual T Pop() { return dheap->getmin(); }
	virtual bool isEmpty() const { return dheap->isEmpty(); }


	int GetSize() { return dheap->GetSize(); }
	T& GetElement(int idx) { return dheap->GetElement(idx); }
	void RepairQueue() { dheap->hilling(); }
	void SetSize(int new_size) { dheap->SetSize(new_size); }

	virtual ~PriorityQueueDHeap() { delete dheap; }

private:
	DHeap<T>* dheap;
};

template class PriorityQueueDHeap<int>;
template class PriorityQueueDHeap<VertexDist>;
#endif