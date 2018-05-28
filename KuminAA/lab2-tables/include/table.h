#pragma once
#include <string>
#include <iostream>
#define ReallocCoeff 2
using namespace std;

template <typename type>
class TabRecord
{
public:
	string key;
	type data;
	TabRecord() { key = "empty"; data = NULL; }
	TabRecord(const string& KEY, const type& DATA) { key = KEY; data = DATA; }
	TabRecord(const TabRecord& T) { key = T.key; data = T.data; }
	TabRecord& operator=(const TabRecord& T) { key = T.key; data = T.data; }
};

template <typename type>
class Table
{
protected:
	TabRecord<type>** Records;
	int MaxRecords;
	int CurrRecord;
	int CurrIndex;
	virtual void Realloc();
public:
	Table(int i = 10);
	Table(Table& CopyTab);
	virtual ~Table() { delete[] Records; };

	virtual type& Search(const string& KEY) const = 0;
	virtual void Insert(const string& KEY, const type& DATA) = 0;
	virtual void Delete(const string& KEY) = 0;

	virtual void reset();
	virtual int isended() const { return CurrIndex == -1 || CurrIndex == CurrRecord; } 
	virtual type& GetCurr() const;
	virtual void SetNext();

};

//-----------------------------------------------------------
template<typename type>
void Table<type>::Realloc()
{
	int NewMax = MaxRecords * ReallocCoeff;
	TabRecord<type>** temp = new TabRecord<type>*[NewMax];
	reset();
	while (!isended())
	{
		temp[CurrIndex] = Records[CurrIndex];
		SetNext();
	}
	delete[] Records;
	Records = temp;
	MaxRecords = NewMax;
};

template <typename type>
Table<type>::Table(int i = 10)
{
	MaxRecords = i;
	CurrIndex = -1;
	CurrRecord = 0;
	Records = new TabRecord<type>*[MaxRecords];
}

template<typename type>
Table<type>::Table(Table& CopyTab)
{
	MaxRecords = CopyTab.MaxRecords;
	CurrRecord = CopyTab.CurrRecord;
	CurrIndex = CopyTab.CurrIndex;
	delete[] Records;
	Records = new TabRecord<type>*[MaxRecords];
	for (int i = 0; i < CurrRecord; i++)
		Records[i] = CopyTab.Records[i];
}

template<typename type>
void Table<type>::reset()
{
	if (CurrRecord)
		CurrIndex = 0;
	else
		CurrIndex = -1;
}

template<typename type>
type& Table<type>::GetCurr() const
{
	if (CurrIndex > -1)
		return Records[CurrIndex]->data;
	else
		throw "table is empty";
}

template<typename type>
void Table<type>::SetNext()
{
	if (CurrIndex > -1)
		CurrIndex++;
	else
		throw "tab is empty";
	if (isended())
		reset();
}