#pragma once

#include "table.h"
#include "line_list.h" 


template <class type>
class hashtable :public table <type> 
{
protected:
	int hf (const string s);
	void Realloc() override;
	List<record<type>>* HT;
public:
	hashtable(int any_size = S) : table(any_size) { HT = new List<record<type>>[any_size]; }
	~hashtable() { delete[] HT; }
	type* Search(const string& k) override;
	void Insert(const string& k, const type& d) override;
	void Delete(const string& k) override;
	void Reset() override;
	void GetNext()override;
	bool IsTabEnded() const override;
	record<type> GetCurrent() const override { return HT[idx].GetCur()->data;}

	template<class t> friend ostream& operator<<(ostream& os, hashtable<t>& tab);

};

template <class type> int hashtable<type>::hf (const string s)
{
	//additive method
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += (int)(s[i]);     
	return (sum % maxsize);
}

template <class type> void hashtable<type>::Realloc()
{
	maxsize *= 1.5;
	List<record<type>>* new_HT = new List<record<type>>[maxsize];
	Reset();
	new_HT[hf(GetCurrent().key)].InsertToHead(GetCurrent());
	while (!IsTabEnded())
	{
		GetNext();
		new_HT[hf(GetCurrent().key)].InsertToHead(GetCurrent());
	}
	delete[] HT;
	HT = new_HT;
}


template <class type> type* hashtable<type>::Search(const string& k)
{
	if (HT[hf(k)].Search(record<type>(k)) != nullptr)
		return ((HT[hf(k)].Search(record<type>(k)))->data).data;  
	else
		throw "Not found";
}


template <class type> void hashtable<type>::Insert(const string& k, const type& d)
{
	int pos = hf(k);
	if (HT[pos].Search(record<type>(k)) == nullptr)
	{
		if (HT[pos].IsEmpty())
		{
			cursize++;
			if (double(cursize) / maxsize > 0.6)
				Realloc();
		}
		HT[pos].InsertToHead(record<type>(k, d));
	}
	else
		throw "Repeat key";
}


template <class type> void hashtable<type>::Delete(const string& k)
{
	if (HT[hf(k)].Search(record<type>(k)) != nullptr)
	{
		HT[hf(k)].Delete(record<type>(k));
		if (HT[hf(k)].IsEmpty())
			cursize--;
	}
	else
		throw "Not found";
}


template <class type> void hashtable<type>::Reset()    // устанавливает idx на первую цепочку и идёт в первый элеммент цепочки
{
	int i = 0;
	if (cursize)       
	{
		while (HT[i].IsEmpty())
			i++;
		idx = i;
		HT[idx].Reset();
	}
	else
		throw "Table is empty";
}


template <class type> void hashtable<type>::GetNext()
{
	if (!HT[idx].IsEnded())   
		HT[idx].GetNext();    
	else                        
	{
		idx++;                 
		while (idx < maxsize && HT[idx].IsEmpty())
			idx++;
		if (idx == maxsize)
			Reset();
		else
			HT[idx].Reset();
	}
}


template <class type> bool hashtable<type>::IsTabEnded() const
{
	bool res = false;
	int i = idx;
	if (cursize)
	{
		if (HT[idx].IsEnded())
		{
			i++;
			while (i < maxsize && HT[i].IsEmpty())
				i++;
			if (i == maxsize)
				res = true;
		}
	}
	else 
		res = true;
	return res;
}


template<class type> ostream& operator<<(ostream& os, hashtable<type>& tab) 
{
	if (tab.cursize)
	{

		tab.Reset();
		int i = tab.idx;     // первый непустой

		if (!tab.IsTabEnded())
		{
			do
			{
				tab.HT[tab.idx].Reset();
				while (!tab.HT[tab.idx].IsEnded())
				{
					os << tab.HT[tab.idx].GetCur()->data.key << "      " << *(tab.HT[tab.idx].GetCur()->data.data) << "       ";
					tab.HT[tab.idx].GetNext();
				}
				os << endl;
				tab.GetNext();
			} while (!tab.IsTabEnded() && i < tab.idx);
		}
	}
	else
		os << "Empty table";
	return os;
}













/*

	tab.Reset();
	int i = tab.idx;


	if (!tab.IsTabEnded())  //////////
	{                       //////////

		do
		{
			tab.HT[tab.idx].Reset();
			while (!tab.HT[tab.idx].IsEnded())
			{
				os << tab.HT[tab.idx].GetCur()->data.key << "      " << *(tab.HT[tab.idx].GetCur()->data.data) << "       ";
				tab.HT[tab.idx].GetNext();
			}
			os << endl;
			tab.GetNext();


		} while (!tab.IsTabEnded() && i > tab.idx);

	}                         ////////////
	return os;


	idx++;
	while (idx < maxsize && HT[idx].IsEmpty())
	idx++;
	if (idx == maxsize)
	Reset();

	

	*/

		

