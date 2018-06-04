#pragma once
#include "Table.h"
#include "list.h"
#include "ScanTable.h"

template <class T>
class SortTable :public Table <T> {
protected:
	void Realloc()override;
	Record<T>** r;
public:
	SortTable(int s = 10);
	~SortTable() { for (int i = 0; i < rec; i++)delete r[i]; delete[] r; }
	SortTable(const ScanTable<T> & t);
	void Insert(const string str, const T& d) override;
	void Delete(const string str) override;
	T* Search(const string str) override;
	void First() override { if (!Empty()) id = 0; else throw "Empty table."; }
	bool End() const  override {return (id >= rec - 1); }
	void Next()override { if (!End()) id++; else First(); }
	Record<T> GetCurr() const override { if (id <= rec - 1) return *(r[id]); else throw "Not found."; }
	template<class T> friend ostream& operator<<(ostream& out, SortTable<T>& t);
};

template<class T>
inline void SortTable<T>::Realloc()
{
	max = max * 2;
	Record<T>** tmp;
	tmp = new Record<T>*[max];
	for (int i = 0; i < max; i++)
		tmp[i] = new Record<T>;
	for (int i = 0; i < rec; i++)
		tmp[i] = r[i];
	delete[] r;
	r = tmp;
}

template <class T> SortTable<T>::SortTable(int s = 10) : Table(s) {
	r = new Record<T>*[max];
}

template<class T>
inline SortTable<T>::SortTable(const ScanTable<T>& t)
{
	r = new Record<T>*[max];
	for (int i = 0; i < max; i++)
		r[i] = new Record<T>;
	for (int i = 0; i < rec; i++)
		Insert(t.r[i]->key, *(t.r[i]->data));
}

template<class T>
inline void SortTable<T>::Insert(const string str, const T& d)
{
	if(Search(str)==NULL)
	{
		int i;
		if (rec == max)
			Realloc();
		for (i = rec; (i >0)&&(r[i-1]->key<str); i--)
			r[i] = r[i-1];
		rec++;
		id++;
		r[i] = new Record<T>(str, d);
	}
	else
		throw "Repeat key.";
}

template<class T>
inline void SortTable<T>::Delete(const string str)
{
	int i = 0;
	while (i < rec && r[i]->key != str)
		i++;
	if (i == rec)
		throw "Not found.";
	else
	{
		rec--;
		delete r[i];
		r[i] = r[rec];
	}
}

template<class T>
inline T * SortTable<T>::Search(const string str)
{
	int i = 0;
	while (i < rec && r[i]->key != str)
		i++;
	if (i == rec)
	{
		return NULL;
	}
	else
		return r[i]->data;
}

template<class T>
inline ostream & operator<<(ostream & out, SortTable<T>& t)
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