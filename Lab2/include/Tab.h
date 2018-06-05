#pragma once
#define MIN_SIZE 10
#include <iostream>
#include <ostream>
template <class KeyField, class DataField>
struct DataTable  
{
	KeyField Key;				 
	DataField Data;			
	DataTable(KeyField Key_k = KeyField(), DataField Data_d = DataField()) { Key = Key_k; Data = Data_d; }  
};

template <class KeyField, class DataField>
class Table 
{
public:
	Table(int SizeTable = MIN_SIZE);
	virtual ~Table();
	virtual void Insert(const KeyField &KEY, const DataField &DATA) = 0;
	virtual void Delete(const KeyField &KEY) = 0;
	virtual DataTable<KeyField, DataField> * Search(const KeyField &KEY) const = 0; 
																					
	void Reset() { current = 0; };
	bool IsFull() const
	{
		if (Top == 0)
			return true;
		if (current == Top - 1) return 1;
		else return 0;
	};
	void GoNext() { if (!IsFull())current++; };
	DataField GetCurData() const { return (*(this->DATATAB[current])).Data; };
	template <class KeyField, class DataField>
	friend std::ostream& operator<<(std::ostream& out, const Table<KeyField, DataField>&P);

protected:
	DataTable <KeyField, DataField> ** DATATAB;  
	int MaxSize; 
	virtual void Realloc() = 0;
	int current;
	int Top;
};


template <class KeyField, class DataField>
Table<KeyField, DataField>::Table(int SizeTable)
{
	MaxSize = SizeTable;
	DATATAB = new DataTable<KeyField, DataField> *[SizeTable];
	for (int i = 0; i < SizeTable; i++)
		DATATAB[i] = NULL;
	Top = 0;
	current = 0;
};


template <class KeyField, class DataField>
Table<KeyField, DataField>::~Table()
{
	for (int i = 0; i < MaxSize; i++)
		delete DATATAB[i];
	delete[] DATATAB;
};


template <class KeyField, class DataField>
std::ostream& operator << (std::ostream& out, const Table<KeyField, DataField>& P)
{
	for (int i = 0; i<P.MaxSize; i++)
	{
		if (P.DATATAB[i] != NULL)
			out << i+1 << "  ||  " << (*(P.DATATAB[i])).Key << " <=====> " << " " << (*(P.DATATAB[i])).Data;
		else  out << i+1 << "  ||  " << " NULL" << endl;
	}
	cout << "=======================================";
	return out;
}
