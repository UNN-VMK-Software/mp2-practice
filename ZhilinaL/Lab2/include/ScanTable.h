#pragma once
#include "table.h"

template <typename T>
class ScanTable : public Table<T>
{
protected:
	virtual void Realloc();
public:
	
	ScanTable(unsigned int i = 10) : Table<T>(i) {};
	ScanTable(const ScanTable<T>& TabToCopy);
	~ScanTable() { };
	//виртуальные
	virtual void Insert(const T Data, const string Key);
	virtual T* Search(const string Key);
	virtual void Delete(const string Key);

	template<class T> friend std::ostream& operator<< (std::ostream& os, const ScanTable<T>& Tab);

};

template <typename T>
ScanTable<T>::ScanTable(const ScanTable<T>& TabToCopy)
{
	this->maxRecord = TabToCopy.maxRecord;
	this->currIndex = TabToCopy.currIndex;
	this->currRecord = TabToCopy.currRecord;
	delete[] rows;
	this->rows = new TabRecord<T>*[maxRecord];
	if (!IsEmpty())
		for (int i = 0; i < this->currRecord; i++)
			this->rows[i] = new TabRecord<T>(*(TabToCopy.rows[i]));
}

template <typename T>
void ScanTable<T>::Realloc()
{
	unsigned int NewMaxRecords = (unsigned int)(this->maxRecord*1.5);
	TabRecord<T>** tmp = new TabRecord<T>*[NewMaxRecords];
	for (int i = 0; i < this->maxRecord; i++)
		tmp[i] = this->rows[i];
	this->maxRecord = NewMaxRecords;
	delete[] this->rows;
	this->rows = tmp;
}

template <typename T>
void ScanTable<T>::Insert(const T Data, const string Key)
{
	if (this->IsFull())
		this->Realloc();
	TabRecord<T> Row(Key, Data);
	this->Reset();
	while (!(this->IsTabEnded()) && Key != this->rows[this->currIndex]->key)
		this->currIndex++;
	if (this->IsEmpty())
	{
		this->currIndex++;
	}
	if (this->currIndex == this->currRecord)
	{
		this->rows[this->currIndex] = new TabRecord<T>(Row);
		this->currRecord++;
		this->Reset();
	}
	else
	{
		this->Reset();
		throw "Your key isn't unique";
	}
}

template <typename T>
T* ScanTable<T>::Search(const string Key)
{
	this->Reset();
	T* tmp = nullptr;
	if (this->IsEmpty())
		throw (string)"Cant Search In Empty Table";
	while (!(this->IsTabEnded()) && Key != this->rows[this->currIndex]->key)
		this->currIndex++;
	if (!(this->IsTabEnded()))
		tmp = this->rows[this->currIndex]->data;
	else
	{
		throw "Your key wasn't found";
	}
	return tmp;
}

template <typename T>
void ScanTable<T>::Delete(string Key)
{
	if (Search(Key) == nullptr)
	{
		throw "Can't Delete From Empty Table";
	}
	else
	{
		this->rows[this->currIndex]->data = this->rows[this->currRecord - 1]->data;
		this->rows[this->currIndex]->key = this->rows[this->currRecord - 1]->key;
		this->rows[this->currRecord - 1] = NULL;
		this->currRecord = this->currRecord - 1;
		this->currIndex = this->currRecord - 1;
	}
	/*this->Reset();
	if (this->IsEmpty())
		throw "Can't Delete From Empty Table";
	this->Search(Key);
	if (this->currRecord > 1)
		this->rows[this->currIndex] = this->rows[--this->currRecord];
	else
		this->currRecord = 0;*/
}


template <typename T>
std::ostream& operator<< (std::ostream& os, const ScanTable<T>& Tab)
{
	unsigned int i = 0;
		while (i < Tab.currRecord)
		{
			os << i << ". " << Tab.rows[i]->key << "  |   " << *(Tab.rows[i]->data) << std::endl;
			i++;
		}
		if (Tab.currRecord == 0)
			os << "Table is Empty";
		return os;
	
}
