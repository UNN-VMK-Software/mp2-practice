#pragma once
#include "table.h"
#include "scantable.h"

template <class type>
class sortedtable :public table <type> {
protected:	
	int BinSearch(const string k);
	void Realloc()override;
	line<type>* stab;
public:	
	sortedtable(int sizeT= DEFAULTSIZE) : table(sizeT) { stab = new line<type>[sizeT]; }
	~sortedtable() { delete[] stab; }
	sortedtable(const scantable<type> & t); // преобрпзование таблицы типа scantable к sortedtable
	void Insert(const string k, const type& d) override;
	void Delete(const string k) override;
	type Search(const string k) override;	
	void Reset() override;
	bool IsTabEnded() override;
	void GetNext()override;
	line<type> GetCurrent() override;	
	template<class type> friend ostream& operator<<(ostream& os, sortedtable<type>& t);
};

template <class type> sortedtable<type>::sortedtable(const scantable<type> & t): table (t.maxsize){
	stab = new line<type>[maxsize];
	for (int i = 0; i < size; i++)
		Insert(t.stab[i].key, *(t.stab[i].data));

}

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
		Reset();
}

template<class type> bool sortedtable<type>::IsTabEnded() {
	return (ind >= size - 1);
}

template<class type> line<type> sortedtable<type>::GetCurrent() {
	if (ind <= size - 1)
		return stab[ind];
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
		return  *(stab[pos].data);
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

template<class type> ostream& operator<<(ostream& os,  sortedtable<type>& t) {
	if (t.size != 0)
	{
		t.Reset();
		os << setw(WIDTHFIRSTCOLUMN) << left << t.GetCurrent().key << *(t.GetCurrent().data) << endl;
		while (!t.IsTabEnded())
		{
			t.GetNext();
			os << setw(WIDTHFIRSTCOLUMN) << left << t.GetCurrent().key << *(t.GetCurrent().data) << endl;
		}
	}
	return os;
}