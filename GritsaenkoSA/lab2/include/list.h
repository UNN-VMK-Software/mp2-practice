#pragma once
#include "node.h"
#include <iostream>

using namespace std;

//Шаблон класса Циклический список с головой
template<class T>
class list
{
private:
	node<T>* head; 	//голова
	node<T>* Current;//Указатель на текущий					
public:
	list();											//Конструктор по умолчанию
	~list();										//Деструктор
	void Clean();									//очистка списка
	list(const list<T>& src);						//Конструктор копирования
	list<T>& operator=(const list<T>& temp);		//Перегрузка оператора присваивания
	void InsertInOrder(T elem);						//Вставка в упорядоченный список
	void InsertAfter(node<T>* temp1, const T& temp2);//вставка после
	void InsertToTail(T elem);						//вставка в конец
	
	bool IsEmpty() const;							//проверка на пустоту

	node<T>* GetCurr() const { return Current; }	//Получение текущего адреса+
	void Reset() { Current = head->next; }			//Установка на начало+

	void gonext();									//переход на следующее звено
	bool IsOver() const { return (Current == head); }// проверка на  конец
	
	bool operator==(const list<T>& var) const;								//Оператор сравнения ==
	bool operator!=(const list<T>& temp) const { return !(*this == temp); }	//Оператор сравнения не равно	
};



template <class T>//Очистка списка
void list<T>::Clean()
{
	node<T>* curr = head->next;
		while (curr != head)
		{
			node<T>* temp = curr->next;
			delete curr;
			curr = temp;
		}
		head->next = head;//вернуть указатель на head
}


template <class T>//Конструктор по умолчанию
list<T>::list()
{
	head = new node<T>;
	head->next = head;
	Current = head;
}



template <class T>//Деструктор
list<T>::~list()
{
	Clean();
	delete head;
}

template<class T>//переход на следующий
 void list<T>::gonext()
{
	Current = Current->next;
}


template <class T>//Конструктор копирования
list<T>::list(const list<T>& src) //: list()
{	
	head = new node<T>;
	head->next = head;
	Current = head;
	if (src.IsEmpty())
	{		
		return;
	}
	node<T>* psrc = src.head;
	node<T>* pcur = head;
	while (psrc->next != src.head)
	{
		psrc = psrc->next;
		pcur->next = new node<T>(psrc->data);		
		pcur = pcur->next;
	} 
	pcur->next = head;
	Current = head;		
}

template <class T>// проверка на пустоту
bool list<T>::IsEmpty() const
{
	
		return (head->next == head);
}



template <class T>//Оператор присваивания
list<T>& list<T>::operator=(const list<T>& temp) 
{
	Clean();
	node<T>* ptemp = temp.head;
	node<T>* pcurr = head;
	while (ptemp->next != temp.head)
	{
		ptemp = ptemp->next;
		pcurr->next = new node<T>(ptemp->data);
		pcurr = pcurr->next;
	}
	pcurr->next = head;
	Current = head->next;
	return *this;
}


template <class T>//Вставка в упорядоченный список
void list<T>::InsertInOrder(T elem)
{
	if (IsEmpty())
	{
		head->next= new node<T>(elem);
		head->next->next=head;
	}
	else 
	{
		node<T>* temp = new node<T>(elem);
		node<T>* curr = head;

		while (curr->next != head && (*(curr->next) < *temp))
		{
			curr = curr->next;
		}
		node<T>* temp1 = curr->next;
		curr->next = temp;
		curr->next->next = temp1;
	}
}
//вставка в конец
template<class T>
void list<T> :: InsertToTail(T elem)
{
	Reset();
	while (Current ->next != head)
		gonext();
	node<T>* temp = Current->next;
	Current->next = new node<T>(elem);
	Current->next->next = temp;
}

template <class T>//вставка после
void list<T>::InsertAfter(node<T>* temp1, const T& d)
{
	if (head == NULL)
		throw "list is empty";
	else 
	{
		node<T>* temp = temp1->next;
		temp1->next = new node<T>(d, temp);
	}
}



template<class T>//Оператор сравнения
bool list<T>::operator==(const list<T>& var) const
{
	bool res = true;
	if (this != &var)
	{
		node<T>* temp1 = var.head->next;
		node<T>* temp2 = head->next;
		while (temp1->data == temp2->data && temp2 != head && temp1 != var.head)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp2 != head || temp1 != var.head)
			res = false;
	}
	return res;
}
