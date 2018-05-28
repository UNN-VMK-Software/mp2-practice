#pragma once
#include "table.h"

template<typename type>
class SortedTable :public Table<type>
{
protected:
	int BinarySearch(const string& KEY) const;
public:
	SortedTable(int i = 10) : Table(i) {};
	SortedTable(const SortedTable& CopyTab) : Table(CopyTab) {};
	~SortedTable() { };

	type& Search(const string& KEY) const override;
	void Insert(const string& KEY, const type& DATA) override;
	void Delete(const string& KEY) override;

	template<class type> friend ostream& operator<< (std::ostream& os, const SortedTable<type>& Tab);
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
		if (KEY > Records[i]->key)
			i = mid;
		else
			j = mid;
	}
	return i;
}

template<typename type>
type& SortedTable<type>::Search(const string& KEY) const
{
	reset();
	if (CurrIndex > -1)
	{
		int k = BinerySearch(KEY);
		if (Records[k]->key == KEY)
			return Records[k];
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
	int k = BinerySearch(KEY);
	if (Records[k]->key != KEY)
	{
		for (int i = CurrRecord; i > k; i--)
			Records[i] = Records[i - 1];
		Records[k] = TabRecord<type>(KEY, DATA);
	}
	else
		throw "Such key already exists";
}

template<typename type>
void SortedTable<type>::Delete(const string& KEY)
{
	reset();
	if (CurrIndex > -1)
	{
		int k = BinarySearch(KEY);
		if (Records[k]->key == KEY)
		{
			for (int i = k; i < CurrRecord - 1; i++)
				Records[i] = Records[i + 1];
		}
		else
			throw "Key does not exist"
	}
	else
		throw "Table is Empty";
}

template <typename type>
ostream& operator<< (ostream& os, const SortedTable<type>& Tab)
{
	if (Tab.CurrRecord)
		for (int i = 0; i < CurrRecod; i++)
			os << i << " | " << Tab.Records[i]->key << " | " << Tab.Records[i]->data << endl;
	else
		os << "Table is empty" << endl;
	return os;
}


