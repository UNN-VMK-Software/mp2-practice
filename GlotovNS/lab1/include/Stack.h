#pragma once 

#include "List.h"

template <class valtype>

class Stack 
{
private:
	List<valtype> *list;
public:
	Stack();
	Stack(const Stack<valtype> &s);
	~Stack();
	int isEmpty() const;
	int isFull() const;
	void push(valtype key);
	valtype pop();
	valtype look();
};


template <class valtype>
Stack<valtype>::Stack()
{
	list = new List<valtype>();
}

template <class valtype>
Stack<valtype>::Stack(const Stack<valtype> &s)
{
	this->list = new List<valtype>(*(s.list));
}

template <class valtype>
Stack<valtype>::~Stack()
{
	delete this->list;
}

template <class valtype>
int Stack<valtype>::isEmpty() const
{
	return list->getFirst() == 0;
}

template <class valtype>
int Stack<valtype>::isFull() const
{
	NODE<valtype> *tmp;
	try {
		tmp = new NODE<valtype>;
	}
	catch (...) {
		return 1;
	}
	delete tmp;
	return 0;
}

template <class valtype>
void Stack<valtype>::push(valtype key)
{
	if (isFull()) throw "Стэк полон!";
	list->insertFirst(key);
}

template <class valtype>
valtype Stack<valtype>::pop()
{
	if (isEmpty()) throw "Стэк пуст!";
	valtype result = list->getFirst()->key;
	list->erase(result);
	return result;
}

template <class valtype>
valtype Stack<valtype>::look()
{
	if (isEmpty()) throw "Стэк пуст!";
	return list->getFirst()->key;
}