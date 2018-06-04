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
	HashTable(int i = 10);
	HashTable(const HashTable& CopyTab);
	~HashTable() { delete[] H; };

	type& Search(const string& KEY) const override;
	void Insert(const string& KEY, const type& DATA) override;
	void Delete(const string& KEY) override;

	void reset() override;
	type& GetCurr() const override;
	void SetNext() override;

	template<class type> friend ostream& operator<< (std::ostream& os, const HashTable<type>& Tab);
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
	int hash = 0;
	for (int i = 0; i < KEY.length(); i++)
		hash = hash + int(KEY[i]);
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
	for (int i = 0; i < MaxRecords; i++)
	{
		H[i] = CopyTab.H[i];
		Records[i] = CopyTab.Records[i];
	}
}

template<typename type>
type& HashTable<type>::Search(const string& KEY) const
{
	HashTable<type> Temp(*this);
	Temp.reset();
	if (Temp.CurrRecord)
	{
		Temp.CurrIndex = Temp.Hash(KEY);
		int l = Temp.CurrIndex;
		if (Temp.Records[Temp.CurrIndex]->key == KEY)
			return Temp.Records[Temp.CurrIndex]->data;
		else
		{
			while (Temp.H[Temp.CurrIndex] && ((Temp.CurrIndex + 1) != l) && (Temp.Records[Temp.CurrIndex]->key != KEY))
				Temp.CurrIndex = (Temp.CurrIndex + 1) % Temp.MaxRecords;
			if(Temp.Records[Temp.CurrIndex]->key == KEY)
				return Temp.Records[Temp.CurrIndex]->data;
			else 
				throw "Key does not exist";
		}
	}
	else
		throw "Table is empty";
}

template<typename type>
void HashTable<type>::Insert(const string& KEY, const type& DATA)
{
	if (CurrRecord == MaxRecords)
		Realloc();
	CurrIndex = Hash(KEY);
	if (!H[CurrIndex])
	{
		Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
		CurrRecord++;
		H[CurrIndex] = 1;
	}
	else
		if (Records[CurrIndex]->key != KEY)
		{
			int l = CurrIndex;
			while (H[CurrIndex] && ((CurrIndex + 1) != l))
				CurrIndex = (CurrIndex + 1) % MaxRecords;
			Records[CurrIndex] = new TabRecord<type>(KEY, DATA);
			CurrRecord++;
			H[CurrIndex] = 1;
		}
		else
			throw "this key exists";
}

template<typename type>
void HashTable<type>::Delete(const string& KEY)
{
	reset();
	if (CurrRecord)
	{
		CurrIndex = Hash(KEY);
		int l = CurrIndex;
		if (H[CurrIndex])
		{
			if (Records[CurrIndex]->key != KEY)
			{
				while (H[CurrIndex] && ((CurrIndex + 1) != l) && (Records[CurrIndex]->key != KEY))
					CurrIndex = (CurrIndex + 1) % MaxRecords;
				if (!H[CurrIndex] || Records[CurrIndex]->key != KEY)
					throw "Key does not exist";
				else
				{
					Records[CurrIndex] = new TabRecord<type>;
					H[CurrIndex] = 0;
					CurrRecord--;
				}
			}
			else
			{
				Records[CurrIndex] = new TabRecord<type>;
				H[CurrIndex] = 0;
				CurrRecord--;
			}
		}
		else
			throw "Key does not exist";
	}
	else
		throw "Table is empty";
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
		while (H[CurrIndex] != 1)
			CurrIndex = (CurrIndex + 1) % MaxRecords;
	}
	else
		throw "table is empty";
}

template <typename type>
ostream& operator<< (ostream& os, const HashTable<type>& Tab)
{
	if (Tab.CurrRecord)
	{
		for (int i = 0; i < Tab.MaxRecords; i++)
			if (Tab.H[i])
				os << i << " | " << Tab.Records[i]->key << " | " << Tab.Records[i]->data << endl;
	}
	else
		os << "Table is empty" << endl;
	return os;
}