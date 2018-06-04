#include "table.h"

template <typename T>
class SortedTable : public Table<T>
{
protected:
	void Realloc();
public:
	
	SortedTable(unsigned int i = 10): Table<T>(i) {};
	SortedTable(const SortedTable<T>& TabToCopy);
	~SortedTable() {};
	//виртуальные
	virtual void Insert(const T data, const string key);
	virtual T* Search(const string key);
	virtual void Delete(const string key);
	template<class T> friend std::ostream& operator<< (std::ostream& os, const SortedTable<T>& Tab);

};


template <typename T>
SortedTable<T>::SortedTable(const SortedTable<T>& TabToCopy)
{
	maxRecord = TabToCopy.maxRecord;
	currIndex = TabToCopy.currIndex;
	currRecord = TabToCopy.currRecord;
	delete[] rows;
	rows = new TabRecord<T>*[maxRecord];
	if (!IsEmpty())
		for (int i = 0; i < currRecord; i++)
			rows[i] = new TabRecord<T>(*(TabToCopy.rows[i]));
}

template <typename T>
void SortedTable<T>::Realloc()
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
void SortedTable<T>::Insert(const T data, const string key)
{
	if (this->IsFull())
		this->Realloc();

	TabRecord<T> Row(key, data);
	this->Reset();

	this->Reset();
	while (!(this->IsTabEnded()) && Row.key >= this->rows[this->currIndex]->key)
	{
		if (this->rows[this->currIndex]->key == Row.key)
		{
			throw "Your key isn't unique";
		}
		this->currIndex++;
	}
	if (this->IsEmpty())
		this->currIndex++;
	this->currRecord++;
	for (int i = this->currRecord - 1; i > this->currIndex; i--)
	{
		this->rows[i] = this->rows[i - 1];

	}
	this->rows[this->currIndex] = new TabRecord<T>(Row);
	this->Reset();

}

template <typename T>
T* SortedTable<T>::Search(const string key)
{
	this->Reset();
	T* tmp = nullptr;

	if (!(this->IsEmpty()))
	{
		int i = -1, j = this->currRecord;
		int mid;
		while (i < j - 1) 
		{
			mid = (j + i) / 2;
			if (key >= this->rows[mid]->key)
			{
				i = mid;
			}
			else
			{
				j = mid;
			}

		}
		if (key == this->rows[i]->key)
		{
			this->currIndex = i;
			tmp = this->rows[this->currIndex]->data;
		}
		else
		{
			throw "Your key wasn't found";
		}
	}
	else
		throw "Table Is Empty";
	return tmp;
}

template <typename T>
void SortedTable<T>::Delete(const string key)
{
	
	this->Reset();
	if (this->IsEmpty())
		throw "Can't Delete From Empty Table";
	this->Search(key);
	if (this->currRecord > 1)
	{
		this->currRecord--;
		for (int i = this->currIndex; i < this->currRecord; i++)
		{
			this->rows[i] = this->rows[i + 1];

		}
		this->Reset();
	}
	else
		this->currRecord = 0;
		
/*if (this->Search(key) == nullptr)
	{
		throw "Can't Delete From Empty Table.";
	}
	else
	{
		int i = 0;
		while (this->rows[i]->key > key)
		{
			i++;
		}

		for (int j = i; j < this->currRecord - 1; j++)
		{
			this->rows[j] = this->rows[j + 1];
		}
		this->rows[this->currRecord - 1] = NULL;
		this->currRecord = this->currRecord - 1;
	}*/

}

template <typename T>
std::ostream& operator<< (std::ostream& os, const SortedTable<T>& Tab)
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
