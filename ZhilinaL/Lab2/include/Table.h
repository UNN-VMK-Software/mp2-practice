#pragma once 
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class TabRecord
{
	public:
		string key;
		T*	data;
		TabRecord() { key = "Empty record"; data = new T(NULL); }
		TabRecord(string CKey , T CData ) { key = CKey; data = new T(CData);} 
		TabRecord(const TabRecord& CTabR) { key = CTabR.key; data = new T(*(CTabR.data)); }
		TabRecord<T>& operator=(const TabRecord<T>& TabR) { data = new T(*(TabR.data)); key = TabR.key; return *this; }
};

template <typename T>
class Table
{
	protected:
			TabRecord<T>** rows; 
			unsigned int maxRecord;
			unsigned int currRecord;
			int currIndex;
			virtual void Realloc() = 0;
	public:
			Table(unsigned int i = 10);
			virtual ~Table() { delete[] rows; };
			//виртуальные
			virtual void Insert(const T Data, const string Key) = 0;
			virtual void Delete(const string Key) = 0;
			virtual	 T* Search(const string Key) = 0;
			//методы навигации
			virtual	void Reset();
			virtual bool IsTabEnded() const { return currIndex == currRecord || currIndex == -1; };
			bool IsFull() const { return currRecord == maxRecord; };
			bool IsEmpty() const { return currRecord == 0; };
			virtual void SetNext();
			virtual T* GetCurr() const;
			int GetCurrRecords() const { return currRecord; };
			int GetMaxRecords() const { return maxRecord; };
			
};

template<typename T>
Table<T>::Table(unsigned int i)
{
	maxRecord = i;
	currRecord = 0;
	currIndex = -1;
	rows = new TabRecord<T>*[maxRecord];
}

template<typename T>
void Table<T>::Reset()
{
	if(currRecord > 0)
		currIndex = 0;
	else
		currIndex = -1;
}

template<typename T>
T* Table<T>::GetCurr() const
{
	T* tmp;
	if (currIndex >= 0 && currIndex<currRecord)
	{
		tmp = rows[currIndex]->data;
	}
	else
	{
		throw (string)"Table Is Empty";
	}
	return tmp;
}

template<typename T>
void Table<T>::SetNext()
{
	if (currIndex != -1)
		currIndex++;
	else
		throw (string)"Table Is Empty";
	if (IsTabEnded())
		Reset();
}
