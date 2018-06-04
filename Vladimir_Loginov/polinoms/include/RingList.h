#ifndef TRINGLIST_H
#define TRINGLIST_H

#include "TLink.h"

template <typename T>
class TRingList {
private:
	TLink <T> *head;
	TLink <T> *current;
public:
	TRingList();
	TRingList(const TRingList <T> &);
	~TRingList();
	void Insert(const T _data);
	void InsertInEnd(const T datum);
	void Reset();
	void Clean();
	bool IsEnded() const; //const
	TRingList<T>& operator=(const TRingList<T>& _TRingList);
	bool operator==(const TRingList<T>& list2) const;
	bool operator<(const TRingList<T>& list2) const;
	bool operator>(const TRingList<T>& list2) const;
	bool operator!=(const TRingList<T>& list2) const { return !((*this) == list2);  }
	TLink<T>* GetNext();
	TLink<T>* Search(const TLink<T>& d);
	void Delete(const T & d);
	TLink<T>* GetCurrent() { return current; }

};

template <typename T>
TRingList<T>::TRingList()
{
	head = new TLink<T>();
	head->pNext = head;
	current = head;
};

template <typename T>
TLink<T>* TRingList<T>::Search(const TLink<T> & d)
{
	TLink<T>* tmp = head;
	while ((tmp->pNext != head) && (tmp->pNext->data != d.data))
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == head)
	{
		return nullptr;
	}
	return tmp->pNext;
};

template<typename T>
void TRingList<T>::Delete(const T & d)
{
	TLink<T>* tmp = head;
	TLink<T>* tmp2 = head->pNext;
	if (tmp != tmp2)
	{
		while ((tmp2->pNext != head) && (tmp2->data != d))
		{
			tmp = tmp2;
			tmp2 = tmp2->pNext;
		}
		if (tmp2->data == d)
		{	
			tmp->pNext = tmp2->pNext;
			delete tmp2;
		}
		else throw "element does not exist in your list";
	}
	else throw "element does not exist in your list";
};


template <typename T>
TRingList<T>::TRingList(const TRingList <T> & Ring)
{
	if (Ring.head->pNext != Ring.head)
	{
		head = new TLink<T> (Ring.head->data);
		TLink<T> *temp = head;
		TLink<T> *temp2 = Ring.head->pNext;
		while (temp2 != Ring.head)
		{
			temp->pNext = new TLink<T>(temp2->data, head);
			temp = temp->pNext;
			temp2 = temp2->pNext;
		}
	}
	else {
		head = new TLink<T>(Ring.head->data);
		current = head;
		head->pNext = head;
	}
};

template<typename T>
TRingList<T>::~TRingList()
{
	Clean();
	delete head;
};

template <typename T>
void TRingList<T>::Insert(const T datum)
{
	if (head->pNext == head) 
	{
		TLink<T>* tmp = new TLink<T>(datum, head);
		head->pNext = tmp;
	}
	else
	{
		TLink<T>* prev = head;
		TLink<T>* tmp = head->pNext;
		while ((tmp != head) && (datum < tmp->data))  
		{
			prev = tmp;
			tmp = tmp->pNext;
		}
		prev->pNext = new TLink<T>(datum, tmp);
	}
};

template <typename T>
void TRingList<T>::InsertInEnd(const T datum)
{
	TLink<T>* tmp = head;
	while (tmp->pNext != head)
			tmp = tmp->pNext;
	tmp->pNext = new TLink<T>(datum, head);	
};

template <typename T>
void TRingList<T>::Reset()
{
	current = head->pNext;
};

template<typename T>
void TRingList<T>::Clean()
{
	TLink<T> *temp = head->pNext;
	TLink<T> *temp2 = head;
	while (temp != head)
	{
		temp2 = temp->pNext;
		delete temp;
		temp = temp2;
	}

	head->pNext = head;
};

template<typename T>
bool TRingList<T>::IsEnded() const
{
	return (current == head);
};

template<typename T>
TRingList<T>& TRingList<T>::operator=(const TRingList<T> & Ring)
{
	
	if ((*this) != Ring)
	{
		Clean();
		if (Ring.head->pNext != Ring.head)
		{
			head = new TLink<T>(Ring.head->data);
			TLink<T> *temp = head;
			TLink<T> *temp2 = Ring.head->pNext;
			while (temp2 != Ring.head)
			{
				temp->pNext = new TLink<T>(temp2->data, head);
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
	return *this;
};

template<typename T>
bool TRingList<T>::operator==(const TRingList<T> & list2) const
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = list2.head;
	bool f = true;
	if ((temp->pNext == head) && (temp2->pNext == list2.head))
		f = true;
	else if (((temp->pNext != head) && (temp2->pNext == list2.head)) || ((temp2->pNext != list2.head) && (temp->pNext == head)))
		f = false;
	while ((temp->pNext != head) && (temp2->pNext != list2.head) && (f))
	{
		if (temp->data != temp2->data)
			f = false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	return f;
};

template<typename T>
bool TRingList<T>::operator<(const TRingList<T> & list2) const
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = list2.head;
	bool f = true;
	if ((temp->pNext == head) && (temp2->pNext == list2.head))
		f = false;
	else if ((temp->pNext != head) && (temp2->pNext == list2.head))
		f = false;
	else if ((temp2->pNext != list2.head) && (temp->pNext == head))
		f = true;
	while ((temp->pNext != head) && (temp2->pNext != list2.head) && (f))
	{
		if ((temp->data > temp2->data) || (temp->data == temp2->data))
			f = false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	return f;
};

template<typename T>
bool TRingList<T>::operator>(const TRingList<T> & list2) const
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = list2.head;
	bool f = true;
	if ((temp->pNext == head) && (temp2->pNext == list2.head))
		f = true;
	else if ((temp->pNext != head) && (temp2->pNext == list2.head))
		f = true;
	else if ((temp2->pNext != list2.head) && (temp->pNext == head))
		f = false;
	while ((temp->pNext != head) && (temp2->pNext != list2.head) && (f))
	{
		if ((temp->data < temp2->data) || (temp->data == temp2->data))
			f = false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	return f;
};

template <typename T>
TLink<T>* TRingList<T>::GetNext()
{
	current = current->pNext;
	return current;
};

#endif
