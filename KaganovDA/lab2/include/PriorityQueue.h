#pragma once
#include "DHeap.h"

enum QueueID {
	HEAP = 0,
};

class PriorityQueue {
public:
	PriorityQueue() {};

	virtual void Push(Data *&key) = 0;
	virtual Data* Pop() = 0;
	virtual void Refresh() = 0;

	virtual int IsFull() = 0;
	virtual int IsEmpty() = 0;
};

class DHeapBasedPriorityQueue : public PriorityQueue {
protected:
	DHeap* heap;
public:
	DHeapBasedPriorityQueue(int d = 4);
	DHeapBasedPriorityQueue(const DHeapBasedPriorityQueue &queue);
	DHeapBasedPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapBasedPriorityQueue();

	virtual void Push(Data *&key);
	virtual Data* Pop();
	virtual void Refresh();

	virtual int IsFull();
	virtual int IsEmpty();
};

class QueueFactory {
public:
	static PriorityQueue* createQueue(QueueID Qid)
	{
		PriorityQueue *queue;
		queue = new DHeapBasedPriorityQueue();
		return queue;
	}
};
