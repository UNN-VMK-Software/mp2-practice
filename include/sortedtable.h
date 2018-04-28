#pragma once
#include "table.h"

template <class type>
class sortedtable :public table <type> {
protected:
	line<type>* stab;
	int BinSearch(const string k);
	void Realloc()override;
public:	
	sortedtable(int sizeT) : table(sizeT) { stab = new line<type>[sizeT]; }
	~sortedtable() { delete[] stab; }
	void Insert(const string k, const type& d) override;
	void Delete(const string k) override;
	type Search(const string k) override;	
	void Reset() override;
	bool IsTabEnded() override;
	void GetNext()override;
	type GetCurrent() override;
};

template <class type> void sortedtable<type>::Reset() {
	if (!IsEmpty())
		ind = 0;
	else
		throw "empty table";
}

template <class type> void sortedtable<type>::GetNext() {		
	if (!IsTabEnded())
		ind++;
	else
		throw "not found";
}

template<class type> bool sortedtable<type>::IsTabEnded() {
	return (ind >= size - 1);
}

template<class type> type sortedtable<type>::GetCurrent() {
	if (!IsTabEnded())
		return stab[ind].data;
	else
		throw "not found";
}

template <class type> int sortedtable<type>::BinSearch(const string k) {
	int st = 0, fn = size - 1, mid;
	while (st <= fn)
	{
		mid = (st + fn) / 2;
		if (k > stab[mid].key)
			st = mid + 1;
		else fn = mid - 1;
	}
	return st;
}

template <class type> void sortedtable<type>::Insert(const string k, const type& d) {
	int pos = BinSearch(k);
	if ((pos < size && stab[pos].key != k) || pos==size)
	{
		if (size == maxsize)
			Realloc();
		for (int i = size - 1; i >= pos; i--)
			stab[i + 1] = stab[i];
		size++;
		stab[pos] = line<type>(k, d);
	}
	else
		throw "repeated key";
}

template <class type> type sortedtable<type>::Search(const string k) {		
	int pos = BinSearch(k);
	if (pos < size && stab[pos].key == k)
		return  stab[pos].data;
	else 
		throw "not found";
}

template <class type> void sortedtable<type>::Delete(const string k) {	
	int pos = BinSearch(k);
	if (pos<size && stab[pos].key == k)
	{
		size--;
		for (int i = pos; i < size; i++)
			stab[i] = stab[i + 1];
	}
	else 
		throw "not found";
}

template <class type> void sortedtable<type>::Realloc() {
	maxsize *= 2;
	line<type>* temp = new line<type>[maxsize];
	for (int i = 0; i < size; i++)
		temp[i] = stab[i];
	delete[] stab;
	stab = temp;
}