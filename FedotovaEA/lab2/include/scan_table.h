#pragma once

#include "table.h"

template<typename T>
class Scantable : public Table<T>
{
public:
	Scantable(int j = 10) : Table(j) {};
	Scantable(const Scantable<T>& t) : Table(t) {}
	~Scantable() {}
	void Insert(const T& data1, const string& key1) override;
	T& Search(const string& key1) override;
	void Delete(const string& key1) override;
};


template<typename T>
void Scantable<T>::Insert(const T& data1, const string& key1)
{
	if(Isfull())
		Realloc();
	Reset();
	if (currrec)
	{
		while ((currind < currrec) && (tab[currind]->key != key1))
			currind++;
		if (currind == currrec)
		{
			tab[currind] = new Tabrecord<T>(key1, data1);
			currrec++;
		}
		else
			throw "error";
	}
	else
	{
		currind++;
		tab[currind] = new Tabrecord<T>(key1, data1);
		currrec++;
	}
}

template<typename T>
T& Scantable<T>::Search(const string &key1)
{
	Reset();
	if (currind > -1)
	{
		while((tab[currind]->key != key1) && (currind < currrec))
			TGetnext();
		if (currind < currrec)
			return tab[currind]->data;
		else
			throw "error";
	}
	else
		throw "error";
}

template<typename T>
void Scantable<T>::Delete(const string& key1)
{
	Reset();
	if (currind > -1)
	{
		while ((currind < currrec) && (tab[currind]->key != key1))
			currind++;
		if (currrec && (currind < currrec))
		{
			if (currrec > 1)
				tab[currind] = tab[--currrec];
			else
				currrec = 0;
		}
		else
			throw "error";
	}
	else
		throw "error";
}







