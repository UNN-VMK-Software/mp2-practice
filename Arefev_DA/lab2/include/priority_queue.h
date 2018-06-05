#pragma once
#include "dheap.h"

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue() {};
	PriorityQueue(int Maxsize);
	virtual void push(T val);
    virtual T pop();
	//virtual T get();
	virtual bool IsEmpty();
	virtual void refresh();
};

template <typename T>
PriorityQueue<T>::PriorityQueue(int Maxsize)
{

}

template <typename T>
void PriorityQueue<T>::push(T val)
{
	
}

template <typename T>
void PriorityQueue<T>::refresh()
{

}

template <typename T>
T PriorityQueue<T>::pop()
{
	T tmp;
	return tmp;
}

//template <typename T>
//T PriorityQueue<T>::get()
//{
//  Edge tmp;
//	return tmp;
//}

template <typename T>
bool PriorityQueue<T>::IsEmpty()
{
	return true;
}