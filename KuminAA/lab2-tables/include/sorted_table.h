#pragma once
#include "table.h"

template<typename type>
class SortedTable : public Table<type>
{
protected:
	int BinarySearch(const string& KEY) const;
public:
	SortedTable(int i = 10) : Table(i) {};
	SortedTable(const SortedTable<type>& CopyTab) : Table(CopyTab) {};
	~SortedTable() { };

	type& Search(const string& KEY) const override;
	void Insert(const string& KEY, const type& DATA) override;
	void Delete(const string& KEY) override;
};

//-----------------------------------------------------------

template<typename type>
int SortedTable<type>::BinarySearch(const string& KEY) const
{
	int i = 0, j = CurrRecord - 1;
	int mid;
	while (i <= j)
	{
		mid = (i + j) / 2;
		if (KEY > Records[mid]->key)
			i = mid + 1;
		else
			j = mid - 1;
	}
	return i;
}

template<typename type>
type& SortedTable<type>::Search(const string& KEY) const
{
	SortedTable<type> Temp(*this);
	Temp.reset();
	if (CurrIndex > -1)
	{
		int k = Temp.BinarySearch(KEY);
		if (Temp.Records[k]->key == KEY)
			return Temp.Records[k]->data;
		else
			throw "Key does not exist";
	}
	else
		throw "Table is empty";
}

template<typename type>
void SortedTable<type>::Insert(const string& KEY, const type& DATA)
{
	if (CurrRecord == MaxRecords)
		Realloc();
	reset();
	
	if (CurrRecord)
	{
		int k = BinarySearch(KEY);
		if (k != CurrRecord)
		{
			if (Records[k]->key != KEY)
			{
				for (int i = CurrRecord; i > k; i--)
					Records[i] = Records[i - 1];
				Records[k] = new TabRecord<type>(KEY, DATA);
				CurrRecord++;
			}
			else
				throw "Such key already exists";
		}
		else
		{
			Records[k] = new TabRecord<type>(KEY, DATA);
			CurrRecord++;
		}
	}
	else
	{
		CurrIndex++;
		Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
		CurrRecord++;
	}
}

template<typename type>
void SortedTable<type>::Delete(const string& KEY)
{
	reset();
	if (CurrRecord)
	{
		int k = BinarySearch(KEY);
		if (Records[k]->key == KEY)
		{
				for (int i = k; i < CurrRecord - 1; i++)
					Records[i] = Records[i + 1];
				CurrRecord--;
		}
		else
			throw "Key does not exist";
	}
	else
		throw "Table is Empty";
}


