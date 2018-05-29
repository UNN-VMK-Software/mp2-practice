#pragma once
#include"Polynom.h"

using namespace std;

class Record
{
public:
	Polynom data;
	string key;
	Record() { key = "", data = Polynom(); }
	Record(const string str, const Polynom& p) { key = str; data = p; }
	Record& operator = (const Record& r) { data = r.data; key = r.key.substr(0, r.key.length()); return *this; }
};

class Table
{
protected:
	Record*r;
	int max;
	int size;
	int flag;
public:
	Table(int s = 2);
	virtual ~Table() { delete[] r; } // деструктор
	virtual void Insert(const string str, const Polynom& p) = 0; // вставка
	virtual Polynom Search(const string str) const = 0; // поиск
	virtual void Delete(const string str) = 0; // удаление 

	void First(); // первая запись является текущей
	bool Full(); // проверка на полноту списка
	void Next(); // index++
	Record& GetCurr(); // вернуть текущий
};