#pragma once
#include "Stack.h"

template<class A2>
class Queue :public Stack<A2>
{
public:
	Queue() :Stack<A2>(){}
	Queue(Queue& lhs) :Stack<A2>(lhs){}
	Queue(int _size) :Stack<A2>(_size){}
	~Queue(){}
	void push(A2& lhs)override
	{
		if ((*this).IsFull()) throw logic_error("Queue is overfull");
		this->Array[this->last] = &lhs;
		this->last++;
	}
	A2& pop() override
	{
		if (this->IsEmpty()) throw logic_error("Queue is empty");
		A2* tmp = this->Array[this->first];
		this->Array[this->first] = 0;
		this->first++;
		return (*tmp);
	}

};