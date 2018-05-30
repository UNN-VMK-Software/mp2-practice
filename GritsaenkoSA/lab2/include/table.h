#pragma once

#include <iostream>
#include <ostream>



template <class type_k, class type_d>
struct TableRec//класс таблица записей
{
	type_k KEY;			//ключ, имя 
	type_d Data;			//данные
	TableRec(type_k KEY1 = type_k(), type_d Data1 = type_d()); // оператор присваивания
};

template <class type_k, class type_d>
class Table //класс таблица
{
protected:
	TableRec <type_k, type_d> ** Rows; //массив указателей на записи
	int MaxSizeT;	//количество записей 
	int CurSizeT;	//текущий размер таблицы
	int CurIndex;	//индекс текущей записи
	virtual void Realloc() = 0;	//переупаковка
	
public:
	Table(int sizeT = 10);//конструктор
	virtual ~Table() { for (int i = 0; i < MaxSizeT; i++) delete Rows[i]; delete[] Rows;};//деструктор

	virtual void Insert(const type_k & key, const type_d & Row) = 0;// вставка
	virtual void Delete(const type_k & key) = 0; //удаление
	virtual TableRec<type_k, type_d> * Search(const type_k & key)  = 0; //поиск
	//Методы навигации
	virtual  void Reset();	//установка в начало CurIndex = 0;
	virtual  bool IsTabEnded() const;	//проверка на конец 
	virtual  bool IsFull() const;	//проверка на полноту
	
	virtual  void gonext();	//устанавливает следующий CurIndex ++ 
	virtual  type_d GetCur() const;	//получить текущую запись 

	template <class type_k, class type_d>
	friend std::ostream& operator<<(std::ostream& ostr, const Table<type_k, type_d> & temp)
		{
			for (int i = 0; i<temp.MaxSizeT; i++)
			{
				if (temp.Rows[i] != NULL)
					ostr << i <<":  "<< (*(temp.Rows[i])).KEY<< " |  " << (*(temp.Rows[i])).Data << endl;
				else  ostr << i <<":  " <<" NULL" << endl;
			}
			return ostr;
		}


};

template <class type_k, class type_d>// оператор присваивания
TableRec<type_k, type_d>::TableRec(type_k KEY1 = type_k(), type_d Data1 = type_d()) 
{ 
	KEY = KEY1; 
	Data = Data1; 
}

template <class type_k, class type_d>//конструктор
Table<type_k, type_d>::Table(int sizeT)
{
	MaxSizeT = sizeT;
	Rows = new TableRec<type_k, type_d> *[sizeT];//новая запись
	for (int i = 0; i < sizeT; i++)
		Rows[i] = NULL;
	CurIndex = 0; 
	CurSizeT = 0;
	
}

template<class type_k, class type_d>
bool Table<type_k, type_d>::IsFull() const//проверка на полноту
{
	if (CurSizeT == MaxSizeT) //проверка текущего и максимального
		return true;
	else
		return false;
}


template <class type_k, class type_d>//установка в начало 
void Table<type_k, type_d>::Reset() 
{ 
	CurIndex = 0; 
}


template <class type_k, class type_d>//проверка на конец
bool Table<type_k, type_d>::IsTabEnded() const 
{
	if (CurSizeT == 0)
		return true;
	if (CurIndex == CurSizeT-1) 
		return 1; 
	else return 0;
}

template <class type_k, class type_d>//устанавливает следующий CurIndex ++ 
void Table<type_k, type_d>::gonext() 
{ 
	if (!IsTabEnded())
		CurIndex++;   
}

template <class type_k, class type_d>//получить текущую запись 
type_d Table<type_k, type_d>::GetCur() const 
{ 
	return (*(this->Rows[CurIndex])).Data; 
}

