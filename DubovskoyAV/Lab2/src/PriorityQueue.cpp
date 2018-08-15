
#include "PriorityQueue.h"

DHeapPriorityQueue::DHeapPriorityQueue(int d)
{
	heap = new DHeap(d);
}

DHeapPriorityQueue::DHeapPriorityQueue(const DHeapPriorityQueue &queue)
{
	this->heap = new DHeap(*(queue.heap));
}

DHeapPriorityQueue::DHeapPriorityQueue(Data **keys, int num, int d)
{
	heap = new DHeap(d);
	heap->addSet(keys, num);
}

DHeapPriorityQueue::~DHeapPriorityQueue()
{
	delete heap;
}

void DHeapPriorityQueue::push(Data *&key)
{
	heap->add(key);
}

Data* DHeapPriorityQueue::pop()
{
	return heap->erase(0);
}

int DHeapPriorityQueue::isFull()const
{
	return heap->isFull();
}

int DHeapPriorityQueue::isEmpty()const
{
	return heap->isEmpty();
}

