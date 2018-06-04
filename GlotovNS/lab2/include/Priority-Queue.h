#pragma once

#include "D-Heap.h"

class PriorityQueue
{
public:
	PriorityQueue() {};
	virtual void Push(Data *&key) = 0;
	virtual Data* Pop() = 0;
	//virtual void Refresh() = 0;
    const int IsFull() = 0;
	const int IsEmpty() = 0;
};


/*           Приоритетная очередь на D-куче           */
class DHeapBasedPriorityQueue : public PriorityQueue {
protected:
	DHeap * heap;
public:
	DHeapBasedPriorityQueue(int d = 4);
	DHeapBasedPriorityQueue(const DHeapBasedPriorityQueue &queue);
	DHeapBasedPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapBasedPriorityQueue();
	virtual void Push(Data *&key);	// Добавление ключа в очередь
	virtual Data* Pop();			// Удаление минимального
//	virtual void Refresh();			// Обновление очереди
	virtual int IsFull();
	virtual int IsEmpty();
};
