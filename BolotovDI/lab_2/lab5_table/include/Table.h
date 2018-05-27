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
	unit **str;
	int max_size;
	int size;
	int index;
	virtual void Repacking() = 0;
public:
	table(int nsize = 10);
	virtual ~table() { delete[] str; }

	virtual void Insert(const string k, const TPolinom *poli2) = 0;
	virtual unit* Search(const string k) = 0;
	virtual void Delete(const string k) = 0;

	virtual void Reset();
	virtual bool IsFull() const ;
	virtual void Next();
	virtual unit* GetCurrent() const;
	virtual int GetSize() const;
	virtual int GetMaxSize() const;
	virtual int GetIndex() const;

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
			cout << "Позиция :" << i << " Ключ: " << str[i]->key << endl;
		}
		else
		{
			cout << "Позиция :" << i << " Ключ: NULL" << endl;
		}
		this->Next();
	}
}