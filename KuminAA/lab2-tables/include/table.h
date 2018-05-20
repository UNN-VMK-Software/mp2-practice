#pragma once
#include <string>

template <typename type>
class TabRecord
{
public:
	string key;
	type data;
	TabRecord() { key = "empty"; data = NULL; }
	TabRecord(string KEY, type DATA) { key = KEY; data = DATA; }
	TabRecord(const TabRecord& T) { key = T.key; data = T.data; }
	TabRecord& operator=(const TabRecord& T) { key = T.key; data = T.data; }
};

template <typename type>
class Table
{
protected:
	TabRecord<type>* Records;
	unsigned int MaxRecords;
	unsigned int CurrRecord;
	int CurrIndex;
	virtual void Realloc() = 0;
public:
	Table(unsigned int n = 10);
	virtual ~Table() { delete[] Records; };
	virtual type* Search() = 0;
	virtual void Insert() = 0;
	virtual void Delete() = 0;
	virtual void reset();
	virtual int isended() { return CurrRecord; }
	virtual type* GetCurr() { return Records[CurrIndex]->data; }
	virtual void SetNext() { CurrIndex++; }

};