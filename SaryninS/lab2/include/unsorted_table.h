#pragma once
#include "table.h"

template <typename T>
class UnsortedTable : public Table<T> 
{
	protected:
		void Realloc();
	public:
		UnsortedTable(int i = 10) : Table(i) {};
		UnsortedTable(const UnsortedTable<T>& TabCopy) : Table(TabCopy) {};
		~UnsortedTable() { };
		void Insert(const T Data, const string Key);
		T* Search(const string Key);
		void Delete(const string Key);
		template<class T> friend std::ostream& operator<< (std::ostream& os, const UnsortedTable<T>& Tab);
};

template <typename T>
void UnsortedTable<T>::Realloc()
{
	int NewMaxRecords = (int)(MaxRecords*1.5);
	TabRecord<T>** tmp = new TabRecord<T>*[NewMaxRecords];
	for (int i = 0; i < MaxRecords; i++)
		tmp[i] = Records[i];
	MaxRecords = NewMaxRecords;
	delete[] Records;
	Records = tmp;
}

template <typename T>
void UnsortedTable<T>::Insert(const T Data, const string Key)
{
	if (IsFull())
		Realloc();
	TabRecord<T>* TR = new TabRecord<T>(Key, Data);
	Reset();
	while (!IsEnded() && Key != Records[CurrIndex]->Key)
		CurrIndex++;
	if (IsEmpty())
	{
		CurrIndex++;
	}
	if (CurrIndex == CurrSize)
	{
		Records[CurrIndex] = TR;
		CurrSize++;
		Reset();
	}
	else
	{
		Reset();
		string s = "Key: " + Key + " - isn`t unique";
		throw s;
	}
}

template <typename T>
T* UnsortedTable<T>::Search(const string Key)
{	
	Reset();
	T* tmp = nullptr;
	if (IsEmpty())
		throw (string)"can't search in empty table";
	while (!IsEnded() && Key != Records[CurrIndex]->Key)
		CurrIndex++;
	if (!IsEnded())
		tmp = &(Records[CurrIndex]->Data);
	else
	{	
		string s = Key + " not found";
		throw s;
	}
	return tmp;
}

template <typename T>
void UnsortedTable<T>::Delete(string Key)
{
	Reset();
	if (IsEmpty())
		throw (string)"can't search in empty table";
	Search(Key);
	if (CurrSize > 1)
		Records[CurrIndex] = Records[--CurrSize];
	else
		CurrSize = 0;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const UnsortedTable<T>& Tab)
{	
	int i = 0;
	while(i < Tab.CurrSize)
	{
		os << i << ". " << Tab.Records[i]->Key<< "  |   " << Tab.Records[i]->Data << std::endl;
		i++;
	}
	if (Tab.CurrSize == 0)
		os << "empty table";
	return os;
}