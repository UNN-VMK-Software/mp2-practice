#pragma once
#include "Tables.h" 
#include "math.h"
#include <string>
using namespace std;
template <class typeK, class typeD>
class unordtable : public Table <typeK, typeD>
{
public:
	unordtable(int size = 30) : Table<typeK, typeD>(size) {};
	virtual ~unordtable() {};
	virtual void insert(const typeK &k, const typeD &d); // вставка в неупорядоченный таблице
	virtual void delet(const typeK &k);					// удаление элемента 
	virtual dataTable<typeK, typeD>* search(const typeK &k) const;		// поиск элемена по ключу 
																					
private:
	virtual void realocate(); //перераспределение 
};

template <class typeK, class typeD>
void unordtable <typeK, typeD> ::realocate()
{
	int nextsize = (int)(this->maxsize + 20)*1.65;
	dataTable<typeK, typeD> ** newdt = new dataTable<typeK, typeD>*[nextsize];
	for (int i = 0; i<this->maxsize; i++)
		newdt[i] = this->dt[i];
	for (int i = this->maxsize; i<nextsize; i++)
		newdt[i] = NULL;
	delete[] this->dt;
	this->dt = newdt;
	this->maxsize = nextsize;
};


template <class typeK, class typeD>
void unordtable< typeK, typeD> ::insert(const typeK &k, const typeD &d)
{
	if ((double)this->top / (double)this->maxsize > 0.7) // перераспределить если до заполнения осталось менее 30 процентов 
		realocate();
	for (int i = 0; i < this->top; i++)
	{
		if ((*(this->dt[i])).key == k)
		{
			throw "duplicated key";
		}
	}
	this->dt[this->top++] = new dataTable<typeK, typeD>(k, d);
};

template <class typeK, class typeD>
void unordtable< typeK, typeD> ::delet(const typeK &k)
{
	int i = 0;
	int flag = 0;
	while ((i < this->top) && (flag == 0))
	{
		if ((*(this->dt[i])).key == k) flag = 1;
		i++;
	}
	if (flag == 1)
	{
		i--;
		delete this->dt[i];
		while (i < this->top - 1)
		{
			this->dt[i] = this->dt[i + 1];
			i++;
		}
		this->dt[i] = NULL;
		this->top--;
	}
	else throw "element doesn't exist";
};

template <class typeK, class typeD>
dataTable<typeK, typeD>* unordtable< typeK, typeD> ::search(const typeK &k) const
{
	int i = 0;
	while (i < this->top)
	{
		if ((*(this->dt[i])).key == k)
			return this->dt[i];
		i++;
	}
	throw "element doesn't exist";
};
