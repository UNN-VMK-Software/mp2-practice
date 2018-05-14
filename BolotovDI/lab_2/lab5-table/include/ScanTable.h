#pragma once

#include "Table.h"

class ScanTable : table
{
private:
	int current_size; // количество записей
	int index; // индекс текущей записи 
	void Repacking() override; // перепаковка
public:
	ScanTable(int nsize = 2) : table(nsize) { current_size = 0; index = -1; } // конструктор
	~ScanTable() {} // деструктор

	void Insert(const string s, const TPolinom &poli2) override; // вставка
	TPolinom Search(const string k) const override; // поиск
	void Delete(const string k) override; // удаление
};

void ScanTable::Repacking()
{
	max_size = max_size * 2;
	unit *tmp = new unit[max_size];
	for (int i = 0; i < current_size; i++)
	{
		tmp[i] = str[i];
	}
	delete str; // ???????????????????????????
	unit *str = new unit[max_size];
	for (int i = 0; i < index; i++)
	{
		str[i] = tmp[i];
	}
}

void ScanTable::Insert(const string s, const TPolinom &poli2)
{
	if (max_size == current_size) // проблема того, что массивы начинаются с i = 0 и если у нас max_size = 2 ( по правилу имеем 2 записи), а на деле имеем 3 записи
	{
		Repacking();
	}
	str[current_size] = unit(s, poli2);
	current_size = current_size + 1;
	index = index + 1;
}

TPolinom ScanTable::Search(const string k) const
{
	int i = 0;
	while ((str[i].key != k) && (i < current_size))
	{
		i++;
	}

	if (i < current_size)
	{
		return str[i].data;
	}
	else
	{
		throw "Error";
	}
}

void ScanTable::Delete(const string k)
{
	int i = 0;
	while ((str[i].key != k) && (i < current_size))
	{
		i++;
	}

	if (i < current_size)
	{
		if (current_size > 1)
		{
			str[i] = str[index];
			current_size = current_size - 1;
			index = index - 1;
		}
		else
		{
			current_size = 0;
			index = -1;
		}
	}
	else
	{
		throw "Error";
	}
}