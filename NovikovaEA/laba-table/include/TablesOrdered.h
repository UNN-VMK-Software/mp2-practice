#pragma once
#include "Tables.h"

template <class typeK, class typeD>
class ordertable : public Table<typeK, typeD>
{
public:
	ordertable(int size = 30) : Table<typeK, typeD>(size) {};
	virtual ~ordertable() {};
	virtual void insert(const typeK &k, const typeD &d); // вставка в упорядоченную таблицу таблице
	virtual void delet(const typeK &k);					// удаление элемента 
	virtual dataTable<typeK, typeD>* search(const typeK &k) const;		// поиск элемена по ключу 
private:
	virtual void realocate(); //перераспределение 
	int Binarsearch(const typeK &key) const; //бинарный поиск
};

template <class typeK, class typeD>
void ordertable <typeK, typeD> ::realocate()
{
	int nextsize = (int)(this->maxsize + 20)*1.65;
	dataTable <typeK, typeD> ** newdt = new dataTable <typeK, typeD>*[nextsize];
	for (int i = 0; i<this->maxsize; i++)
		newdt[i] = this->dt[i];
	for (int i = this->maxsize; i<nextsize; i++)
		newdt[i] = NULL;
	delete[] this->dt;
	this->dt = newdt;
	this->maxsize = nextsize;
}

template <class typeK, class typeD>
int ordertable <typeK, typeD> ::Binarsearch(const typeK &key) const  //возвращает индекс (номер строки в таблице)
{
	int tail = this->top - 1;
	int middle = 0;
	int start = 0;
	while (start <= tail)
	{
		middle = (tail + start) / 2;
		if ((*(this->dt[middle])).key < key)
			start = middle + 1;
		else if ((*(this->dt[middle])).key > key)
			tail = middle - 1;
		else return middle;
	}
	if (start > tail)
		middle = start;
	return middle;

}

template <class typeK, class typeD>
void ordertable <typeK, typeD> ::insert(const typeK &k, const typeD &d) // вставка
{
	int a = Binarsearch(k);
	int j;
	if ((this->dt[a] == NULL) || ((*(this->dt[a])).key != k)) // то, что было = 0 или ключи не совпали
	{
		if ((double)this->top / (double)this->maxsize > 0.7) // перераспределить если до заполнения осталось 40 процентов 
			realocate();
		for (j = this->top; j > a; j--)
			this->dt[j] = this->dt[j - 1];
		this->dt[j] = new dataTable<typeK, typeD>(k, d);
		this->top++;
	}
	else throw "duplicate key";
}

template <class typeK, class typeD>
void  ordertable <typeK, typeD> ::delet(const typeK &k)
{
	int a = Binarsearch(k);

	if ((this->dt[a] != NULL) && ((*(this->dt[a])).key == k)) // если не пусто, но ключи совпали
	{
		delete this->dt[a];
		for (int i = a; i < this->top; i++)
			this->dt[i] = this->dt[i + 1];
		this->top -= 1;
	}
	else
		throw "element doesn't exist";
}

template <class typeK, class typeD>
dataTable<typeK, typeD>* ordertable <typeK, typeD> ::search(const typeK &k) const
{
	int a = Binarsearch(k);
	if ((this->dt[a]!=NULL)&&((*(this->dt[a])).key == k))
		return this->dt[a];
	else throw "element doesn't exist";
}
