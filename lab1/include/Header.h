#pragma once
#include <stdio.h>
using namespace std;
struct Tmonom {
	double cf;
	unsigned int abc;
	Tmonom(const double d = 0, const unsigned int m = 0) { cf = d; abc = m; }
	const Tmonom& operator = (const Tmonom& _Tmonom)
	{
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
		return *this;
	}
};

template <typename T>
class TLink {
public:
	T data;
	TLink<T>* pNext;
	TLink(const T datum, TLink<T>* link = NULL const) { data = datum; pNext = link; }
	TLink<T>& operator=(const TLink& _TLink);
};
template <typename T>
class TRingList {
private:
	TLink <T> *head;
	TLink <T> *current; 
public:
	TRingList<T>();
	TRingList<T>(const TRingList <T> &);
	~TRingList<T>();
	void Insert(const TLink& _TLink);
	void InsertInEnd();
	void InsertInBegining();
	void Sort();
	void Reset(); // ???
	bool IsEnded();
	TLink<T> GetNext();
	template <typename T>
	TRingList<T>::TRingList()
	{
		head = *TLink tmp;
		head->pNext = head;
		current = NULL;
	}
	template <typename T>
	TRingList<T>::TRingList(const TRingList <T> & Ring)
	{
		if (Ring.head->pNext != head)
		{
			head = new TLink(Ring.head->data);
			TLink *temp = head;
			TLink *temp2 = Ring.head->pNext;
			while (temp2 != head)
			{
				temp->next = new TLink(temp2->data);
				temp = temp->pNext;
				temp2 = temp2->pNext;
			}
		}
		else {
			head = *TLink tmp;
			current = NULL;
			head->pNext = head;
		}
	}
	template<typename T>
	TRingList<T>::~TRingList()
	{
		TLink *temp = head;
		TLink *temp2 = head;
		while (temp->pNext != head)
		{
			temp2 = temp->pNext;
			delete temp;
			temp = temp2;
		}
		delete temp;
	}
	template <typename T>
	const TLink<T>& TLink<T>::operator=(const TLink<T>& _TLink)
	{
		data = _TLink.data;
		pNext = _TLink.pNext;
		return *this;
	}

	template <typename T>
	void TRingList<T>::Insert(const TLink& _TLink, const T datum&)
	{
		Node* tmp = new Node(d, node->next);
		node->next = tmp;
	}
	template <typename T>
	void TRingList<T>::InsertInEnd()
	{

	}
	template<typename T>
	void TRingList<T>::InsertInBegining()
	{

	}
	template <typename T>
	void TRingList<T>::Sort()
	{

	}
	template <typename T>
	void TRingList<T>::Reset()
	{

	}

	template<typename T>
	bool TRingList<T>::IsEnded()
	{
		return false;
	}


	template <typename T>
	TLink<T> TRingList<T>::GetNext()
	{

	}
};

template <typename T>
class TPolinom {
private:
	TRingList <T> *monoms;
public:
	TPolinom<T>(const string);
	TPolinom<T>(const TPolinom&);
	~Tpolinom();
	TPolinom<T> operator+ (const TPolinom &);
	TPolinom<T> operator* (const TPolinom&);
	TPolinom<T> operator* (double d);
	const TPolinom<T>& operator =(const TPolinom&);
	template <typename T>
	TPolinom<T>::TPolinom<T>(const string s)
	{

	}
	template <typename T>
	TPolinom<T>::TPolinom<T>(const TPolinom&)
	{

	}
	template <typename T>
	TPolinom<T>::~Tpolinom<T>()
	{

	}
	template <typename T>
	TPolinom<T> TPolinom<T>::operator+ (const TPolinom &)
	{

	}
	template <typename T>
	TPolinom<T> TPolinom<T>::operator* (const TPolinom&)
	{

	}
	template <typename T>
	TPolinom<T> TPolinom<T>::operator* (double d)
	{

	}
	template <typename T>
	const TPolinom<T>& TPolinom<T>::operator =(const TPolinom&)
	{

	}
};