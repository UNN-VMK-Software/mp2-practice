#pragma once

#include "TPolinom.h"

using namespace std;

struct unit
{
	TPolinom *data; 
	string key;

	unit() { key = "", data = &TPolinom(); }
	unit(const string s, const TPolinom *poli2) { key = s; data = const_cast<TPolinom*>(poli2);}
	
	unit& operator= (const unit &tmp) { data = tmp.data; key = tmp.key.substr(0, tmp.key.length()); return *this; }
};

class table
{
protected:
	unit **str; // указатель на структуру 
	int max_size; // максимальный размер
	int size; // текущее количество записей
	int index; // индекс текущей записи 
	virtual void Repacking() = 0; // перепаковка 
public:
	table(int nsize = 10); // конструктор
	virtual ~table() { delete[] str; } // деструктор

	virtual void Insert(const string k, const TPolinom *poli2) = 0; // вставка 
	virtual unit* Search(const string k) = 0; // поиск 
	virtual void Delete(const string k) = 0; // удаление 

	virtual void Reset() ;// перва€ запись €вл€етс€ текущей 
	virtual bool IsFull() const ; // проверка на полноту списка 
	virtual void Next() ; // index++ 
	virtual unit* GetCurrent() const ; // вернуть текущий 
	virtual int GetSize() const ; // вернуть size
	virtual int GetMaxSize() const ; // вернуть max_size
	virtual int GetIndex() const; // вернуть index

	virtual void PrintTable(); 
};

table::table(int nsize)
{
	max_size = nsize;
	size = 0;
	index = -1;
	str = new unit*[nsize];
	for (int i=0 ; i < max_size; i++)
	{
		str[i] = NULL;
	}

}

void table::Reset()
{
	index = 0;
}

bool table::IsFull() const
{
	if (max_size == size) 
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

unit* table::GetCurrent() const
{
	return str[index];
}

int table::GetSize() const
{
	return size;
}

int table::GetMaxSize() const
{
	return max_size;
}

int table::GetIndex() const
{
	return index;
}

void table::PrintTable()
{
	Reset();
	for (int i = 0; i < max_size; i++)
	{
		if (str[i] != NULL) 
		{
			cout << "ѕозици€ :" << i << "  люч: " << str[i]->key << endl;
		}
		else
		{
			cout << "ѕозици€ :" << i << "  люч: NULL" << endl;
		}
		this->Next();
	}
}