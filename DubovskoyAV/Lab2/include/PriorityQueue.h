#pragma once
#include "DHeap.h"

class PriorityQueue {
public:
	PriorityQueue() {};

	virtual void push(Data *&key) = 0;  // Добавление ключа в очередь
	virtual Data* pop() = 0;            // Изъятие минимального
	

	virtual int  isFull() const = 0;           //Проверка на полноту
	virtual int  isEmpty() const = 0;          //Проверка на пустоту
};


/*Приоритетная очередь на базе d-кучи*/
class DHeapPriorityQueue : public PriorityQueue {
public:
	DHeap * heap;
	DHeapPriorityQueue(int d = 4);
	DHeapPriorityQueue(const DHeapPriorityQueue &queue);
	DHeapPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapPriorityQueue();

	virtual void push(Data *&key);	// Добавление ключа в очередь
	virtual Data* pop();			// Изъятие минимального
	

	virtual int  isFull()const;           //Проверка на полноту
	virtual int  isEmpty()const;          //Проверка на пустоту
};