#pragma once
#include "table.h"

template <class type>
class scantable :public table <type> {
protected:	
	line<type>** stab;
	void Realloc()override;
	bool BSearch(const string k);			//true если элемент найдет. дл€ Insert	
public:	
	scantable(int sizeT = DEFAULTSIZE);
	~scantable();
	void Insert(const string k, const type& d) override;
	void Delete(const string k) override;
	type* Search(const string k) override;	
	void Reset() override;			
	bool IsTabEnded() const override;
	void GetNext()override;
	line<type> GetCurrent() const override;	
	template<class type> friend class sortedtable;  //класс sortedtable может залезать в protected пол€ 
	template<class t> friend ostream& operator<<(ostream& os,  scantable<t>& t);
};

template <class type> scantable<type>::scantable(int sizeT = DEFAULTSIZE) : table(sizeT) {
	stab = new line<type>*[maxsize];
}

template <class type> scantable<type>::~scantable() {
	for (int i = 0; i < size; i++)
		delete stab[i];
	delete[] stab;
}

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
		Reset();
}

template<class type> bool scantable<type>::IsTabEnded() const {			
		return (ind >= size - 1);	
}

template<class type> line<type> scantable<type>::GetCurrent() const {
	if (ind <= size - 1)
	return *(stab[ind]);
	else
		throw "not found";
}

template <class type> type* scantable<type>::Search(const string k) {
	int i = 0;
	while (i < size && stab[i]->key != k)
		i++;
	if (i == size)
		throw "not found";
	else
		return stab[i]->data;
}

template <class type> bool scantable<type>::BSearch(const string k) {
	int i = 0;
	bool res = false;
	while (i < size && stab[i]->key != k)
		i++;
	if (i != size && stab[i]->key == k)
		res = true;
	return res;
}
 
template <class type> void scantable<type>::Insert(const string k, const type& d) {	
	if (!BSearch(k))
	{
		if (size == maxsize)
			Realloc();	
		stab[size] = new line<type>(k, d);
		size++;
	}
	else 
		throw "repeated key";
}

template <class type> void scantable<type>::Delete(const string k) {
	int i = 0;
	while (i < size && stab[i]->key != k)
		i++;
	if (i == size)
		throw "not found";
	else
	{
		size--;
		delete stab[i];
		stab[i] = stab[size];
	}
}

template <class type> void scantable<type>::Realloc() {
	maxsize *= 2;
	line<type>** temp;
	temp = new line<type>*[maxsize];
	for (int i = 0; i < maxsize; i++)
		temp[i] = new line<type>;
	for (int i = 0; i < size; i++)
		temp[i] = stab[i];	
	delete[] stab;
	stab = temp;

}

template<class type>  ostream& operator<<(ostream& os, scantable<type>& t) {
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