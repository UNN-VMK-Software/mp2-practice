#pragma once
 
#include "table.h"

template <typename T>
class Hashtable : public Table<T>
{
protected:
	int* flag;
	int HashFunc(const string& key) const;
	void Realloc() override;
public:
	Hashtable(int j = 10);
	Hashtable(const Hashtable<T>& t);
	~Hashtable();
	void Insert(const T& data1, const string& key1) override;
	T& Search(const string& key1);
	void Delete(const string& key1);
	void TGetnext() override;
	T& Getcurr() const override;
	void Reset() override;
	bool TIsended() const;
	template <class T> friend ostream& operator<<(ostream& os, const Hashtable<T>& t);
};

template<typename T>
Hashtable<T>::Hashtable(int j = 10) : Table(j)
{
	flag = new int[j];
	for (int i = 0; i < maxrec; i++)
		flag[i] = 0;
}

template<typename T>
Hashtable<T>::Hashtable(const Hashtable<T>& t)
{
	maxrec = t.maxrec;
	currind = t.currind;
	currrec = t.currrec;
	delete[] flag;
	delete[] tab;
	tab = new Tabrecord<T>*[maxrec];
	flag = new int[maxrec];
	for (int i = 0; i < currrec; i++)
	{
		tab[i] = t.tab[i];
		flag[i] = t.flag[i];
	}
}

template<typename T>
Hashtable<T>::~Hashtable()
{
	delete[] flag;
}

template<typename T>
int Hashtable<T>::HashFunc(const string& key) const
{
	int h = 0;
	for (int i = 0; i < key.length(); i++)
		h = h + int(key[i]);
	return h % maxrec;
}

template<typename T>
void Hashtable<T>::Realloc()
{
	int maxrec1 = maxrec * 2;
	int* flag1 = new int[maxrec1];
	Tabrecord<T>** temp = new Tabrecord<T>*[maxrec1];
	for (int i = 0; i < maxrec; i++)
	{
		temp[i] = tab[i];
		flag1[i] = flag[i];
	}
	delete[] tab;
	delete[] flag;
	tab = temp;
	flag = flag1;
	maxrec = maxrec1;
}

template<typename T>
void Hashtable<T>::TGetnext()
{
	if(currrec)
	{
		currind++;
		while (flag[currind] != 1)
			currind = (currind + 1) % maxrec; 
	}
	else
		throw "error";
}

template<typename T>
T& Hashtable<T>::Getcurr() const
{
	if (currrec)
		return tab[currind]->data;
	else
		throw "error";
}

template<typename T>
void Hashtable<T>::Reset()
{
	if (currrec)
	{
		currind = 0;
		while (flag[currind] != 1)
			currind++;
	}
	else
		currind = -1;
}

template<typename T>
bool Hashtable<T>::TIsended() const
{
	return (currind == currrec || currind == -1);
}

template<typename T>
void Hashtable<T>::Insert(const T& data1, const string& key1)
{
	if (Isfull())
		Realloc();
	currind = HashFunc(key1);
	if (!flag[currind])
	{
		tab[currind] = new Tabrecord<T>(key1, data1);
		currrec++;
		flag[currind] = 1;
	}
	else
		if (tab[currind]->key != key1)
		{
			int i = currind;
			while (flag[currind] && ((currind + 1) != i))
				currind = (currind + 1) % maxrec;
			tab[currind] = new Tabrecord<T>(key1, data1);
			currrec++;
			flag[currind] = 1;
		}
		else
			throw "error";
}

template<typename T>
T& Hashtable<T>::Search(const string& key1)
{
	Reset();
	if (currrec)
	{
		currind = HashFunc(key1);
		int ind = currind;
		if (tab[currind]->key == key1)
			return tab[currind]->data;
		else
		{
			while (flag[currind] && ((currind + 1) != ind) && (tab[currind]->key != key1))
				currind = (currind + 1) % maxrec;
			if (tab[currind]->key == key1)
				return tab[currind]->data;
			else
				throw "error";
		}
	}
	else
		throw "error";
}

template<typename T>
void Hashtable<T>::Delete(const string& key1)
{
	Reset();
	if (currrec)
	{
		currind = HashFunc(key1);
		int ind = currind;
		if (flag[currind])
		{
			if (tab[currind]->key != key1)
			{
				while (flag[currind] && ((currind + 1) != ind) && (tab[currind]->key != key1))
					currind = (currind + 1) % maxrec;
				if (!flag[currind] || tab[currind]->key != key1)
					throw "error";
				else
				{
					tab[currind] = new Tabrecord<T>;
					flag[currind] = 0;
					currrec--;
				}
			}
			else
			{
				tab[currind] = new Tabrecord<T>;
				flag[currind] = 0;
				currrec--;
			}
		}
		else
			throw "error";
	}
	else
		throw "error";
}

template <typename T>
ostream& operator<<(ostream& os, const Hashtable<T>& t)
{
	if (t.currrec)
	{
		for (int i = 0; i < t.maxrec; i++)
			if (t.flag[i])
				os << i << " | " << t.tab[i]->key << " | " << t.tab[i]->data << endl;
	}
	else
		os << "error" << endl;
	return os;
}










