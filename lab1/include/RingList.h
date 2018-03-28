#pragma once
#include "TLink.h"

template <typename T>
class TRingList {
private:
	TLink <T> *head;
public:
	TLink <T> *current;
	TRingList();
	TRingList(const TRingList <T> &);
	~TRingList();
	void Insert(const T _data);
	void InsertInEnd(const T datum);
	void Reset();
	void Clean();
	bool IsEnded();
	TRingList<T>& operator=(const TRingList<T>& _TRingList);
	bool operator==(const TRingList<T>& list2) const;
	TLink<T>* GetNext();
	TLink<T>* Search(const TLink<T>& d);
};

template <typename T>
TRingList<T>::TRingList()
{
	head = new TLink<T>();
	head->pNext = head;
	//current = head;
}
template <typename T>
TLink<T>* TRingList<T>::Search(const TLink<T> & d)
{
	TLink<T>* tmp = head;
	if (tmp->pNext != head)
	{
		while ((tmp->pNext != head) && (tmp->data != d.data))
		{
			tmp = tmp->pNext;
		}
		if (tmp->data == d.data)
			return tmp;
		else
			return NULL;
	}
	else
		return NULL;
}
template <typename T>
TRingList<T>::TRingList(const TRingList <T> & Ring)
{
	if (Ring.head->pNext != head)
	{
		head = new TLink<T>(Ring.head->data, Ring.head);
		TLink<T> *temp = head;
		TLink<T> *temp2 = Ring.head->pNext;
		while (temp2 != head)
		{
			temp->pNext = new TLink<T>(temp2->data, Ring.head);
			temp = temp->pNext;
			temp2 = temp2->pNext;
		}
	}
	else {
		head = new TLink<T>(Ring.head->data);
		current = head;
		head->pNext = head;
	}
}
template<typename T>
TRingList<T>::~TRingList()
{
	/*Clean();
	TLink<T> *temp = head;
	delete temp;*/
	TLink<T> *temp = head;
	TLink<T> *temp2 = head;
	if (temp != NULL)
	{
		while (temp->pNext != head)
		{
			temp2 = temp->pNext;
			delete temp;
			temp = temp2;
		}
		delete temp;
	}
}

template <typename T>
void TRingList<T>::Insert(const T datum)
{
	if (head->pNext == head) // проблема с доступом к голове
	{
		TLink<T>* tmp = new TLink<T>(datum, head);
		head->pNext = tmp;
	}
	else
	{
		TLink<T>* prev = head;
		TLink<T>* tmp = head->pNext;
		while ((tmp != head) && (datum < tmp->data)) // сравнение степеней, второй моном не определен
		{
			prev = tmp;
			tmp = tmp->pNext;
		}
		prev->pNext = new TLink<T>(datum, tmp);
	}
}
template <typename T>
void TRingList<T>::InsertInEnd(const T datum)
{
	TLink<T>* tmp = head;
	if (head->pNext != head)
	{
		while (tmp->pNext != head)
			tmp = tmp->pNext;
		tmp = new TLink<T>(datum);
		tmp->pNext = head;
	}
	else
	{
		tmp = new TLink<T>(datum, head);
		head->pNext = tmp;
	}
}

template <typename T>
void TRingList<T>::Reset()
{
	current = head->pNext;
}

template<typename T>
inline void TRingList<T>::Clean()
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = head;
	if (temp->pNext != head)
	{
		while (temp->pNext != head)
		{
			temp2 = temp->pNext;
			delete temp;
			temp = temp2;
		}
		head->pNext = head;
	}
}

template<typename T>
bool TRingList<T>::IsEnded()
{
	return (current == head);
}

template<typename T>
TRingList<T>& TRingList<T>::operator=(const TRingList<T> & _TRingList)
{
	TLink<T>* tmp = head;
	if (this != &_TRingList)
	{
		Clean();
		if (_TRingList.head->pNext != _TRingList.head)
		{
			head = _TRingList.head;
			TLink<T> *temp = head;
			TLink<T> *temp2 = _TRingList.head->pNext;
			while (temp2 != head)
			{
				temp->pNext = new TLink<T>(temp2->data);
				temp = temp->pNext;
				temp2 = temp2->pNext;
			}
		}
	}
	return *this;
}

template<typename T>
bool TRingList<T>::operator==(const TRingList<T> & list2) const
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = list2.head;
	bool f = true;
	if ((temp->pNext == head) && (temp2->pNext == list2.head))
		f = true;
	else if ((temp->pNext != head) || (temp2->pNext != list2.head))
		f = false;
	while ((temp->pNext != head) && (temp2->pNext != list2.head) && (f))
	{
		if (temp->data != temp2->data)
			f = false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	return f;
}



template <typename T>
TLink<T>* TRingList<T>::GetNext()
{
	current = current->pNext;
	return current;
};
