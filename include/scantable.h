#pragma once
#include "table.h"

template <class type>
class scantable :public table <type> {
protected:	

public:
	line<type>* stab;
	scantable(int sizeT) : table(sizeT) { stab = new line<type>[sizeT]; }
	~scantable() { delete[] stab; }
	void Insert(const string k, const type d) override;
	void Delete(const string k) override;
	type Search(const string k) override;

	void Reset() override { ind = 0; }
	bool IsTabEnded() override { return ind == size; }
	void GetNext()override;
	type GetCurrent() override { return stab[ind].data; }
};
 
template <class type> void scantable<type>::Insert(const string k, const type d) {
	if (size==maxsize)
		1;//Realloc();	
		stab[size] = line<type>(k, d);
		size++;	
}

template <class type> void scantable<type>::Delete(const string k) {
	Reset();
	while (ind<size && stab[ind].key != k)
		ind++;
	if (stab[ind].key == k)
	{
		size--;
		stab[ind].key = stab[size].key;
		stab[ind].data= stab[size].data;
	}
}

template <class type> type scantable<type>::Search(const string k) {
	Reset();
	while (ind<size && stab[ind].key != k)
		ind++;
	if (ind=size)
		throw " ";
	return ind;
}


template <class type> void scantable<type>::GetNext() {
	if (!IsTabEnded())
		ind++;
	else
		throw " ";
}
