#pragma once

#include "TLink.h"

template <typename T>
class TRingList
{
private:
	TLink <T> *head; // голова списка 
	TLink <T> *current; // текущей элемент в списке
public:
	TRingList(); // конструктор 
	TRingList(const TRingList <T> & TRingList2); // конструктор копирования
	~TRingList(); // деструктор 

	TRingList<T>& operator = (const TRingList<T>& TRingList2); // оператор копирования

	void Clean(); // очистка 
	void Insert(const T& data); // вставка в упорядоченный список
	void Reset(); // current указывает на head 
	void Next(); // сurrent = current.pNext 
	bool IsEnded() const ; // current последний в списке ? 
	TLink<T>* GetLink(); // вернуть current 

	bool operator == (const TRingList<T>& TRingList2) const; // оператор сравнения 
};

template <typename T>
TRingList<T>::TRingList()
{
	head = new TLink<T>();
	head->pNext = head;
	current = head;
}

template <typename T>
void TRingList<T>::Clean()
{
	if (head->pNext != head)
	{
		TLink<T> *tmp = head;
		TLink<T> *tmp2 = head->pNext;
		while (tmp2 != head)
		{
			tmp = tmp2->pNext;
			delete tmp2;
			tmp2 = tmp;
		}
	}
}

template <typename T>
TRingList<T>::~TRingList()
{
	this->Clean();
	delete head;
}

template <typename T>
TRingList<T>& TRingList<T>::operator = (const TRingList<T>& TRingList2)
{
	if (this != &TRingList2)
	{
		this->Clean();

		if (TRingList2.head->pNext == TRingList2.head)
		{
			head = new TLink<T>();
			head->pNext = head;
			current = head;
		}
		else
		{
			head = new TLink<T>(TRingList2.head->data, TRingList2.head->pNext);
			current = head;
			TLink<T> *tmp = TRingList2.head->pNext;
			while (tmp != TRingList2.head)
			{
				current->pNext = new TLink<T>(tmp->data);
				current = current->pNext;
				tmp = tmp->pNext;
			}
			current->pNext = head;
		}
	}

	return *this;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T> & TRingList2)
{
	if (TRingList2.head->pNext == TRingList2.head)
	{
		head = new TLink<T>();
		head->pNext = head;
		current = head;
	}
	else
	{
		head = new TLink<T>(TRingList2.head->data, TRingList2.head->pNext);
		current = head;
		TLink<T> *tmp = TRingList2.head->pNext;
		while (tmp != TRingList2.head)
		{
			current->pNext = new TLink<T>(tmp->data);
			current = current->pNext;
			tmp = tmp->pNext;
		}
		current->pNext = head;
	}
}

template <typename T>
void TRingList<T>::Insert(const T& data)
{
	if (head->pNext == head)
	{
		current = new TLink<T>(data, head);
		head->pNext = current;
	}
	else
	{
		current = head;

		while (current->pNext->data > data)
		{
			this->Next();
		}

		current->pNext = new TLink<T>(data, current->pNext);
	}
}

template <typename T>
void TRingList<T>::Reset()
{
	current = head->pNext;
}

template <typename T>
void TRingList<T>::Next()
{
	current = current->pNext;
}

template <typename T>
bool TRingList<T>::IsEnded() const
{
	if (current == head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
TLink<T>* TRingList<T>::GetLink()
{
	return current;
}

template <typename T>
bool TRingList<T>::operator == (const TRingList<T>& TRingList2) const
{
	TRingList<T> tmp(*this);
	TRingList<T> tmp2(TRingList2);

	tmp.Reset();
	tmp2.Reset();

	int k = 0;

	while ((tmp.IsEnded() == false) && (tmp2.IsEnded() == false))
	{
		if (tmp.GetLink()->data != tmp2.GetLink()->data)
		{
			k++;
		}
		tmp.Next();
		tmp2.Next();
	}

	if ((tmp.IsEnded() == false) && (tmp2.IsEnded() == true))
	{
		k++;
		tmp.Next();
	}

	if ((tmp.IsEnded() == true) && (tmp2.IsEnded() == false))
	{
		k++;
		tmp2.Next();
	}

	if (k == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}