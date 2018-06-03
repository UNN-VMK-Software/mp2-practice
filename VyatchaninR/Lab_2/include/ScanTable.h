#pragma once
#include "Table.h"

template <class T>
class ScanTable:public Table<T>
{
protected:
	Record<T>** r;
	void Realloc()override;
public:
	ScanTable(int s = 10);
	~ScanTable() { for (int i = 0; i < rec; i++) delete r[i]; delete[] r; }
	void Insert(const string str, const T& d) override;
	void Delete(const string str) override;
	T* Search(const string str) override;
	void First() override { if (!Empty()) id = 0; else throw "Empty table."; }
	bool End() const override{ return (id >= rec - 1); }
	void Next()override { if (!End()) id++; else First(); }
	Record<T> GetCurr() const override { if (id <= rec - 1) return *(r[id]); else throw "Not found."; }
	template<class T> friend ostream& operator<<(ostream& out, ScanTable<T>& t);
};

template<class T>
inline void ScanTable<T>::Realloc()
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

template <class T> ScanTable<T>::ScanTable(int s = 10) : Table(s) {
	r = new Record<T>*[max];
}

template<class T>
inline void ScanTable<T>::Insert(const string str, const T & d)
{
	if (Search(str)==NULL)
	{
		if (rec == max)
			Realloc();
		r[rec] = new Record<T>(str, d);
		rec++;
	}
	else
		throw "Repeat key.";
}

template<class T>
inline void ScanTable<T>::Delete(const string str)
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
inline T * ScanTable<T>::Search(const string str)
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
inline ostream & operator<<(ostream & out, ScanTable<T>& t)
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