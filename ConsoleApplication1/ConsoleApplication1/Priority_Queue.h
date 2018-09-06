#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "D_Heap.h"

template <class KeyType>
class Priority_queue
{
public:
	Priority_queue(void) {};
	virtual ~Priority_queue() {};
	virtual void Push(const KeyType) = 0;
	virtual void Pop() = 0;
	virtual int IsEmpty() = 0;
	virtual int GetSize() = 0;
	virtual KeyType Top() = 0;
};

template <class KeyType>
class Queue_on_heap : public Priority_queue<KeyType>
{
private:
	D_heap<KeyType> *heap;
public:
	Queue_on_heap(int);
	virtual ~Queue_on_heap() { delete heap; }
	void Push(const KeyType);
	void Pop();
	KeyType Top();
	int IsEmpty();
	virtual int GetSize() { return heap->GetCount(); };
};

template <class KeyType>
Queue_on_heap<KeyType>::Queue_on_heap(int arity)
{
	if (arity < 0)
		break;
	heap = new D_heap<KeyType>(arity, 0);
}

template <class KeyType>
void Queue_on_heap<KeyType>::Pop()
{
	if (IsEmpty())
		break;
	heap->RemoveMin();
}

template <class KeyType>
int Queue_on_heap<KeyType>::IsEmpty()
{
	return heap->GetCount() == 0;
};

template <class KeyType>
void Queue_on_heap<KeyType>::Push(const KeyType x)
{
	heap->Push(x);
	heap->Sort();
}

template <class KeyType>
KeyType Queue_on_heap<KeyType>::Top()
{
	if (IsEmpty())
		break;
	return heap->GetKey(0)->pr;
}

#endif