#pragma once
#include<string>
#include<iostream>

using namespace std;

template <class T>
struct Record
{
	T*data;
	string key;
	Record() { data = NULL; key = ""; }
	Record(const Record<T>& r){ data = new T(*(r.data)); key = r.key;}
	~Record() { delete data; }
	Record(string str, T d) { data = new T(d); key = str; }
	Record(string str) { data = NULL; key = str; }
	Record<T>& operator=(const Record<T>& r);
	bool operator==(const Record<T>& r)const { return key == r.key; }
	bool operator!=(const Record<T>& r)const { return !(*this == r); }
};

template <class T>
class Table
{
protected:
	int max;
	int rec;
	int id;
	virtual void Realloc() = 0;
public:
	Table(int s) { max = s; rec = 0; id = 0; }
	virtual ~Table() {};
	virtual void Insert(const string str, const T& d) = 0;
	virtual T* Search(const string str) = 0;
	virtual void Delete(const string str) = 0;
	virtual Record<T>GetCurr()const = 0;
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool End()const = 0;
	bool Empty()const { return rec == NULL; }
	bool Full()const { return rec == max; }
	int GetSize()const { return rec; }
};

template<class T>
inline Record<T>& Record<T>::operator=(const Record<T>& r)
{
	delete data;
	data = new T(*(r.data));
	key = r.key;
	return *this;
}