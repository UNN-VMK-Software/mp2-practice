#pragma once

#include "Table.h"

class SortedTable : table
{
private:
	int current_size; // количество записей
	int index; // индекс текущей записи 
	void Repacking() override; // перепаковка
public:
	SortedTable(int nsize = 2) : table(nsize) { current_size = 0; } // конструктор
	~SortedTable() {} // деструктор

	int BinarSearch(const string k) const; // бинарный поиск
	void Insert(const string s, const TPolinom &poli2) override; // вставка
	TPolinom Search(const string k) const override; // поиск
	void Delete(const string k) override; // удаление
};

void SortedTable::Repacking()
{
	max_size = max_size * 2;
	int tsize = max_size;
	unit *tmp = new unit[tsize];
	for (int i = 0; i < current_size; i++)
	{
		tmp[i] = str[i];
	}
	str = tmp;
}

int SortedTable::BinarSearch(const string k) const
{
	int left = 0;
	int right = current_size - 1; 
	int middle = 0;
	
	while (left <= right)
	{
		middle = (left + right) / 2;

		if (k > str[middle].key)
		{
			left = middle + 1;
		}
		else 
		{
			right = middle - 1;
		}
	}

	return left;
}

void SortedTable::Insert(const string s, const TPolinom &poli2)
{
	if (max_size == current_size - 1)
	{
		Repacking();
	}

	int cur = BinarSearch(s);

	if (str[cur].key != s)
	{
		for (int i = current_size; i > cur; i--)
		{
			str[i] = str[i - 1];
		}
		str[cur] = unit(s, poli2); // ломается 
		current_size = current_size + 1;
	}
	else
	{
		throw "Error";
	}
}

TPolinom SortedTable::Search(const string k) const
{
	int i = BinarSearch(k);

	if (str[i].key == k)
	{
		return str[i].data;
	}
	else
	{
		throw "Error";
	}
}

void SortedTable::Delete(const string k)
{
	int i = BinarSearch(k);

	if (str[i].key == k)
	{
		for (int j = i; j < current_size - 1; j++)
		{
			str[j] = str[j + 1];
		}
		current_size = current_size - 1;
	}
	else
	{
		throw "Error";
	}
}