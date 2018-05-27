#pragma once

#include "Table.h"

class SortedTable : public table
{
private:
	void Repacking() override;
public:
	SortedTable(int nsize = 10) : table(nsize) { size = 0; index = -1; }
	SortedTable(const ScanTable T);
	~SortedTable() {} 

	void Insert(const string k, const TPolinom *poli2) override; 
	unit* Search(const string k) override;
	void Delete(const string k) override; 
};

void SortedTable::Repacking()
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

void SortedTable::Insert(const string k, const TPolinom *poli2)
{
	if (max_size == size)
	{
		Repacking();
	}

	if (Search(k) != nullptr)
	{
		throw "В сортированной таблице уже присутствует данный ключ.";
	}
	else
	{
			int i;
			for (i = size; (i > 0) && (str[i - 1]->key < k); i--)
			{
				str[i] = str[i - 1];
			}
			str[i] = new unit(k, poli2);
			size = size + 1;
			index = index + 1;
	}
}

unit* SortedTable::Search(const string k) 
{
	int left = 0;
	int right = size - 1;
	int middle = 0;
	int a = 0;

	while ((left <= right) && (a != 1))
	{
		middle = (left + right) / 2;

		if (k > str[middle]->key)
		{
			right = middle - 1;
		}
		else if (k < str[middle]->key)
		{
			left = middle + 1;
		}
		else if (k == str[middle]->key)
		{
			a = 1;
		}
	}

	if (a == 0)
	{
		return nullptr;
	}
	else
	{
		index = middle;
		return str[left];
	}
}

void SortedTable::Delete(const string k)
{
	if (Search(k) == nullptr) 
	{
		throw "В сортированных таблицах отсутствует элемент, который хотите удалить.";
	}
	else
	{
		int i = 0;
		while (str[i]->key > k)
		{
			i++;
		}

		for (int j = i; j < size - 1; j++)
		{
			str[j] = str[j + 1];
		}
		str[size - 1] = NULL;
		size = size - 1;
	}
}

SortedTable::SortedTable(const ScanTable T)
{
	ScanTable ST = T;
	size = 0;
	index = -1;
	max_size = ST.GetMaxSize();
	ST.Reset();

	for (int i = 0; i < ST.GetSize(); i++)
	{
		Insert(ST.GetCurrent()->key, ST.GetCurrent()->data);
		ST.Next();
	}
}