#pragma once
#include "table.h"

template<typename type>
class HashTable :public Table<type>
{
protected:
	int* H;
	int Hash(const string& KEY) const;
	void Realloc() override;
public:
	HashTable(int i = 10) override;
	HashTable(const HashTable& CopyTab) override;
	~Table() { delete[] H; };

	type& Search(const string& KEY) const override;
	void Insert(const string& KEY, const type& DATA) override;
	void Delete(const string& KEY) override;

	void reset() override;
	type& GetCurr() const override;
	void SetNext() override;
};

//-----------------------------------------------------------
template<typename type>
HashTable<type>::HashTable(int i = 10) : Table(i) 
{ 
	H = new int[i]; 
	for (int j = 0; j < MaxRecords; j++)
		H[j] = 0;
};

template<typename type>
int HashTable<type>::Hash(const string& KEY) const
{
	int seed = 171;
	int hash = 0;
	for (int i = 0; i < KEY.length(); i++)
		hash = (hash * seed) + int(KEY[i]);
	return  hash % MaxRecords;
}

template<typename type>
void HashTable<type>::Realloc() 
{
	int NewMax = MaxRecords * ReallocCoeff;
	TabRecord<type>** temp = new TabRecord<type>*[NewMax];
	int* tempH = new int[NewMax];
	int i = 0;
	for (i; i < MaxRecords; i++)
	{
		temp[i] = Records[i];
		tempH[i] = H[i];
	}
	delete[] Records;
	delete[] H;
	Records = temp;
	H = tempH;
	MaxRecords = NewMax;
}

template<typename type>
HashTable<type>::HashTable(const HashTable& CopyTab)
{
	MaxRecords = CopyTab.MaxRecords;
	CurrRecord = CopyTab.CurrRecord;
	CurrIndex = CopyTab.CurrIndex;
	delete[] Records;
	delete[] H;
	Records = new TabRecord<type>*[MaxRecords];
	H = new int[MaxRecords];
	for (int i = 0; i < CurrRecord; i++)
	{
		H[i] = CopyTab.H[i];
		Records[i] = CopyTab.Records[i];
	}
}

template<typename type>
type& HashTable<type>::Search(const string& KEY) const
{
	reset();
	if (CurrRecord)
	{
		CurrIndex = Hash[KEY];
		int l = CurrIndex;
		if (Records[CurrIndex]->key == KEY)
			return Records[CurrIndex]->data;
		else
		{
			while (H[CurrIndex] && ((CurrIndex + 1) != l) && (Records[CurrIndex]->key == KEY))
				CurrIndex = (CurrIndex + 1) % MaxRecords;
			return Records[CurrIndex]->data;	
		}
			throw "Key does not exist";
	}
	else
		throw "Table is empty";
}

template<typename type>
void HashTable<type>::Insert(const string& KEY, const type& DATA)
{
	if (CurrRecord == MaxRecords)
		Realloc();
	reset();
	CurrIndex = Hash(KEY);
	if (!H[CurrIndex])
	{
		Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
		CurrRecords++;
		H[CurrIndex] = 1;
	}
	else 
		if (Records[CurrIndex]->key != KEY)
		{
			int l = CurrIndex;
			while (H[CurrIndex] && ((CurrIndex + 1) != l)
				CurrIndex = (CurrIndex + 1) % MaxRecords;
			Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
			CurrRecords++;
			H[CurrIndex] = 1;
		}
		else
			throw "this key exists"
}

template<typename type>
void HashTable<type>::Delete(const string& KEY)
{
	reset();
	Search(KEY);
	Records[CurrIndex] = new TabRecord<type>;
	H[CurrIndex] = 0;
	CurrRecord--;
}

template<typename type>
void HashTable<type>::reset()
{
	if (CurrRecord)
	{
		CurrIndex = 0;
		while (H[CurrIndex] != 1)
			CurrIndex++;
	}
	else
		CurrIndex = -1;
}

template<typename type>
type& HashTable<type>::GetCurr() const
{
	if (CurrRecord)
		return Records[CurrIndex]->data;
	else
		throw "table is empty";
	
}

template<typename type>
void HashTable<type>::SetNext()
{
	if (CurrRecord)
	{
		CurrIndex++;
		while (flag[CurrIndex] != 1)
			CurrIndex = (CurrIndex + 1) % MaxRecords;
	}
	else
		throw "table is empty";
}