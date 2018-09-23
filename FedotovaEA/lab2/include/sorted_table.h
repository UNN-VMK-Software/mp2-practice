#pragma once

#include "table.h"

template <typename T>
class SortedTable : public Table<T>
{
protected:
	int BinSearch(const string& key1) const;
public:
	SortedTable(int j = 10) : Table(j) {}
	SortedTable(const SortedTable<T>& t) : Table(t) {}
	~SortedTable() {};
	void Insert(const T& data1, const string& key1) override;
	T& Search(const string& key1) override;
	void Delete(const string& key1) override;
};


///////////////////////////////////////////////////////////
template<typename T>
int SortedTable<T>::BinSearch(const string& key1) const
{
	int i = 0;
	int j = currrec - 1;
	int ser;
	while (i <= j)
	{
		ser = (j + i) / 2;
		if (key1 > tab[ser]->key)
			i = ser + 1;
		else
			j = ser - 1;
	}
	return i;
}

template<typename T>
void SortedTable<T>::Insert(const T& data1, const string& key1) 
{
	if(Isfull())
		Realloc();
	Reset();
	if (currrec)
	{
		int k = BinSearch(key1);
		if (k != currrec)
		{
			if (tab[k]->key != key1)
			{
				for (int i = currrec; i > k; i--)
					tab[i] = tab[i - 1];
				tab[k] = new Tabrecord<T>(key1, data1);
				currrec++;
			}
			else
				throw "error";
		}
		else
		{
			tab[k] = new Tabrecord<T>(key1, data1);
			currrec++;
		}
	}
	else
	{
		currind++;
		tab[currind] = new Tabrecord<T>(key1, data1);
		currrec++;
	}
}

template<typename T>
T& SortedTable<T>::Search(const string& key1) 
{
	Reset();
	if (currind > -1)
	{
		int i = BinSearch(key1);
		if (key1 == tab[i]->key)
			return tab[i]->data;
		else
			throw "error";
	}
	else
		throw "error";
}

template<typename T>
void SortedTable<T>::Delete(const string& key1)
{
	Reset();
	if (currrec)
	{
		int k = BinSearch(key1);
		if ((k < currrec) && (tab[k]->key == key1))
		{
			for (int i = k; i < currrec; i++)
				tab[i] = tab[i + 1];
			currrec--;
		}
		else
			throw "error";
	}
	else
		throw "error";
}
