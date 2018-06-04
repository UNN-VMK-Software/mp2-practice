#pragma once
#include "Tables.h" 
#include <string>
using namespace std;
//дубликаты ключа при вставке;
template <class typeK, class typeD>
class hashtable : public Table <typeK, typeD>
{
public:
	hashtable(int size = 30) : Table<typeK, typeD>(size)
	{
		dm = new int[size];
		for (int i = 0; i < size; i++)
			dm[i] = 0;
	};
	~hashtable() {};
	void insert(const typeK &k, const typeD &d); // вставка в неупорядоченный таблице
	void delet(const typeK &k);					// удаление элемента 
	dataTable<typeK, typeD>* search(const typeK &k) const;		// поиск элемена по ключу 
private:
	void realocate(); //перераспределение памяти
	int Hashfunc(const typeK &k) const;// ищет место для вставки
	int *dm; // указатель на место вставки
};

template<class typeK>
int getkey(const typeK& k)
{ 
	return 0; 
}

template<>
int getkey<string>(const string &k)  // реализация хэш функции для string
{
	int g = 31;
	int hash = 0;
	for (int i = 0; i < k.length(); i++)
		hash = g * hash + k[i];
	return hash;
}

template <class typeK, class typeD>  // хэш функция внутри класса (метод)
int hashtable<typeK, typeD>::Hashfunc(const typeK& k) const
{
	int temp = getkey(k); 
	return (temp % (this->maxsize));
}

template <class typeK, class typeD>
void hashtable<typeK, typeD>::realocate()
{
	int i = 0;
	int nextsize = (int)(this->maxsize + 20)*1.65;
	dataTable<typeK, typeD> ** newdt = new dataTable<typeK, typeD> *[nextsize];
	int * dm1 = new int[nextsize];
	for (int i = 0; i < this->maxsize; i++)
		dm1[i] = dm[i];
	for (int i = this->maxsize; i < nextsize; i++)
		dm1[i] = 0;
	delete[]dm;
	dm = dm1;

	for (int i = 0; i<this->maxsize; i++)
		newdt[i] = this->dt[i];
	for (int i = this->maxsize; i < nextsize; i++)
		newdt[i] = NULL;
	delete[] this->dt;
	this->dt = newdt;
	this->maxsize = nextsize;
}

template <class typeK, class typeD>
void hashtable<typeK, typeD>::insert(const typeK &k, const typeD &d)//вставка
{
	if ((double)this->curind / (double)this->maxsize > 0.7) // перераспределить если до заполнения осталось 40 процентов 
		realocate();
	int place = Hashfunc(k);
	if (dm[place] == 0) //ячейка свободна
	{
		this->dt[place] = new dataTable<typeK, typeD>(k, d); dm[place] = 1; this->curind++;
	}
	else if (dm[place] == -1)
	{
		this->dt[place] = new dataTable<typeK, typeD>(k, d); dm[place] = 1;
	}
	else
	{
		if ((*(this->dt[place])).key == k)
		{
			throw "duplicated key";
		}
		int next = place + 1;
		while (dm[next] == 1) //пока элемент занят 
		{
			next = next + 1;
			if ((this->dt[next] != NULL) && ((*(this->dt[next])).key == k))
			{
				throw "duplicated key";
			}
		}
		this->dt[next] = new dataTable<typeK, typeD>(k, d);
		if (dm[next] == 0)
			this->curind++;
		dm[next] = 1;
	}
}

template <class typeK, class typeD>
void hashtable<typeK, typeD>::delet(const typeK &k)
{
	int place = Hashfunc(k);
	if (dm[place] == 0) //элемента нет
		throw "element doesn't exist";
	if ((this->dt[place] != NULL) && ((*(this->dt[place])).key == k))
	{
		delete this->dt[place];
		this->dt[place] = NULL;
		dm[place] = -1;
	}
	else
	{
		while ((dm[place] == -1) || ((dm[place] == 1) && ((*(this->dt[place])).key != k))) //если элемент был удалён, или он занят, но не совпадают ключи - обновить место
			place = place + 1;
		if (dm[place] == 1) // совпадают ключи
		{
			delete this->dt[place];
			this->dt[place] = NULL;
			dm[place] = -1;
		}
		else throw "element doesn't exist";
	}
}


template <class typeK, class typeD>
dataTable<typeK, typeD>* hashtable<typeK, typeD>::search(const typeK &k) const
{
	int place = Hashfunc(k);
	if (dm[place] == 0) //элемента нет
		throw "element doesn't exist";
	if ((this->dt[place] != NULL) && ((*(this->dt[place])).key) == k)
	{
		return this->dt[place];
	}
	else
	{
		while ((dm[place] == -1) || ((dm[place] == 1) && ((*(this->dt[place])).key != k))) //если элемент был удалён, или он занят, но не совпадают ключи - обновить место
			place = place + 1;
		if (dm[place] == 1) // совпадают ключи
		{
			return this->dt[place];
		}
		else
			throw "element doesn't exist";
	}

}