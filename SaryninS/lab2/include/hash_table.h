#pragma once
#include "table.h"
template <typename T>
class HashTable : public Table<T> 
{
protected:
	int* fl;
	int HashFunc(string Key) const;
	void Realloc();
public:
	HashTable(int i = 10);
	HashTable(const HashTable<T>& TabCopy);
	~HashTable() { delete[] fl;};
	void Insert(const T Data, const string Key);
	T* Search(const string Key);
	void Delete(const string Key);
	void SetNext();
	T* GetCurr() const;
	void Reset();
	bool IsEnded() const { return false; };
	template<class T> friend std::ostream& operator<< (std::ostream& os, const HashTable<T>& Tab);
};

template <typename T>
HashTable<T>::HashTable(int i) : Table(i)
{	
	fl = new int[i];
	for (int j = 0; j < i; j++)
		fl[j] = 0; 
}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& TabCopy)
{
	MaxRecords = TabCopy.MaxRecords;
	CurrIndex = TabCopy.CurrIndex;
	CurrSize = TabCopy.CurrSize;
	delete[] Records;
	delete[] fl;
	Records = new TabRecord<T>*[MaxRecords];
	fl = new int[MaxRecords];
	
	for (int j = 0; j < MaxRecords; j++)
		fl[j] = TabCopy.fl[j];

	if (!IsEmpty())
		for (int i = 0; i < MaxRecords; i++)
		{	
			if(fl[i] == 1)
				Records[i] = new TabRecord<T>(*(TabCopy.Records[i]));
		}
}

template <typename T>
void HashTable<T>::Reset()
{	
	if (!IsEmpty())
	{	
		CurrIndex = 0;
		while (fl[CurrIndex] != 1)
			CurrIndex++;
	}
	else
		CurrIndex = -1;
}

template <typename T>
T* HashTable<T>::GetCurr()  const
{
	T* tmp = nullptr;

	if(!IsEmpty())
	{	
		tmp = &(Records[CurrIndex]->Data);
	}
	else
	{
		throw (string)"empty table";
	}
	return tmp;
}

template <typename T>
void HashTable<T>::SetNext()
{
	if (!IsEmpty())
	{	
		CurrIndex++;
		while (fl[CurrIndex] != 1)
			CurrIndex = (CurrIndex+1) % MaxRecords;
	}
	else
		throw (string)"empty table";
	
}

template <typename T>
void HashTable<T>::Realloc()
{
	int OldMaxRecords = MaxRecords;
	MaxRecords *= 1.5;
	TabRecord<T>** tmp = new TabRecord<T>*[OldMaxRecords];
	for (int i = 0; i < OldMaxRecords; i++)
	{
		tmp[i] = Records[i];
	}
	delete[] Records;
	CurrSize = 0;
	CurrIndex = -1;
	delete[] fl;
	fl = new int[MaxRecords];
	for (int i = 0; i < MaxRecords; i++)
		fl[i] = 0;
	Records = new TabRecord<T>*[MaxRecords];
	for (int i = 0; i < OldMaxRecords; i++)
	{
		Insert(tmp[i]->Data, tmp[i]->Key);
	}
}

template<typename T>
int HashTable<T>::HashFunc(string Key) const
{	
	int i= 0;
	for (int j = 0; j < Key.length(); j++)
		i += (char)Key[j];
	for (int j = 0; j < Key.length(); j++)
		i *= 13;
	srand(i);
	int h = rand();
	return h % MaxRecords;
}

template <typename T>
void HashTable<T>::Insert(const T Data, const string Key)
{
	if (IsFull())
		Realloc();
	TabRecord<T>* TR = new TabRecord<T>(Key, Data);
	Reset();
	CurrIndex = HashFunc(Key);
	if (fl[CurrIndex] == 0 || fl[CurrIndex] == -1 )
	{
		Records[CurrIndex] = TR; 
		CurrSize++;
		fl[CurrIndex] = 1;
		Reset();
	}
	else
	{
		if (Records[CurrIndex]->Key != Key)
		{	
			int ind = CurrIndex;
			while (fl[CurrIndex] == 1 && CurrIndex+1 != ind)
				CurrIndex = (CurrIndex+1)  % MaxRecords; 
			Records[CurrIndex] = TR; 
			CurrSize++;
			fl[CurrIndex] = 1;
			Reset();
		}
		else 
		{	
			Reset();
			string s = "Key: " + Key + " - isn`t unique";
			throw s;
		}
	}
}

template <typename T>
T* HashTable<T>::Search(const string Key)
{
	Reset();
	T* tmp = nullptr;
	if (IsEmpty())
		throw (string)"can't search in empty table";
	CurrIndex = HashFunc(Key);
	
	if(Records[CurrIndex]->Key == Key)
		tmp = &(Records[CurrIndex]->Data);
	else
	{	
		int ind = CurrIndex;
		while (fl[CurrIndex] == 1 && CurrIndex+1 != ind)
		{
			CurrIndex = (CurrIndex + 1) % MaxRecords;
			if (Records[CurrIndex]->Key == Key)
					{
						tmp = &(Records[CurrIndex]->Data);
						break;
					}
		}
		if (tmp == nullptr)
		{
			Reset();
			string s = Key + " not found";
			throw s;
		}
	}
	return tmp;
}

template <typename T>
void HashTable<T>::Delete(string Key)
{
	Reset();
	if (IsEmpty())
		throw (string)"can't search in empty table";
	Search(Key);

	TabRecord<T> A;
	fl[CurrIndex] = -1;
	Records[CurrIndex] = new TabRecord<T>(A);
	CurrSize--;
	Reset();
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const HashTable<T>& Tab)
{
	int i = 0;
	while (i < Tab.MaxRecords)
	{	
		if (Tab.fl[i] == 1)
		{
			os << i << ". " << Tab.Records[i]->Key << "  |   " << Tab.Records[i]->Data << std::endl;
		}
		i++;
	}
	if (Tab.CurrSize == 0)
		os << "empty table";
	return os;
}
