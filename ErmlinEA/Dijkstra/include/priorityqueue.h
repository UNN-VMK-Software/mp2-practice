#pragma once

#include "DHeap.h"

enum QueueID {
	HEAP = 0,
};

class PriorityQueue {
public:
	PriorityQueue() {};
	virtual void push(Data *&key) = 0;
	virtual Data* pop() = 0;
	virtual void refresh() = 0;
	virtual int isFull() = 0;
	virtual int isEmpty() = 0;
};

class PriorityQueueHeap : public PriorityQueue {
protected:
	DHeap *heap;
public:
	PriorityQueueHeap(int d = 4);
	PriorityQueueHeap(const PriorityQueueHeap &queue);
	PriorityQueueHeap(Data **keys, int num, int d = 4);
	~PriorityQueueHeap();
	virtual void push(Data *&key);
	virtual Data* pop();
	virtual void refresh();
	virtual int isFull();
	virtual int isEmpty();
};

class QueueFactory {
public:
	static PriorityQueue* createQueue(QueueID qid)
	{
		PriorityQueue *queue;
		queue = new PriorityQueueHeap();
		return queue;
	}
};