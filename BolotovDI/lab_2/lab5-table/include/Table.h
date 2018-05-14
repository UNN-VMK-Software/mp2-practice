#pragma once

#include "TPolinom.h"

using namespace std;

struct unit
{
	TPolinom data;
	string key;

	unit() { key = "", data = TPolinom(); }
	unit(const string s, const TPolinom &poli2) { key = s; data = poli2;}
	
	unit& operator= (const unit &tmp) { data = tmp.data; key = tmp.key.substr(0, tmp.key.length()); return *this; }
};

class table
{
protected:
	unit *str; // указатель на структуру 
	int max_size; // максимальный размер
	int size; // количество записей
	int index; // индекс текущей записи 
	virtual void Repacking() = 0; // перепаковка 
public:
	table(int nsize = 2); // конструктор
	virtual ~table() { delete[] str; } // деструктор

	virtual void Insert(const string k, const TPolinom &poli2) = 0; // вставка
	virtual TPolinom Search(const string k) const = 0; // поиск
	virtual void Delete(const string k) = 0; // удаление 

	void Reset(); // первая запись является текущей
	bool IsFull(); // проверка на полноту списка
	void Next(); // index++
	unit& GetCurrent(); // вернуть текущий
};

table::table(int nsize)
{
	max_size = nsize;
	size = 0;
	index = -1;
	str = new unit[nsize];
}

void table::Reset()
{
	index = 0;
}

bool table::IsFull()
{
	if (max_size == size) // проблема того, что массивы начинаются с i = 0 и если у нас max_size = 2 ( по правилу имеем 2 записи), а на деле имеем 3 записи
	{
		return true;
	}
	else
	{
		return false;
	}
}

void table::Next()
{
	index = index + 1;
}

unit& table::GetCurrent()
{
	return str[index];
}