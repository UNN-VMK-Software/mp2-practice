#ifndef STACK_H
#define STACK_H
#include "list.h"

template <typename T>
class Stack
{
private:
	List<T>* list;
public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();

	void Push(T);
	T Pop();
	T Take() const;
	bool IsEmpty() const;
	bool IsFull() const;
};

template <typename T>
Stack<T>::Stack()
{
	list = new List<T>;
};

template <typename T>
Stack<T>::Stack(const Stack&S)
{
	list = new List<T>(S.list);
};

template <typename T>
Stack<T>::~Stack()
{
	delete list;
};

template <typename T>
void Stack<T>::Push(T key)
{
	if (IsFull()) throw "Is Full";
	list->Add(key);
};

template <typename T>
T Stack<T>::Take()const
{

	return list->GetRoot();
};

template <typename T>
T Stack<T>::Pop()
{
	if (IsEmpty()) throw "Is Empty";
	T key = list->GetRoot();
	try {
		list->Remove(key);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	return key;
};

template <typename T>
bool Stack<T>::IsEmpty() const
{
	return(list->Size() == 0);
};
template <typename T>
bool Stack<T>::IsFull() const
{
	T key = -1;
	try {
		list -> Add(key);
		list->Remove(key);
	}
	catch (const char* ex)
	{
		return true;
	}
	return false;
};

#endif