#pragma once
#include "table.h"

#pragma once
#include "table.h"

template <typename T>
class HashTable : public Table<T> 
{
protected:
	int* flag;
	int HashFunc(string key) const;
	void Realloc();
public:

	HashTable(unsigned int i = 10);
	HashTable(const HashTable<T>& TabToCopy);
	~HashTable() { delete[] flag; };
	//виртуальные
	virtual void Insert(const T data, const string key);
	virtual T* Search(const string key);
	virtual void Delete(const string key);
	//навигация
	virtual void SetNext();
	virtual T* GetCurr() const;
	virtual void Reset();
	virtual bool IsTabEnded() const { return this->currIndex == this->currRecord || this->currIndex == -1; };// return false;
	template<class T> friend std::ostream& operator<< (std::ostream& os, const HashTable<T>& Tab);

};

template <typename T>
HashTable<T>::HashTable(unsigned int i) : Table<T>(i)
{
	flag = new int[i];
	for (int j = 0; j < i; j++)
		flag[j] = 0; // 0 пуста, 1 -заполнена, -1 - удалена
}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& TabToCopy)
{
	maxRecord = TabToCopy.maxRecord;
	currIndex = TabToCopy.currIndex;
	currRecord = TabToCopy.currRecord;
	delete[] rows;
	delete[] flag;
	rows = new TabRecord<T>*[maxRecord];
	flag = new int[maxRecord];

	for (int j = 0; j < maxRecord; j++)
		flag[j] = TabToCopy.flag[j];

	if (!IsEmpty())
		for (int i = 0; i < maxRecord; i++)
		{
			if (flag[i] == 1)
				rows[i] = new TabRecord<T>(*(TabToCopy.rows[i]));
		}
}

template <typename T>
void HashTable<T>::Reset()
{
	if (!(this->IsEmpty()))
	{
		this->currIndex = 0;
		while (flag[this->currIndex] != 1)
			this->currIndex++;
	}
	else
		this->currIndex = -1;
}

template <typename T>
T* HashTable<T>::GetCurr()  const
{
	T* tmp = nullptr;

	if (!(this->IsEmpty()))
	{
		tmp = this->rows[this->currIndex]->data;
	}
	else
	{
		throw "Table Is Empty";
	}
	return tmp;
}

template <typename T>
void HashTable<T>::SetNext()
{
	if (!(this->IsEmpty()))
	{
		this->currIndex++;
		while (flag[this->currIndex] != 1)
			this->currIndex = (this->currIndex + 1) % this->maxRecord;
	}
	else
		throw "Table Is Empty";

}

template <typename T>
void HashTable<T>::Realloc()
{
	unsigned int OldMaxRecords = this->maxRecord;
	this->maxRecord *= 1.5;
	TabRecord<T>** tmp = new TabRecord<T>*[OldMaxRecords];
	for (int i = 0; i < OldMaxRecords; i++)
	{
		tmp[i] = new TabRecord<T>(*(this->rows[i]));
	}

	delete[] this->rows;
	this->currRecord = 0;
	this->currIndex = -1;
	delete[] flag;
	flag = new int[this->maxRecord];
	for (int i = 0; i < this->maxRecord; i++)
		flag[i] = 0;
	this->rows = new TabRecord<T>*[this->maxRecord];
	for (int i = 0; i < OldMaxRecords; i++)
	{
		this->Insert(*(tmp[i]->data), tmp[i]->key); // ? 
	}
}

template<typename T>
int HashTable<T>::HashFunc(string key) const
{
	unsigned int i = 0;
	for (int j = 0; j < key.length(); j++)
		i += (char)key[j];
	for (int j = 0; j < key.length(); j++)
		i *= 13;
	srand(i);
	unsigned int h = rand();
	return h % this->maxRecord;
}

template <typename T>
void HashTable<T>::Insert(const T data, const string key)
{
	if (this->IsFull())
		this->Realloc();
	TabRecord<T> Row(key, data);
	this->Reset();
	this->currIndex = HashFunc(key);
	if (flag[this->currIndex] == 0 || flag[this->currIndex] == -1)
	{
		this->rows[this->currIndex] = new TabRecord<T>(Row);
		this->currRecord++;
		flag[this->currIndex] = 1;
		this->Reset();
	}
	else
	{
		if (this->rows[this->currIndex]->key != key)
		{
			int ind = this->currIndex;
			while (flag[this->currIndex] == 1 && this->currIndex + 1 != ind)
				this->currIndex = (this->currIndex + 1) % this->maxRecord; // 
			this->rows[this->currIndex] = new TabRecord<T>(Row);
			this->currRecord++;//
			flag[this->currIndex] = 1;
			this->Reset();
		}
		else
		{
			this->Reset();
			throw "Your key isn't unique";
		}
	}
}

template <typename T>
T* HashTable<T>::Search(const string Key)
{
	/*this->Reset();
	T* tmp = nullptr;
	if (!(this->IsEmpty()))
	{
		this->currIndex = HashFunc(key);
		if (this->rows[this->currIndex]->key == key)
			tmp = this->rows[this->currIndex]->data;
		else
		{
			int ind = this->currIndex;
			while (flag[this->currIndex] == 1 && this->currIndex + 1 != ind)
			{
				this->currIndex = (this->currIndex + 1) % this->maxRecord;
				if (this->rows[this->currIndex]->key == key)
				{
					tmp = this->rows[this->currIndex]->data;
					break;
				}
			}

			if (tmp == nullptr)
			{
				this->Reset();
				throw "Your key wasn't found";
			}
		}
	}
	else
	{
		throw (string)"Can't Search In Empty Table";
	}
	return tmp;*/
	this->Reset();
	T* tmp = nullptr;
	if (this->IsEmpty())
		throw (string)"Can't Search In Empty Table";
	this->currIndex = HashFunc(Key);

	if (((this->rows[this->currIndex]->key)=!nullptr) && (this->rows[this->currIndex]->key == Key))
		tmp = this->rows[this->currIndex]->data;
	else
	{
		int ind = this->currIndex;
		while (flag[this->currIndex] == 1 && this->currIndex + 1 != ind)
		{
			this->currIndex = (this->currIndex + 1) % this->maxRecord;
			if (this->rows[this->currIndex]->key == Key)
			{
				tmp = this->rows[this->currIndex]->data;
				break;
			}
		}

		if (tmp == nullptr)
		{
			this->Reset();
			throw "Your key wasn't found";
		}

	}
	return tmp;
}
template <typename T>
void HashTable<T>::Delete(string key)
{
	if (Search(key) == nullptr)
	{
		throw "Can't Delete From Empty Table.";
	}
	else
	{
		this->rows[this->currIndex] = NULL;
		flag[this->currIndex] = -1;
		this->currRecord = this->currRecord - 1;
	}
	/*this->Reset();
	if (this->IsEmpty())
		throw (string)"Can't Delete From Empty Table";
	this->Search(key);

	TabRecord<T> A;
	flag[this->currIndex] = -1;
	this->rows[this->currIndex] = new TabRecord<T>(A);
	this->currRecord--;
	this->Reset();*/
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const HashTable<T>& Tab)
{
	unsigned int i = 0;
	while (i < Tab.maxRecord)
	{
		if (Tab.flag[i] == 1)
		{
			os << i << ". " << Tab.rows[i]->key << "  |   " << *(Tab.rows[i]->data) << std::endl;
		}
		i++;
	}
	if (Tab.currRecord == 0)
		os << "Table is Empty";
	return os;
}
