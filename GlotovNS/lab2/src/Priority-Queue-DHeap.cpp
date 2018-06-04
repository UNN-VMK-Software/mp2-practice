#include "Priority-Queue.h"

DHeapBasedPriorityQueue::DHeapBasedPriorityQueue(int d)
{
	heap = new DHeap(d);
}

DHeapBasedPriorityQueue::DHeapBasedPriorityQueue(const DHeapBasedPriorityQueue &queue)
{
	this->heap = new DHeap(*(queue.heap));
}

DHeapBasedPriorityQueue::DHeapBasedPriorityQueue(Data **keys, int num, int d)
{
	heap = new DHeap(d);
	heap->AddSet(keys, num);
}

DHeapBasedPriorityQueue::~DHeapBasedPriorityQueue()
{
	delete heap;
}

void DHeapBasedPriorityQueue::Push(Data *&key)
{
	heap->Add(key);
}

Data* DHeapBasedPriorityQueue::Pop()
{
	return heap->Erase(0);
}

void DHeapBasedPriorityQueue::Refresh()
{
	heap->Hilling();
}

int DHeapBasedPriorityQueue::IsFull()
{
	return heap->IsFull();
}

int DHeapBasedPriorityQueue::IsEmpty()
{
	return heap->IsEmpty();
}

