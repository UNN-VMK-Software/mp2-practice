#pragma once
#include "Table.h"
#include "list.h"

template <class T>
class HashTable :public Table<T>
{
protected:
	List<Record<T>>* hashT;
	void Realloc()override;
	int H(const string str);
public:
	HashTable(int s = 10);
	~HashTable() { delete[] hashT; }
	T*Search(const string str)override;
	void Insert(const string str, const T&d)override;
	void Delete(const string str)override;
	void First()override;
	void Next()override;
	bool End()const override;
	Record<T>GetCurr()const override { return hashT[id].GetCurr()->data; }
	template<class T>friend ostream& operator<<(ostream& out, HashTable<T>& t);
};

template<class T>
inline void HashTable<T>::Realloc()
{
	int n = max * 2;
	List<Record<T>>* tmp = new List<Record<T>>[n];
	First();
	tmp[H(GetCurr().key)].InsertToHead(GetCurr());
	while (!End())
	{
		Next();
		tmp[H(GetCurr().key)].InsertToHead(GetCurr());
	}
	delete[] hashT;
	max = n;
	hashT = tmp;
}

template<class T>
inline int HashTable<T>::H(const string str)
{
	int res = 0;
	for (int i = 0; i < str.length(); i++)
	{
		res = res + int(str[i]);
	}
	res = res%max;
	return res;
}

template <class T> HashTable<T>::HashTable(int s = 10) : Table(s) {
	hashT = new List<Record<T>>[max];
}

template<class T>
inline T * HashTable<T>::Search(const string str)
{
	int s = H(str);
	node<Record<T>>*n = hashT[s].Search(Record<T>(str));
	if (n == NULL)
		throw"Not found.";
	else
		return (n->data).data;
}

template<class T>
inline void HashTable<T>::Insert(const string str, const T & d)
{
	int i = 0;
	node<Record<T>>*n = hashT[H(str)].Search(Record<T>(str));
	if (n == NULL)
	{
		if (hashT[H(str)].Empty())
		{
			rec++;
			if (double(rec) / max > 0.65)
				Realloc();
		}
		hashT[H(str)].InsertToHead(Record<T>(str, d));
	}
	else
		throw"Repeat key.";
}

template<class T>
inline void HashTable<T>::Delete(const string str)
{
	int s = H(str);
	node<Record<T>>*n = hashT[s].Search(Record<T>(str));
	if (n != NULL)
	{
		hashT[s].Delete(Record<T>(str));
		if (hashT[s].Empty())
			rec--;
	}
	else
		throw"Not found.";
}

template<class T>
inline void HashTable<T>::First()
{
	int i = 0;
	if (rec != 0)
	{
		while (hashT[i].Empty())
			i++;
		id = i;
		hashT[id].First();
	}
	else
		throw"Error.";
}

template<class T>
inline void HashTable<T>::Next()
{
	if (!hashT[id].End())
		hashT[id].Next();
	else
	{
		id++;
		while (id < max&&hashT[id].Empty())
			id++;
		if (id == max)
			First();
		else
			hashT[id].First();
	}
}

template<class T>
inline bool HashTable<T>::End() const
{
	bool f = false;
	int i = id;
	if (rec != 0)
	{
		if (hashT[id].End())
		{
			i++;
			while (i < max&&hashT[i].Empty())
				i++;
			if (i == max)
				f = true;
		}
	}
	else
		f = true;
	return f;
}

template<class T>
inline ostream & operator<<(ostream & out, HashTable<T>& t)
{
	if (t.rec != 0)
	{
		t.First();
		out << t.GetCurr().key << endl;
		while (!t.End())
		{
			t.Next();
			out << t.GetCurr().key << endl;
		}
	}
	return out;
}