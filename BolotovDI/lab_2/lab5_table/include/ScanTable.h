#pragma once

#include "Table.h"

class ScanTable : public table
{
private:
	void Repacking() override; // перепаковка
public:
	ScanTable(int nsize = 10) : table(nsize) { size = 0; index = -1; } // конструктор
	ScanTable(const ScanTable &T);
	~ScanTable() {} // деструктор

	void Insert(const string k, const TPolinom *poli2) override; // вставка // переделать
	unit* Search(const string k) override; // поиск
	void Delete(const string k) override; // удаление // переделать
};

void ScanTable::Repacking()
{
	max_size = max_size * 2;
	unit **tmp = new unit*[max_size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = str[i];
	}
	for (int i = size; i < max_size; i++)
	{
		tmp[i] = NULL;
	}
	delete str; 
	str = tmp;
}

void ScanTable::Insert(const string k, const TPolinom *poli2)
{
	if (max_size == size) 
	{
		Repacking();
	}

	if (Search(k) != nullptr)
	{
		throw "В просматриваемой таблице уже присутствует данный ключ.";
	}
	else
	{
		str[size] = new unit(k, poli2);
		size = size + 1;
		index = index + 1;
	}
}

unit* ScanTable::Search(const string k) 
{
	int i = 0;
	while ((i < size) && (str[i]->key != k))
	{
		i++;
	}

	if (i < size)
	{
		index = i;
		return str[i];
	}
	else
	{
		return nullptr;
	}
}

void ScanTable::Delete(const string k)
{
	if (Search(k) == nullptr)
	{
		throw "В просматриваемых таблицах отсутствует элемент, который хотите удалить.";
	}
	else
	{
		str[index]->data = str[size - 1]->data;
		str[index]->key = str[size - 1]->key;
		str[size - 1] = NULL;
		size = size - 1;
		index = size - 1;
	}
}

ScanTable::ScanTable(const ScanTable &T)
{
	max_size = T.max_size;
	size = T.size;
	index = T.index;
	str = T.str;
}