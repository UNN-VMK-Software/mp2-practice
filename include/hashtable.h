#pragma once
#include "table.h"
#include "linelist.h"
#include "vector" 

#define LOADFACTOR 0.65

template <class type>
class hashtable :public table <type> {
protected:	
	List<line<type>>** htab;
	int hashf(const string k);
public:
	void Reset() override;
	hashtable(int sizeT= DEFAULTSIZE) { shift = 0; maxsize = sizeT; size = 0; ind = 0; htab = new List<line<type>>*[maxsize]; for (int i = 0; i < maxsize; i++) htab[i] = new List<line<type>>; }
	~hashtable() { for (int i = 0; i < maxsize; i++) delete htab[i]; delete[] htab; }
	type Search(const string k) override;
	void Insert(const string k, const type& d) override;
	void Delete(const string k) override;
	void GetNext()override;
	bool IsTabEnded() override;

};

template <class type> void hashtable<type>::Reset() {
	int i = 0;
	if (size != 0)
	{
		while (htab[i]->IsEmpty())
			i++;
		ind = i;		
	}
	else
		throw "not found";
}

template <class type> bool hashtable<type>::IsTabEnded() {
	
}

template <class type> void hashtable<type>::GetNext() {
	if (!htab[ind]->IsEmpty())
		htab[ind]->GetNext();
	else 
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
	int s = hashf(k);
	Node<line<type>>* el = htab[s]->Search(line<type>(k, NULL));
	if (el == NULL)
	{
		if (htab[s]->IsEmpty())
		{
			size++;
			if (double(size) / maxsize > LOADFACTOR)
				1;// Realloc();
		}
		htab[s]->InsertToHead(line<type>(k, d));
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