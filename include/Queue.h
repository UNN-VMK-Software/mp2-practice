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
	
	const A2& pop() override
	{
		if (this->IsEmpty()) throw logic_error("Queue is empty");
		if (Array == 0) throw logic_error("");
		const A2* tmp = this->Array[this->first];
		this->Array[this->first] = 0;
		this->first++;
		this->DataCount--;
		return (*tmp);
	}

};