#include "priority-queue.h"

DHeapBasedPriorityQueue::DHeapBasedPriorityQueue(int d)
{
	heap = new DHeap(d);
}
//============================================================||============================================================
DHeapBasedPriorityQueue::DHeapBasedPriorityQueue(const DHeapBasedPriorityQueue &queue)
{
	this->heap = new DHeap(*(queue.heap));
}
//============================================================||============================================================
DHeapBasedPriorityQueue::DHeapBasedPriorityQueue(Data **keys, int num, int d)
{
	heap = new DHeap(d);
	heap->addSet(keys, num);
}
//============================================================||============================================================
DHeapBasedPriorityQueue::~DHeapBasedPriorityQueue()
{
	delete heap;
}
//============================================================||============================================================
void DHeapBasedPriorityQueue::push(Data *&key)
{
	heap->add(key);
}
//============================================================||============================================================
Data* DHeapBasedPriorityQueue::pop()
{
	return heap->erase(0);
}
//============================================================||============================================================
int DHeapBasedPriorityQueue::isFull()const
{
	return heap->isFull();
}

int DHeapBasedPriorityQueue::isEmpty()const
{
	return heap->isEmpty();
}