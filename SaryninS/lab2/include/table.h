#pragma once 
#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

template <typename T>
class TabRecord
{
	public:
		string Key;
		T	Data; 
		TabRecord() { Key = "EMPTY"; Data = 0;}
		TabRecord(string K , T D ) { Key = K; Data = D;} 
		TabRecord(const TabRecord& TR) { Key = TR.Key; Data = TR.Data; }
		TabRecord<T>& operator=(const TabRecord<T>& TabR) { Data = TabR.Data; Key = TabR.Key; return *this; }
};

template <typename T>
class Table
{
	protected:
			TabRecord<T>** Records; 
			int MaxRecords;
			int CurrSize;
			int CurrIndex;
			virtual void Realloc() = 0;
	public:
			Table(int i = 10);
			Table(const Table<T>& TabCopy);
			virtual ~Table() {};
			virtual void Insert(const T Data, const string Key) = 0;
			virtual void Delete(const string key) = 0;
			virtual	 T* Search(const string Key) = 0;
			virtual	void Reset();
			virtual bool IsEnded() const { return CurrIndex == CurrSize || CurrIndex == -1; };
			bool IsFull() const { return CurrSize == MaxRecords; };
			bool IsEmpty() const { return CurrSize == 0; };
			virtual void SetNext();
			virtual T* GetCurr() const;
};

template<typename T>
Table<T>::Table(int i)
{
	MaxRecords = i;
	CurrSize = 0;
	CurrIndex = -1;
	Records = new TabRecord<T>*[MaxRecords];
}

template<typename T>
void Table<T>::Reset()
{
	if(CurrSize > 0)
		CurrIndex = 0;
	else
		CurrIndex = -1;
}

template<typename T>
T* Table<T>::GetCurr() const
{
	T* tmp;
	if (CurrIndex >= 0 && CurrIndex<CurrSize)
	{
		tmp = &(Records[CurrIndex]->Data);
	}
	else
	{
		throw (string)"empty table";
	}
	return tmp;
}



template<typename T>
void Table<T>::SetNext()
{
	if (CurrIndex != -1)
		CurrIndex++;
	else
		throw (string)"empty table";
	if (IsEnded())
		Reset();
}

template <typename T>
Table<T>::Table(const Table<T>& TabCopy)
{
	MaxRecords = TabCopy.MaxRecords;
	CurrIndex = TabCopy.CurrIndex;
	CurrSize = TabCopy.CurrSize;
	delete[] Records;
	Records = new TabRecord<T>*[MaxRecords];
	if (!IsEmpty())
		for (int i = 0; i < CurrSize; i++)
			Records[i] = new TabRecord<T>(*(TabCopy.Records[i]));
}