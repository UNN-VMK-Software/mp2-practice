#pragma once
#include "table.h"

#include <iostream>

using namespace std;

template <class type>
class sortedtable :public table <type> 
{
protected:
	record<type>* z;
	int BSearch(const string k);
	void Realloc() override;
public:
	sortedtable(int any_size = S) : table(any_size) { z = new record<type>[maxsize]; }
	sortedtable(const scantable<type>& st);            //Конструктор копирования
	~sortedtable() {delete[] z;}

	type* Search(const string& k) override;
	void Insert(const string& k, const type& d) override;
	void Delete(const string& k) override;
	
	record<type> GetCurrent() const override;

	template<class t> friend ostream& operator<<(ostream& os, sortedtable<t>& tab);
};


template <class type> void sortedtable<type>::Realloc()
{
	maxsize *= 1.5;
	record<type>* new_z = new record<type>[maxsize];
	for (int i = 0; i < cursize; i++)
		new_z[i] = z[i];
	delete[] z;
	z = new_z;
}

template <class type> int sortedtable<type>::BSearch(const string k)
{
	int start = 0;
	int finish = cursize - 1;
	int centre;
	while (start <= finish)                   // 0...n
	{
		centre = (start + finish) / 2;
		if (k <= z[centre].key)
			finish = centre - 1;
			
		else
			start = centre + 1;
	}
	return start;
}


template <class type> sortedtable<type>::sortedtable(const scantable<type> & st) : table(st.maxsize)
{
	for (int i = 0; i < st.cursize; i++)
		Insert(st.z[i].key, *(st.z[i].data));
	Reset();
}

template <class type> type* sortedtable<type>::Search(const string& k) 
{
	int p = BSearch(k);
	if (z[p].key == k && p < cursize)
		return  z[p].data;
	else
		throw "Data with this key was not found";
}


template <class type> void sortedtable<type>::Insert(const string& k, const type& d) 
{
	if (cursize == maxsize)
			Realloc();
	int p = BSearch(k);
	if ( z[p].key != k)
	{
		for (int i = cursize; i > p; i--)
			z[i] = z[i-1];
		cursize++;
		z[p] = record<type>(k, d);
	}
	else
		throw "this key already exists";
}


template <class type> void sortedtable<type>::Delete(const string& k)
{
	int p = BSearch(k);
	if (p < cursize && z[p].key == k)
	{
		for (int i = p; i < cursize - 1; i++)
			z[i] = z[i + 1];
		cursize--;
	}
	else
		throw "Data with this key was not found";
}


template<class type> record<type> sortedtable<type>::GetCurrent() const
{
	if (idx < cursize)
		return z[idx];
	else
		throw "Not found";
}

template<class type> ostream& operator<<(ostream& os, sortedtable<type>& tab)
{
	if (tab.cursize)
	{
		tab.Reset();
		os << tab.GetCurrent().key << "                               " << *(tab.GetCurrent().data) << endl;
		while (!tab.IsTabEnded())
		{
			tab.GetNext();
			os << tab.GetCurrent().key << "                               " << *(tab.GetCurrent().data) << endl;
		}
	}
	else
		os << "Empty table" << endl;
	return os;
}
