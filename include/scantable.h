#pragma once
#include "table.h"

template <class type>
class scantable :public table <type> {
protected:	
	line<type>* stab;
	void Realloc()override;
	bool BSearch(const string k);			//true если элемент найдет. для Insert	
public:	
	scantable(int sizeT=DEFAULTSIZE) : table(sizeT) { stab = new line<type>[sizeT]; }
	~scantable() { delete[] stab; }	
	void Insert(const string k, const type& d) override;
	void Delete(const string k) override;
	type Search(const string k) override;	
	void Reset() override;			
	bool IsTabEnded() override;
	void GetNext()override;
	type GetCurrent() override;	
};

template<class type> void scantable<type>::Reset() {
	if (!IsEmpty())
		ind = 0;
	else 
		throw "empty table";
}

template <class type> void scantable<type>::GetNext() {				
	if (!IsTabEnded())
		ind++;
	else
		throw "not found";
}

template<class type> bool scantable<type>::IsTabEnded() {			
		return (ind >= size - 1);	
}

template<class type> type scantable<type>::GetCurrent() {
	if (ind <= size - 1)
	return *(stab[ind].data);
	else
		throw "not found";
}

template <class type> type scantable<type>::Search(const string k) {
	int i = 0;
	while (i < size && stab[i].key != k)
		i++;
	if (i == size)
		throw "not found";
	else
		return *(stab[i].data);
}

template <class type> bool scantable<type>::BSearch(const string k) {
	int i = 0;
	bool res = false;
	while (i < size && stab[i].key != k)
		i++;
	if (i != size && stab[i].key == k)
		res = true;
	return res;
}
 
template <class type> void scantable<type>::Insert(const string k, const type& d) {	
	if (!BSearch(k))
	{
		if (size == maxsize)
			Realloc();	
		stab[size] = line<type>(k, d);
		size++;
	}
	else 
		throw "repeated key";
}

template <class type> void scantable<type>::Delete(const string k) {
	int i = 0;
	while (i < size && stab[i].key != k)
		i++;
	if (i == size)
		throw "not found";
	else
		size--;
	stab[i] = stab[size];
}

template <class type> void scantable<type>::Realloc() {
	maxsize *= 2;
	line<type>* temp = new line<type>[maxsize];
	for (int i = 0; i < size; i++)
		temp[i] = stab[i];
	delete[] stab;
	stab = temp;
}

