#pragma once
#include "Tables.h" 
#include "math.h"
#include <string>
using namespace std;
template <class KeyType, class DataType>
class TableUnord : public Table <KeyType, DataType>
{
public:
	TableUnord(int SIZE = MIN_SIZE) : Table<KeyType, DataType>(SIZE) {};
	virtual ~TableUnord() {};
	virtual void Insert(const KeyType &KT_T, const DataType &DT_D); // вставка в неупорядоченный таблице
	virtual void Dell(const KeyType &KT_T);					// удаление элемента 
	virtual DataTable<KeyType, DataType>* Search(const KeyType &KT_T) const;		// поиск элемена по ключу 
																					//вывод
private:
	virtual void Reallocate(); //перераспределение 
};

template <class KeyType, class DataType>
void TableUnord <KeyType, DataType> ::Reallocate()
{
	int NextSize = (int)(this->MaxSize + 20)*1.65;
	DataTable<KeyType, DataType> ** NewDT = new DataTable<KeyType, DataType>*[NextSize];
	for (int i = 0; i<this->MaxSize; i++)
		NewDT[i] = this->DT[i];
	for (int i = this->MaxSize; i<NextSize; i++)
		NewDT[i] = NULL;
	delete[] this->DT;
	this->DT = NewDT;
	this->MaxSize = NextSize;
};


template <class KeyType, class DataType>
void TableUnord< KeyType, DataType> ::Insert(const KeyType &KT_T, const DataType &DT_D)
{
	if ((double)this->Top / (double)this->MaxSize > 0.7) // перераспределить если до заполнения осталось менее 30 процентов 
		Reallocate();
	for (int i = 0; i < this->Top; i++)
	{
		if ((*(this->DT[i])).Key == KT_T)
		{
			throw "duplicated key";
		}
	}
	this->DT[this->Top++] = new DataTable<KeyType, DataType>(KT_T, DT_D);
};

template <class KeyType, class DataType> //прочекать на правильность
void TableUnord< KeyType, DataType> ::Dell(const KeyType &KT_T)
{
	int i = 0;
	int flag = 0;
	while ((i < this->Top) && (flag == 0)) {
		if ((*(this->DT[i])).Key == KT_T) flag = 1;
		i++;
	}
	if (flag == 1) {
		i--;
		delete this->DT[i];
		while (i < this->Top - 1) {
			this->DT[i] = this->DT[i + 1];
			i++;
		}
		this->DT[i] = NULL;
		this->Top--;
	}
	else throw "element doesn't exist";
};

template <class KeyType, class DataType>
DataTable<KeyType, DataType>* TableUnord< KeyType, DataType> ::Search(const KeyType &KT_T) const
{
	int i = 0;
	while (i < this->Top)
	{
		if ((*(this->DT[i])).Key == KT_T)
			return this->DT[i];
		i++;
	}
	throw "element doesn't exist";
};

