#pragma once
#include "table.h"

template<typename type>
class ScanTable :public Table<type>
{
public:
	ScanTable(int i = 10) : Table(i) {};
	ScanTable(const SortedTable& CopyTab) : Table(CopyTab) {};
	~ScanTable() { };

	type& Search(const string& KEY) const override;
	void Insert(const string& KEY, const type& DATA) override;
	void Delete(const string& KEY) override;

	template<class type> friend ostream& operator<< (std::ostream& os, const ScanTable<type>& Tab);
};

//-----------------------------------------------------------
template<typename type>
type& ScanTable<type>::Search(const string& KEY) const
{
	reset();
	if (CurrIndex > -1)
	{
		while (((CurrIndex > -1) && (Records[CurrIndex]->key != KEY) && (CurrIndex < CurrRecord))
			SetNext();
		if (CurrIndex < CurrRecord)
			return Records[CurrIndex];
		else
			throw "key does not exist";
	}
	else
		throw "Table is empty";
}

template<typename type>
void ScanTable<type>::Insert(const string& KEY, const type& DATA)
{
	if (CurrRecord == MaxRecords)
		Realloc();
	reset();
	while (((CurrIndex > -1) && (Records[CurrIndex]->key != KEY) && (CurrIndex < CurrRecord))
		CurrIndex++;
	if (CurrIndex == CurrSize)
	{
		Records[CurrIndex] == TabRecord<type>(KEY, DATA);
		CurrSize++;
	}
	else
		throw "Such key already exists";
}

template<typename type>
void ScanTable<type>::Delete(const string& KEY)
{
	reset();
	while (((CurrIndex > -1) && (Records[CurrIndex]->key != KEY) && (CurrIndex < CurrRecord))
		CurrIndex++;
	if (CurrIndex < CurrSize)
	{
		if (CurrSize > 1)
			Records[CurrIndex] = Records[--CurrSize];
		else
			CurrSize = 0;
	}
	else
		throw "Key does not exist"
}

template <typename type>
ostream& operator<< (ostream& os, const ScanTable<type>& Tab)
{
	if (Tab.CurrRecord)
		for (int i = 0; i < CurrRecod; i++)
			os << i << " | " << Tab.Records[i]->key << " | " << Tab.Records[i]->data << endl;
	else
		os << "Table is empty" << endl;
	return os;
}