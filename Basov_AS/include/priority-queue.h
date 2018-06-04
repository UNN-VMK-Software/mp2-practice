#include "d-heap.h"

class PriorityQueue {
public:
	PriorityQueue() {};

	virtual void push(Data *&key) = 0;
	virtual Data* pop() = 0;
	virtual void refresh() = 0;

	virtual int isFull() = 0;
	virtual int isEmpty() = 0;
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

	virtual void push(Data *&key);	// Добавление ключа в очередь
	virtual Data* pop();			// Удаление минимального
	virtual void refresh();			// Обновление очереди

	virtual int isFull();
	virtual int isEmpty();
};