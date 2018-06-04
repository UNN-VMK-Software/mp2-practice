#pragma once
#define MIN_SIZE 40
#include <iostream>
#include <ostream>
template <class KeyType, class DataType>
struct DataTable  //Данные, которые будет хранить таблица
{
	KeyType Key;			//ключ	 
	DataType Data;			//данные, хранящиеся в таблице
	DataTable(KeyType Key_k = KeyType(), DataType Data_d = DataType()) { Key = Key_k; Data = Data_d; };//конструктор копирования

};

template <class KeyType, class DataType>
class Table //абстрактный класс таблиц
{
protected:
	int Top;
	int curindex;
	DataTable <KeyType, DataType> **DT; //указатель на начало массива из указателей на ключ-значение
	int MaxSize; //Размер таблицы
	virtual void Reallocate() = 0;
public:
	Table(int SizeTable = MIN_SIZE);
	virtual ~Table();
	virtual void Insert(const KeyType &KT_T, const DataType &DT_D) =0;
	virtual void Dell(const KeyType &KT_T) = 0;
	virtual DataTable<KeyType,DataType> *  Search(const KeyType &KT_T) const = 0;
	//методы навигации
	void Reset() { curindex = 0; };
	bool IsEnded() { 
		if (Top == 0) return 1;
		if (curindex == Top - 1) return 1; else return 0; 
	};
	void GetNext() { if (!IsEnded())curindex++;};
	DataType GetCurData() const  { return (*(this->DT[curindex])).Data;};

	//методы навигации
	// вывод 
	template <class KeyType, class DataType>  friend std::ostream& operator<<(std::ostream& os, const Table<KeyType, DataType>& p);
};


template <class KeyType, class DataType>
std::ostream& operator<<(std::ostream& os, const  Table<KeyType, DataType>& p) {
	int i = 0;
	for (i = 0; i < p.MaxSize; i++) {
		if (p.DT[i] != NULL) os << i<< "| "<< (*(p.DT[i])).Key << "---> "<<(*(p.DT[i])).Data;
		else { os << i << " NULL" << endl;}
	}
	return os;
}




template <class KeyType, class DataType>
Table<KeyType, DataType>::Table(int SizeTable)
{
	Top = 0;
	curindex = 0;
	MaxSize = SizeTable;
	DT = new DataTable<KeyType, DataType> * [SizeTable];
	for (int i = 0; i < SizeTable; i++) DT[i] = NULL;
	};


template <class KeyType, class DataType>
Table<KeyType, DataType>::~Table()
{
	for (int i = 0; i < MaxSize; i++) delete DT[i];
	delete[] DT;
};
