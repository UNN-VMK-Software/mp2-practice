#pragma once
#define MIN_SIZE 40
#include <iostream>
#include <ostream>
template <class KeyType, class DataType>
struct DataTable  //Данные, которые будет хранить таблица
{
	KeyType Key;			//ключ	 
	DataType Data;			//данные, хранящиеся в таблице УКАЗАТЕЛЬ
	DataTable(KeyType Key_k = KeyType(), DataType Data_d = DataType()) { Key = Key_k; Data = Data_d; } //конструктор 
};

template <class KeyType, class DataType>
class Table //абстрактный класс таблиц
{
public:
	Table(int SizeTable = MIN_SIZE);
	virtual ~Table();
	virtual void Insert(const KeyType &KT_T, const DataType &DT_D) =0;
	virtual void Dell(const KeyType &KT_T) = 0;
	virtual DataTable<KeyType, DataType> * Search(const KeyType &KT_T) const = 0; //УКАЗАТЕЛЬ
	//Методы навигации
	void Reset() { curindex = 0; };
	bool IsEnded() const 
	{
		if (Top == 0)
			return true;
		if (curindex == Top-1) return 1; 
		else return 0;
	};
	void GetNext() { if (!IsEnded())curindex++;   };
	DataType GetCurData() const { return (*(this->DT[curindex])).Data; };
	template <class KeyType, class DataType>
	friend std::ostream& operator<<(std::ostream& os, const Table<KeyType, DataType>&P);

protected:
	DataTable <KeyType, DataType> ** DT; //указатель на начало массива указателей да DT 
	int MaxSize; //Размер таблицы
	virtual void Reallocate() = 0;
	int curindex;
	int Top;
};


template <class KeyType, class DataType>
Table<KeyType, DataType>::Table(int SizeTable)
{
	MaxSize = SizeTable;
	DT = new DataTable<KeyType, DataType> *[SizeTable];
	for (int i = 0; i < SizeTable; i++)
		DT[i] = NULL;
	Top = 0;
	curindex = 0;
};


template <class KeyType, class DataType>
Table<KeyType, DataType>::~Table()
{
	for (int i = 0; i < MaxSize; i++)
		delete DT[i];
	delete[] DT;
};


template <class KeyType, class DataType>
std::ostream& operator << (std::ostream& os, const Table<KeyType, DataType>& P)
{
	for (int i = 0; i<P.MaxSize; i++)
	{
		if (P.DT[i] != NULL)
			os << i <<":  "<< (*(P.DT[i])).Key<< " --> "<<" " << (*(P.DT[i])).Data;
		else  os << i <<":  " <<" NULL" << endl;
	}
	return os;
}

