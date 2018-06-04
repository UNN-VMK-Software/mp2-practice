#include "table.h"

template <typename T>
class SortedTable : public Table<T>
{
protected:
	void Realloc();
public:
	SortedTable(int i = 10) : Table(i) {};
	SortedTable(const SortedTable<T>& TabCopy) : Table(TabCopy) {};
	~SortedTable() {};
	void Insert(const T Data, const string Key);
	T* Search(const string Key);
	void Delete(const string Key);
	template<class T> friend std::ostream& operator<< (std::ostream& os, const SortedTable<T>& Tab);
};

template <typename T>
void SortedTable<T>::Realloc()
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
void SortedTable<T>::Insert(const T Data, const string Key)
{
	if (IsFull())
		Realloc();
	TabRecord<T>* TR = new TabRecord<T>(Key, Data);
	Reset();
	while (!IsEnded() && TR->Key >= Records[CurrIndex]->Key)
	{
		if (Records[CurrIndex]->Key == TR->Key) 
		{
			string s = "Key: " + Key + " - isn`t unique";
			throw s;
		}
		CurrIndex++;
	}
	if (IsEmpty())
		CurrIndex++;
	CurrSize++;
	for (int i = CurrSize-1; i > CurrIndex; i--)
	{
		Records[i] = Records[i - 1];
	}
	Records[CurrIndex] = TR; 
	Reset();
}

template <typename T>
T* SortedTable<T>::Search(const string Key)
{
	Reset();
	T* tmp = nullptr;

	if (!IsEmpty())
	{	
		int i = -1, j = CurrSize;
		int mid;
		while (i < j -1 ) 
		{	
			mid = (j + i) / 2;
			if (Key >= Records[mid]->Key)
			{
				i = mid;
			}
			else
			{
				j = mid;
			}
		}
		if (Key == Records[i]->Key)
		{
			CurrIndex = i;
			tmp = &(Records[CurrIndex]->Data);
		}
		else
		{
			string s = Key + " not found";
			throw s;
		}
	}
	else
		throw (string)"emty table";
	return tmp;
}

template <typename T>
void SortedTable<T>::Delete(const string Key)
{
	Reset();
	if (IsEmpty())
		throw (string)"can't search in empty table";
	Search(Key);
	if (CurrSize > 1)
	{	
		CurrSize--;
		for (int i = CurrIndex; i < CurrSize; i++)
		{
			Records[i] = Records[i + 1];
		}
		Reset();
	}
	else
		CurrSize = 0;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const SortedTable<T>& Tab)
{
	int i = 0;
	while (i < Tab.CurrSize)
	{
		os << i << ". " << Tab.Records[i]->Key << "  |   " << Tab.Records[i]->Data << std::endl;
		i++;
	}
	if (Tab.CurrSize == 0)
		os << "empty table";
	return os;
}
