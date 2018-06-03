#include "DHeap.h"

class PriorityQueue {
public:
	PriorityQueue() {};

	virtual void push(Data *&key) = 0;  // Добавление ключа в очередь
	virtual Data* pop() = 0;            // Изъятие минимального
	virtual void refresh() = 0;         // Обновление очереди

	virtual int isFull() = 0;           //Проверка на полноту
	virtual int isEmpty() = 0;          //Проверка на пустоту
};


/*Приоритетная очередь на базе d-кучи*/
class DHeapPriorityQueue : public PriorityQueue {
protected:
	DHeap * heap;
public:
	DHeapPriorityQueue(int d = 4);
	DHeapPriorityQueue(const DHeapPriorityQueue &queue);
	DHeapPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapPriorityQueue();

	virtual void push(Data *&key);	// Добавление ключа в очередь
	virtual Data* pop();			// Изъятие минимального
	virtual void refresh();			// Обновление очереди

	virtual int isFull();           //Проверка на полноту
	virtual int isEmpty();          //Проверка на пустоту
};