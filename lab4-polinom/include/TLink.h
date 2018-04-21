#pragma once

#include "TMonom.h"

template <typename T>
class TLink
{
public:
	T data;
	TLink* pNext;

	TLink();
	TLink(const TLink& unit);
	TLink(T d, TLink* unit= NULL);
	~TLink() {}

	TLink& operator = (const TLink& unit);
	bool operator == (const TLink& unit) const;
	bool operator != (const TLink& unit) const;
};

template <typename T>
TLink<T>::TLink()
{
	pNext = NULL;
}

template <typename T>
TLink<T>::TLink(const TLink& unit)
{
	data = unit.data;
	pNext = unit.pNext;
}

template <typename T>
TLink<T>::TLink(T d, TLink* unit)
{
	data = d;
	pNext = unit;
}

template <typename T>
TLink<T>& TLink<T>::operator=(const TLink& unit)
{
	data = unit.data;
	pNext = unit.pNext;
	return *this;
}

template <typename T>
bool TLink<T>::operator== (const TLink& unit) const
{
	int k = 0;

	if (data != unit.data)
		k++;

	if (pNext != unit.pNext)
		k++;

	if (k == 0)
		return true;
	else
		return false;
}

template <typename T>
bool TLink<T>::operator!= (const TLink& unit) const
{
	int k = 0;

	if (data == unit.data)
		k++;

	if (pNext == unit.pNext)
		k++;

	if (k != 0)
		return true;
	else
		return false;
}