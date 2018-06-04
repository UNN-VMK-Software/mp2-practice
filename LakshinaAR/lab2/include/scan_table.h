#pragma once
#include "table.h"

template <class type>
class scantable :public table <type> 
{
protected:
	record<type>* z;	
	void Realloc() override;
public:
	scantable(int any_size = S) : table(any_size) { z = new record<type>[maxsize]; }
	~scantable() {delete[] z;}

	type* Search(const string& k) override;
	void Insert(const string& k, const type& d) override;
	void Delete(const string& k) override;

	record<type> GetCurrent() const override;
	
	template<class t> friend ostream& operator<<(ostream& os, scantable<t>& tab);
};

template <class type> void scantable<type>::Realloc()
{
	maxsize *= 1.5;
	record<type>* new_z = new record<type>[maxsize];
	for (int i = 0; i < cursize; i++)
		new_z[i] = z[i];
	delete[] z;
	z = new_z;
}


template <class type> type* scantable<type>::Search(const string& k)
{
	int i = 0;
	while (i < cursize && z[i].key != k)
		i++;
	if (i < cursize)
		return z[i].data;                                  
	else
		throw "Data with this key was not found";
}


template <class type> void scantable<type>::Insert(const string& k, const type& d)
{
	int i = 0;
	bool r = true;
	while (i < cursize && z[i].key != k)
		i++;
	if (i != cursize && z[i].key == k)
		r = false;


	if (r)
	{
		if (cursize == maxsize)
			Realloc();
		z[cursize] = record<type>(k, d);
		cursize++;
	}
	else
		throw "This key has already been entered earlier";
}


template <class type> void scantable<type>::Delete(const string& k)
{
	int i = 0;
	while (i < cursize && z[i].key != k)
		i++;
	if (i < cursize)
		z[i] = z[--cursize];
	else
		throw "Data with this key was not found";
}


template<class type> record<type> scantable<type>::GetCurrent() const
{
	if (idx < cursize )        
		return z[idx];
	else
		throw "Not found";
}

template<class type> ostream& operator<<(ostream& os, scantable<type>& tab)
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
