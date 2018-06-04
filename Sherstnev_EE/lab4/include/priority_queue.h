#pragma once
#include "Dheap.h"


class priority_queue
{
public:
	priority_queue() {};

	virtual void push(VertexLabel*&key) = 0;
	virtual VertexLabel* pop() = 0;
	virtual void refresh() = 0;
	virtual int isFull() = 0;
	virtual int isEmpty() = 0;
};


class DheapBasedPriorityQueue : public priority_queue
{
protected:
	Dheap * heap;
public:
	DheapBasedPriorityQueue(int d = 4);
	DheapBasedPriorityQueue(VertexLabel **keys, int num, int d = 4);
	~DheapBasedPriorityQueue();

	virtual void push(VertexLabel *&key);
	virtual VertexLabel* pop();
	virtual void refresh();
	virtual int isFull();
	virtual int isEmpty();
};


