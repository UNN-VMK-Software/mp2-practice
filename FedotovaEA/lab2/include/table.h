#pragma once

#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Tabrecord
{
public:
	T data;
	string key; 
	Tabrecord();
	Tabrecord(const string& key1, const T& data1);
	Tabrecord(const Tabrecord& t);
	Tabrecord& operator=(const Tabrecord<T>& t);
	~Tabrecord() {}
};

template <typename T>
class Table
{
protected:
	Tabrecord<T>** tab;
	int currind; //текущий индекс
	int maxrec; //максимальное количество
	int currrec; //текущее количество
	virtual void Realloc(); ///////

public:
	Table(int j = 10);
	Table(const Table<T>& t);
	virtual ~Table();
	virtual T& Search(const string& key1) = 0; //поиск
	virtual void Delete(const string& key1) = 0; //удаление
	virtual void Insert(const T& data1, const string& key1) = 0; //вставка
	virtual void Reset(); //переход в начало
	virtual bool TIsended() const; //проверка на конец /////const
	bool Isfull() const; //проверка на заполненность
	bool Isempty() const;  //проверка на пустоту
	virtual void TGetnext();
	virtual T& Getcurr() const;
	virtual int Getcurrrec() const;
	virtual int Getcurrind() const;
	template <class T> friend ostream& operator<< (ostream& os, const Table<T>& t);
};

//реализация класса Tabrecord
template<typename T>
Tabrecord<T>::Tabrecord()
{
	key = "null";
	data = T();
}

template<typename T>
Tabrecord<T>::Tabrecord(const string& key1, const T& data1)
{
	key = key1;
	data = data1;
}

template<typename T>
Tabrecord<T>::Tabrecord(const Tabrecord& t)
{
	key = t.key;
	data = t.data; 
}

template<typename T>
Tabrecord<T>& Tabrecord<T>::operator=(const Tabrecord<T>& t)
{
	key = t.key;
	data = t.data;
	return *this;
}

//реализация класса Table
template <typename T>
void Table<T>::Realloc()
{
	int realloccof = 2;
	int maxrec1 = maxrec * realloccof;
	Tabrecord<T>** temp = new Tabrecord<T>*[maxrec1];
	Reset();
	for (int i = 0; i < maxrec; i++)
		temp[i] = tab[i];
	delete[] tab;
	maxrec = maxrec1;
	tab = temp;
}

template<typename T>
Table<T>::Table(int j)
{
	maxrec = j;
	currind = -1;
	currrec = 0;
	tab = new Tabrecord<T>*[maxrec]; 
}

template<typename T>
Table<T>::Table(const Table<T>& t)
{
	currrec = t.currrec;
	maxrec = t.maxrec;
	currind = t.currind;
	delete[] tab;
	tab = new Tabrecord<T>*[maxrec];
	for (int i = 0; i < currrec; i++)
		tab[i] = t.tab[i];
}

template<typename T>
Table<T>::~Table()
{
	delete[] tab;
}

template<typename T>
void Table<T>::Reset()
{
	if (currrec)
		currind = 0;
	else
		currind = -1;
}

template<typename T>
bool Table<T>::TIsended() const
{
	if (((currind + 1) == currrec) || (currind == -1)) 
		return true;
	else
		return false;
}

template<typename T>
bool Table<T>::Isfull() const
{
	if (currrec == maxrec)
		return true;
	else
		return false;
}

template<typename T>
bool Table<T>::Isempty() const
{
	if (currrec == 0)
		return true;
	else
		return false;
}

template<typename T>
void Table<T>::TGetnext()
{
	if (currrec)
		currind++;
	else
		throw "error";
	if (currind == currrec)
		Reset();
}

template<typename T>
T& Table<T>::Getcurr() const
{
	if (currrec)
		return tab[currind]->data; 
	else
		throw "error";
}

template<typename T>
int Table<T>::Getcurrrec() const
{
	return currrec;
}


template<typename T>
int Table<T>::Getcurrind() const
{
	return currind;
}

template <typename T>
ostream& operator<< (ostream& os, const Table<T>& t)
{
	if (t.currrec)
		for (int i = 0; i < t.currrec; i++)
			os << i << " | " << t.tab[i]->key << " | " << t.tab[i]->data << endl;
	else
		os << "error" << endl;
	return os;
}