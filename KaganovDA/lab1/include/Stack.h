#ifndef POLISH_STACK_H
#define POLISH_STACK_H

#include "List.h"
#include <iostream>
using namespace std;

template <typename TKey>

class Stack {
private:
	List<TKey>* list;
public:
	Stack();
	Stack(const Stack<TKey>&);
	~Stack();
	void Push(TKey);				//добавление элемента
	TKey Pop();						//изъятие элемента
	TKey Take()const;				//возвращение элемента без его изъятия
	bool IsEmpty()const;			//проверка стека на пустоту
	bool IsFull()const;				//проверка стека на полнату
};

template <typename TKey>
Stack<TKey>::Stack() {
	list = new List<TKey>;
};

template <typename TKey>
Stack<TKey>::~Stack() {
	delete list;
};

template <typename TKey>
Stack<TKey>::Stack(const Stack<TKey>& S) {
	list = new List<TKey>(S.list);
};

template <typename TKey>
void Stack<TKey>::Push(TKey key) {
	if (IsFull())
		throw "Stack Is Full";
	list->Add(key);
};

template <typename TKey>
TKey Stack<TKey>::Pop() {
	if (IsEmpty())
		throw "Stack Is Empty";
	TKey key = list->GetRoot();
	try {
		list->Remove(key);
	}
	catch (const char* error) {
		cout << error << endl;
	}
	return key;
};

template <typename TKey>
TKey Stack<TKey>::Take()const {
	if (IsEmpty())
		throw "Stack Is Empty";
	return List.GetRoot();
};

template <typename TKey>
bool Stack<TKey>::IsEmpty()const {
	return(list->Size() == 0);
};

template <typename TKey>
bool Stack<TKey>::IsFull()const {
	TKey key = -1;
	try {
		list->Add(key);
		list->Remove(key);
	}
	catch (...) {
		return true;
	}
	return false;
};

#endif