#pragma once

#include "Table.h"
int freedom = 0; // элемент свободен 
int busy = 1; // элемент занят
int removed = -1; // эдемент был удалён

class HashTable : table
{
private:
	int current_size; // текущий размер
	int hash(string key) const; // хэш-функция
	void Repacking() override; // перепаковка
	int *State; // состояние элемента
public:
	HashTable(int nsize = 2); // конструктор

	void Insert(const string s, const TPolinom &poli2) override;
	void Delete(const string k) override;
	TPolinom Search(const string k) const override;
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
	unit *tmp = new unit[max_size];

	for (int i = 0; i < current_size; i++)
	{
		if (State[i] != freedom)
		{
			int j = hash(str[i].key);
			tmp[j] = str[i];
		}
	}

	str = tmp;
}

HashTable::HashTable(int nsize = 2) : table(nsize)
{
	current_size = 0;
	State = new int[nsize]; for (int i = 0; i < nsize; i++)
	{
		State[i] = freedom;
	}
}

void HashTable::Insert(const string s, const TPolinom &poli2)
{
	if ((current_size / max_size) > 0,63)
	{
		Repacking();
	}
		
	int place = hash(s);
	if (State[place] == freedom)
	{
		str[place] = unit(s, poli2);
	}
	else 
	{
		while (State[place] != freedom)
		{
			place = (place + 11) % max_size;
		}
		str[place] = unit(s, poli2);
		State[place] = busy;
		current_size = current_size + 1;
	}
}

void HashTable::Delete(const string k)
{
	int place = hash(k);
	int one = place;
	
	// если не свободен, то заходим внутрь, запоминаем первый элемент сравнения (чтобы потом если попадем в цикл, могли знать, что прошли и надо выдавать ошибку), идем по циклу и если находим свободный, не подходящий по ключу, выдаем ошибку
	if (State[place] != freedom)
	{
		place = (place + 11) % max_size;
		
				
		if (str[place].key == k)
		{
			State[place] = removed;
		}
		else
		{
			place = (place + 11) % max_size;
		}
	}
	else
	{
		throw "Error";
	}
}

