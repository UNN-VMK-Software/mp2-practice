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


	virtual int IsFull()const = 0;
	virtual int IsEmpty()const = 0;
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

	virtual int IsFull()const;
	virtual int IsEmpty()const;
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
