#ifndef STACK_H
#define STACK_H

#include "List.h"

template<typename T>
class Stack
{
private:
	List<T> list;
public:
	Stack();
	Stack(const Stack<T>& stack);
	~Stack();
	void push(const T& t);
	T pop();
	bool IsEmpty()const;
	bool IsFull()const;

};
//==========================================================||==========================================================
template<typename T>
Stack<T>::Stack() {}
//==========================================================
template<typename T>
Stack<T>::~Stack() 
{
	list.~List();
}
//==========================================================
template<typename T>
Stack<T>::Stack(const Stack<T>& stack){
	list = List<T>(stack.list);
}
//==========================================================
template<typename T>
void Stack<T>::push(const T & t) 
{
	list.push_up(t);
}
//==========================================================
template<typename T>
T Stack<T>::pop() 
{
	T dat = T();
	try 
	{
		dat = list.pop_up();
	}
	catch (const char* ex) 
	{
		return T();
	}
	return dat;
}
//==========================================================
template<typename T>
bool Stack<T>::IsEmpty()const 
{
	if (list.get_size() == 0) 
	{
		return true;
	}
	return false;
}
//==========================================================
template<typename T>
bool Stack<T>::IsFull()const
{
	try 
	{
		list.push_up(T());
	}
	catch (const char* ex) 
	{
		return true;
	}
	list.pop();
	return false;
}
//==========================================================
#endif