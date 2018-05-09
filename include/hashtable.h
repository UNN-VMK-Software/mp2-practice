#pragma once
#include "table.h"
#include "linelist.h"

#define LOADFACTOR 0.65

template <class type>
class hashtable :public table <type> {
protected:	
	List<line<type>>** htab;
	void Realloc()override;
	int hashf(const string k);
public:	
	hashtable(int sizeT = DEFAULTSIZE);
	~hashtable() { for (int i = 0; i < maxsize; i++) delete htab[i]; 
		delete[] htab; 
	}
	
	type Search(const string k) override;
	void Insert(const string k, const type& d) override;
	void Delete(const string k) override;
	void Reset() override;
	void GetNext()override;
	bool IsTabEnded() override;
	line<type> GetCurrent() override;
	template<class t> friend ostream& operator<<(ostream& os, hashtable<t>& t);
};

template <class type> hashtable<type>::hashtable(int sizeT = DEFAULTSIZE) : table(sizeT) {
	htab = new List<line<type>>*[maxsize];
	for (int i = 0; i < maxsize; i++)
		htab[i] = new List<line<type>>;
}

template <class type> void hashtable<type>::Reset() {
	int i = 0;
	if (size != 0)
	{
		while (htab[i]->IsEmpty())
			i++;
		ind = i;	
		htab[ind]->Reset();
	}
	else
		throw "not found";
}

template <class type> bool hashtable<type>::IsTabEnded() {
	bool res = false;
	int i = ind;
	if (htab[ind]->IsEnded())
	{
		i++;
		while (i < maxsize && htab[i]->IsEmpty())
			i++;
		if (i == maxsize)
			res = true;
	}
	return res;

}

template <class type> void hashtable<type>::GetNext() {
	if (!htab[ind]->IsEnded())
		htab[ind]->GetNext();
	else
	{
		ind++;
		while (ind<maxsize && htab[ind]->IsEmpty())
			ind++;
		if (ind==maxsize)
			Reset();		
		else			
			htab[ind]->Reset();		
	}
}

template <class type> line<type> hashtable<type>::GetCurrent() {
	Node < line < type >>* a= (htab[ind]->GetCur());
	line<type> res = a->data;
	return res;
}

template <class type> int hashtable<type>::hashf(const string k) {
	int res = 0;
	for (int i = 0; i < k.length(); i++)
		res += int(k[i]);
	res %= maxsize;
	return res;
}

template <class type> type hashtable<type>::Search(const string k) {
	int s = hashf(k);
	Node<line<type>>* el = htab[s]->Search(line<type>(k, NULL));
	if (el != NULL)
		return *((el->data).data);
	else 
		throw "not found";
}

template <class type> void hashtable<type>::Insert(const string k, const type& d) {
	
	int i = 0;
	Node<line<type>>* el = htab[hashf(k)]->Search(line<type>(k, NULL));
	if (el == NULL)
	{
		if (htab[hashf(k)]->IsEmpty())
		{
			size++;
			if (double(size) / maxsize > LOADFACTOR)
				Realloc();
		}
		htab[hashf(k)]->InsertToHead(line<type>(k, d));
	}
	else
		throw "repeated key";
}

template <class type> void hashtable<type>::Delete(const string k) {
	int s = hashf(k);
	Node<line<type>>* el = htab[s]->Search(line<type>(k, NULL));
	if (el != NULL)
	{
		htab[s]->Delete(line<type>(k, NULL));
		if (htab[s]->IsEmpty())
			size--;
	}
	else
		throw "not found";
}

template <class type> void hashtable<type>::Realloc() {

	int nmaxsize = maxsize * 2;
	List<line<type>>** temp;
	temp = new List<line<type>>*[nmaxsize];
	for (int i = 0; i < nmaxsize; i++)
		temp[i] = new List<line<type>>;

	Reset();	
	temp[hashf(GetCurrent().key)]->InsertToHead(GetCurrent());
	while (!IsTabEnded())
	{
		GetNext();
		temp[hashf(GetCurrent().key)]->InsertToHead(GetCurrent());
	}

	for (int i = 0; i < maxsize; i++)
		delete htab[i];
	delete[] htab;
	
	maxsize = nmaxsize;
	htab = temp;
}

template<class type> ostream& operator<<(ostream& os,  hashtable<type>& t) {
	if (t.size != 0)
	{
		t.Reset();
		os << t.GetCurrent().key << "     " << *(t.GetCurrent().data) << endl;
		while (!t.IsTabEnded())
		{
			t.GetNext();
			os << t.GetCurrent().key << "     " << *(t.GetCurrent().data) << endl;
		}
	}
	return os;
}