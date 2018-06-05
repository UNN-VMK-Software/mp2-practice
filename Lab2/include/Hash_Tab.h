#pragma once
#include "Tab.h" 
#include <string>
#include <cstdlib> 
#include <cmath>
using namespace std;
#define FREE 0
#define BUSY 1
#define DELETE -1 


template <class KeyField, class DataField>
class HashTab : public Table <KeyField, DataField>
{
private:
	void Realloc();
	int ReHash(const KeyField &k) const;
	int *STATUS;
public:
	HashTab(int SIZE = 20) : Table<KeyField, DataField>(SIZE)
	{
		STATUS = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
			STATUS[i] = FREE;
	};
	~HashTab() {};
	void Insert(const KeyField &KEY, const DataField &DATA); 
	void Delete(const KeyField &KEY);	
	void GoNext();
	virtual int GetMaxSize() { return MaxSize; };
	virtual int GetCurrent() { return current; };
	DataTable<KeyField, DataField>* Search(const KeyField &KEY) const;		 

};
template <class KeyField, class DataField>
void HashTab<KeyField, DataField>::GoNext()
{
	bool flag = true;
	int i = current;
	while (flag == true)
	{
		if (STATUS[i] == BUSY)
		{
			flag = false;
			current = i;
		}
		i++;
	}
}

template <class KeyField, class DataField>  
int HashTab<KeyField, DataField>::ReHash(const KeyField& k) const
{
	int g = 17;
	int hash = 0;
	for (int i = 0; i < k.length(); i++)
		hash = g * hash + k[i];
	return (hash % (this->MaxSize));
}

template <class KeyField, class DataField>
void HashTab<KeyField, DataField>::Realloc()
{
	int i = 0;
	int NextSize = (this->MaxSize)*2;
	DataTable<KeyField, DataField> ** NewDATATAB = new DataTable<KeyField, DataField> *[NextSize];
	int * STATUS1 = new int[NextSize];
	for (int i = 0; i < this->MaxSize; i++)
		STATUS1[i] = STATUS[i];
	for (int i = this->MaxSize; i < NextSize; i++)
		STATUS1[i] = FREE;
	delete[]STATUS;
	STATUS = STATUS1;
	//
	for (int i = 0; i<this->MaxSize; i++)
		NewDATATAB[i] = this->DATATAB[i];
	for (int i = this->MaxSize; i < NextSize; i++)
		NewDATATAB[i] = NULL;
	delete[] this->DATATAB;
	this->DATATAB = NewDATATAB;
	this->MaxSize = NextSize;
}

template <class KeyField, class DataField>
void HashTab<KeyField, DataField>::Insert(const KeyField &KEY, const DataField &DATA)
{
	if ((double)this->current / (double)this->MaxSize > 0.5)  
		Realloc();
	int place = ReHash(KEY);
	if (STATUS[place] == FREE) 
	{
		this->DATATAB[place] = new DataTable<KeyField, DataField>(KEY, DATA); STATUS[place] = BUSY; this->current++;
	}
	else if (STATUS[place] == DELETE)
	{
		this->DATATAB[place] = new DataTable<KeyField, DataField>(KEY, DATA); STATUS[place] = BUSY;
	}
	else
	{
		if ((*(this->DATATAB[place])).Key == KEY)
		{
			throw "duplicated key";
		}
		srand(place);
		int laker = rand() % (this->MaxSize);
		while (STATUS[laker] == BUSY)  
		{
			laker = rand() % (this->MaxSize);
			if ((this->DATATAB[laker] != NULL) && ((*(this->DATATAB[laker])).Key == KEY))
			{
				throw "duplicated key";
			}
		}
		this->DATATAB[laker] = new DataTable<KeyField, DataField>(KEY, DATA);
		if (STATUS[laker] == 0)
			this->current++;
		STATUS[laker] = BUSY;
	}
}

template <class KeyField, class DataField>
void HashTab<KeyField, DataField>::Delete(const KeyField &KEY)
{
	int place = ReHash(KEY);
	if (STATUS[place] == 0) 
		cout<< "Элемента нет в Хэш"<<'\n';
	if ((this->DATATAB[place] != NULL) && ((*(this->DATATAB[place])).Key == KEY))
	{
		delete this->DATATAB[place];
		this->DATATAB[place] = NULL;
		STATUS[place] = DELETE;
	}
	else
	{
		srand(place);
		while ((STATUS[place] == -1) || ((STATUS[place] == 1) && ((*(this->DATATAB[place])).Key != KEY))) 
			place = rand() % (this->MaxSize);
		if (STATUS[place] == 1) 
		{
			delete this->DATATAB[place];
			this->DATATAB[place] = NULL;
			STATUS[place] = DELETE;
		}
		else cout << "Элемента нет в Хэш" << '\n';
	}
}


template <class KeyField, class DataField>
DataTable<KeyField, DataField>* HashTab<KeyField, DataField>::Search(const KeyField &KEY) const
{
	int place = ReHash(KEY);
	if (STATUS[place] == 0) 
		throw "element doesn't exist";
	if ((this->DATATAB[place] != NULL) && ((*(this->DATATAB[place])).Key) == KEY)
	{
		return this->DATATAB[place];
	}
	else
	{
		srand(place);
		while ((STATUS[place] == -1) || ((STATUS[place] == 1) && ((*(this->DATATAB[place])).Key != KEY))) 
			place = rand() % (this->MaxSize);
		if (STATUS[place] == 1) 
		{
			return this->DATATAB[place];
		}
		else
			throw "element doesn't exist";
	}

}
