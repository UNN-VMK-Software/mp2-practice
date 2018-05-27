#pragma once

#include "Table.h"

class HashTable : public table
{
private:
	int hash(string key) const; 
	void Repacking() override; 
	int *State; 
public:
	HashTable(int nsize = 10) : table(nsize) { size = 0;	index = -1;	State = new int[nsize]; for (int i = 0; i < max_size; i++) {	State[i] = 0; } };

	void Insert(const string s, const TPolinom *poli2) override;
	void Delete(const string k) override;
	unit* Search(const string k) override;
};

int HashTable::hash(string key) const
{
	int a = 7;
	int h = 0;
	for (int i = 0; i < key.length(); i++)
	{
		h = key[i] * a + h;
	}
	
	return (h % max_size);
}

void HashTable::Repacking()
{
	max_size = max_size * 2;
	unit **tmp = new unit*[max_size];
	for (int i = 0; i < max_size; i++)
	{
		tmp[i] = NULL;
	}
	int *State2;
	State2 = new int[max_size];
	for (int i = 0; i < max_size; i++) 
	{ 
		State2[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		if (State[i] != 0)
		{
			int j = hash(str[i]->key);
			tmp[j] = str[i];
			State2[j] = 1;
		}
	}

	str = tmp;
	
	for (int i = 0; i < max_size; i++)
	{
		State[i] = State2[i];
	}
}

void HashTable::Insert(const string s, const TPolinom *poli2)
{
	double a = size;
	double b = max_size;
	if (a != 0)
	{
		if ((a / b) > 0.63)
		{
			Repacking();
		}
	}
		
	if (Search(s) != nullptr)
	{
		throw "В хэш-таблице уже присутствует данный ключ.";
	}
	else
	{
		int place = hash(s);
		if (State[place] == 0)
		{
			str[place] = new unit(s, poli2);
			size = size + 1;
			index = place;
			State[place] = 1;
		}
		else
		{
			while (State[place] != 0)
			{
				place = (place + 11) % max_size;
			}
			str[place] = new unit(s, poli2);
			State[place] = 1;
			size = size + 1;
			index = place;
		}
	}
}

void HashTable::Delete(const string k) 
{
	if (Search(k) == nullptr)
	{
		throw "В хэш-таблицах отсутствует элемент, который хотите удалить.";
	}
	else
	{
		str[index] = NULL;
		State[index] = -1;
		size = size - 1;
	}
}

unit* HashTable::Search(const string k)
{
	int place = hash(k);
	int first = -10;

	if (str[place] == NULL)
	{
		return nullptr;
	}
	else if ((State[place] != 0) && (str[place]->key != k))
	{
		first = place;
		place = (place + 11) % max_size;
		while ((State[place] != 0) && (place != first) && (str[place]->key != k))
		{
			place = (place + 11) % max_size;
		}
	}

	if (State[place] != 1)
	{
		return nullptr;
	}
	else if (place == first)
	{
		return nullptr;
	}
	else if (str[place]->key == k)
	{
		index = place;
		return str[place];
	}
}