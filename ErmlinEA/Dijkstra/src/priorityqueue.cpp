#include "..//include/priorityqueue.h"

PriorityQueueHeap::PriorityQueueHeap(int d)
{
	heap = new DHeap(d);
}

PriorityQueueHeap::PriorityQueueHeap(const PriorityQueueHeap &queue)
{
	this->heap = new DHeap(*(queue.heap));
}

PriorityQueueHeap::PriorityQueueHeap(Data **keys, int num, int d)
{
	heap = new DHeap(d);
	heap->addSet(keys, num);
}

PriorityQueueHeap::~PriorityQueueHeap()
{
	delete heap;
}

void PriorityQueueHeap::push(Data *&key)
{
	heap->add(key);
}

Data* PriorityQueueHeap::pop()
{
	return heap->erase(0);
}

void PriorityQueueHeap::refresh()
{
	heap->spudding();
}

int PriorityQueueHeap::isFull()
{
	return heap->isFull();
}

int PriorityQueueHeap::isEmpty()
{
	return heap->isEmpty();
}
