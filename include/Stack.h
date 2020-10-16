#pragma once
#include <iostream>

using namespace std;
template<class A1>
class Stack
{
public:

	Stack()
	{
		Array = 0;
		size = 0;
		first = 0;
		last = 1;
	}
	Stack(int _size)
	{
		if (_size < 0)throw logic_error("negative size");
		Array = new A1*[_size];
		size = _size;
		first = 0;
		last = 0;
	}
	Stack(Stack& lhs)
	{
		Array = new A1*[lhs.size];
		size = lhs.size;
		first = lhs.first;
		last = lhs.last;
	}

	virtual ~Stack()
	{
		delete[] Array;
	}
	bool IsEmpty()
	{
		return(last==first);
	}
	bool IsFull()
	{
		return(last==size);
	}
	A1** GetMemory()
	{
		return Array;
	}
	virtual void push(A1& lhs)
	{
		if ((*this).IsFull()) throw logic_error("Stack is overflow");
		Array[last] = &lhs;
		last++;
	}
	virtual A1& pop()
	{
		if (this->IsEmpty()) throw logic_error("Stack is empty");
		A1* tmp = Array[last - 1];
		Array[last - 1] = 0;
		last--;
		return (*tmp);
	}
	int GetSize()
	{
		return size;
	}
	int GetFirst()
	{
		return first;
	}
protected:

A1** Array;
int size;
int first;
int last;
};