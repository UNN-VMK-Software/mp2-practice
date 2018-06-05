#pragma once
#include "Tab.h"

template <class KeyField, class DataField>
class SortTab : public Table<KeyField, DataField>
{
public:
	SortTab(int SIZE = MIN_SIZE) : Table<KeyField, DataField>(SIZE) {};
	virtual ~SortTab() {};
	virtual void Insert(const KeyField &KEY, const DataField &DATA); 
	virtual void Delete(const KeyField &KEY);	
	virtual int GetCurrent() { return current; };
	virtual DataTable<KeyField, DataField>* Search(const KeyField &KEY) const;		 
private:
	virtual void Realloc();  
	int BinSearch(const KeyField &Key) const; 
};

template <class KeyField, class DataField>
void SortTab <KeyField, DataField> ::Realloc()
{
	int NextSize = (this->MaxSize)*2;
	DataTable <KeyField, DataField> ** NewDataTab = new DataTable <KeyField, DataField>*[NextSize];
	for (int i = 0; i<this->MaxSize; i++)
		NewDataTab[i] = this->DATATAB[i];
	for (int i = this->MaxSize; i<NextSize; i++)
		NewDataTab[i] = NULL;
	delete[] this->DATATAB;
	this->DATATAB = NewDataTab;
	this->MaxSize = NextSize;
}

template <class KeyField, class DataField>
int SortTab <KeyField, DataField> ::BinSearch(const KeyField &Key) const  
{
	int tail = this->Top - 1;
	int mid = 0;
	int start = 0;
	while (start <= tail)
	{
		mid = (tail + start) / 2;
		if ((*(this->DATATAB[mid])).Key < Key)
			start = mid + 1;
		else if ((*(this->DATATAB[mid])).Key > Key)
			tail = mid - 1;
		else return mid; 
	}
	if (start > tail)
		mid = start;
	return mid;

}

template <class KeyField, class DataField>
void SortTab <KeyField, DataField> ::Insert(const KeyField &KEY, const DataField &DATA)
{
	int area = BinSearch(KEY);
	int j;
	if ((this->DATATAB[area] == NULL) || ((*(this->DATATAB[area])).Key != KEY))
	{
		if ((double)this->Top / (double)this->MaxSize > 0.7)  
			Realloc();
		for (j = this->Top; j > area; j--)
			this->DATATAB[j] = this->DATATAB[j - 1];
		this->DATATAB[j] = new DataTable<KeyField, DataField>(KEY, DATA);
		this->Top++;
	}
	else throw "duplicate key";
}

template <class KeyField, class DataField>
void  SortTab <KeyField, DataField> ::Delete(const KeyField &KEY)
{
	int area = BinSearch(KEY);

	if ((this->DATATAB[area] != NULL) && ((*(this->DATATAB[area])).Key == KEY))
	{
		delete this->DATATAB[area];
		for (int i = area; i < this->Top; i++)
			this->DATATAB[i] = this->DATATAB[i + 1];
		this->Top -= 1;
	}
	else
		cout<< "Элемента нет в Сорт"<<'\n';
}

template <class KeyField, class DataField>
DataTable<KeyField, DataField>* SortTab <KeyField, DataField> ::Search(const KeyField &KEY) const
{
	int area = BinSearch(KEY);
	if ((this->DATATAB[area] != NULL) && ((*(this->DATATAB[area])).Key == KEY))
		return this->DATATAB[area];
	else throw "element doesn't exist";
}
