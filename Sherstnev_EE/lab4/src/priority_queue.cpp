#include "..\include\priority_queue.h"



DheapBasedPriorityQueue::DheapBasedPriorityQueue(int d)
{
	heap = new Dheap(d);
}



DheapBasedPriorityQueue::DheapBasedPriorityQueue(VertexLabel ** keys, int num, int d)
{
	heap = new Dheap(d);
	heap->addSet(keys, num);
}


DheapBasedPriorityQueue::~DheapBasedPriorityQueue()
{
	delete heap;
}


void DheapBasedPriorityQueue::push(VertexLabel*& key)
{
	heap->add(key);
}

VertexLabel* DheapBasedPriorityQueue::pop()
{
	return heap->erase(0);
}


void DheapBasedPriorityQueue::refresh()
{
	heap->spudding();
}


int DheapBasedPriorityQueue::isFull()
{
	return heap->isFull();
}


int DheapBasedPriorityQueue::isEmpty()
{
	return heap->isEmpty();
}

