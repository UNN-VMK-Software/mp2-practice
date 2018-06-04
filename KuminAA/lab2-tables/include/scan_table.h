#pragma once
#include "table.h"

template<typename type>
class ScanTable :public Table<type>
{
public:
	ScanTable(int i = 10) : Table(i) {};
	ScanTable(const ScanTable<type>& CopyTab) : Table(CopyTab) {};
	~ScanTable() { };

	type& Search(const string& KEY) const override;
	void Insert(const string& KEY, const type& DATA) override;
	void Delete(const string& KEY) override;
};

//-----------------------------------------------------------
template<typename type>
type& ScanTable<type>::Search(const string& KEY) const
{	
	ScanTable<type> Temp(*this);
	Temp.reset();
	if (Temp.CurrIndex > -1)
	{
		while (Temp.Records[Temp.CurrIndex]->key != KEY) && (Temp.CurrIndex < Temp.CurrRecord))
			Temp.SetNext();
		if (Temp.CurrIndex < Temp.CurrRecord)
			return Temp.Records[Temp.CurrIndex]->data;
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
	if (CurrRecord)
	{
		while ((CurrIndex < CurrRecord) && (Records[CurrIndex]->key != KEY))
			CurrIndex++;
		if (CurrIndex == CurrRecord)
		{
			Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
			CurrRecord++;
		}
		else
			throw "Such key already exists";
	}
	else
	{
		CurrIndex++;
		Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
		CurrRecord++;
	}
}

template<typename type>
void ScanTable<type>::Delete(const string& KEY)
{
	reset();
	if (CurrIndex > -1)
	{
		while ((CurrIndex < CurrRecord) && (Records[CurrIndex]->key != KEY))
			CurrIndex++;
		if (CurrRecord && (CurrIndex < CurrRecord))
		{
			if (CurrRecord > 1)
				Records[CurrIndex] = Records[--CurrRecord];
			else
				CurrRecord = 0;
		}
		else
			throw "Key does not exist";
	}
	else
		throw "Table is empty";
}
