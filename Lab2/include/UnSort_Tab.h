#pragma once
#include "Tab.h" 
#include "math.h"
#include <string>
using namespace std;
template <class KeyField, class DataField>
class UnSortTab : public Table <KeyField, DataField>
{
public:
	UnSortTab(int SIZE = MIN_SIZE) : Table<KeyField, DataField>(SIZE) {};
	virtual ~UnSortTab() {};
	virtual void Insert(const KeyField &KEY, const DataField &DATA); 
	virtual void Delete(const KeyField &KEY);	
	virtual int GetMaxSize() { return MaxSize; };
	virtual int GetCurrent() { return current; };
	virtual DataTable<KeyField, DataField>* Search(const KeyField &KEY) const;		 
																					
private:
	virtual void Realloc();  
};

template <class KeyField, class DataField>
void UnSortTab <KeyField, DataField> ::Realloc()
{
	int NextSize = (this->MaxSize)*2;
	DataTable<KeyField, DataField> ** NewDATATAB = new DataTable<KeyField, DataField>*[NextSize];
	for (int i = 0; i<this->MaxSize; i++)
		NewDATATAB[i] = this->DATATAB[i];
	for (int i = this->MaxSize; i<NextSize; i++)
		NewDATATAB[i] = NULL;
	delete[] this->DATATAB;
	this->DATATAB = NewDATATAB;
	this->MaxSize = NextSize;
};


template <class KeyField, class DataField>
void UnSortTab< KeyField, DataField> ::Insert(const KeyField &KEY, const DataField &DATA)
{
	if ((double)this->Top / (double)this->MaxSize > 0.5)  
		Realloc();
	for (int i = 0; i < this->Top; i++)
	{
		if ((*(this->DATATAB[i])).Key == KEY)
		{
			throw "duplicated key";
		}
	}
	this->DATATAB[this->Top++] = new DataTable<KeyField, DataField>(KEY, DATA);
};

template <class KeyField, class DataField> 
void UnSortTab< KeyField, DataField> ::Delete(const KeyField &KEY)
{
	int i = 0;
	int flag = 0;
	while ((i < this->Top) && (flag == 0)) {
		if ((*(this->DATATAB[i])).Key == KEY) flag = 1;
		i++;
	}
	if (flag == 1) {
		i--;
		delete this->DATATAB[i];
		while (i < this->Top - 1) {
			this->DATATAB[i] = this->DATATAB[i + 1];
			i++;
		}
		this->DATATAB[i] = NULL;
		this->Top--;
	}
	else cout<< "Элемента нет в АнСорт"<<'\n';
};

template <class KeyField, class DataField>
DataTable<KeyField, DataField>* UnSortTab< KeyField, DataField> ::Search(const KeyField &KEY) const
{
	int i = 0;
	while (i < this->Top)
	{
		if ((*(this->DATATAB[i])).Key == KEY)
			return this->DATATAB[i];
		i++;
	}
	throw "element doesn't exist";
};
