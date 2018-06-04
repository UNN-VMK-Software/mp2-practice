#pragma once
#include <iostream>
#include <ostream>
template <class typeK, class typeD>
struct dataTable  //Данные, которые будет хранить таблица
{
	typeK key;			//ключ	 
	typeD data;			//данные, хранящиеся в таблице-указателе
	dataTable(typeK key_k = typeK(), typeD data_d = typeD()) //конструктор 
	{
		key = key_k; data = data_d;
	}  
};

template <class typeK, class typeD>
class Table //абстрактный класс таблиц
{
public:
	Table(int SizeTable = 30);
	virtual ~Table();
	virtual void insert(const typeK &k, const typeD &d) = 0; //вставка
	virtual void delet(const typeK &k) = 0; //удаление
	virtual dataTable<typeK, typeD> * search(const typeK &k) const = 0; //поиск
																				 
	void reset() // обнуление текущего
	{
		curind = 0;
	}; 
	bool isended() const // проверка на конец
	{
		if (top == 0) // самый верхний элемент в таблице
			return true;
		if (curind == top - 1) return 1;
		else return 0;
	};
	void getnext() 
	{ 
		if (!isended())curind++; 
	};
	typeD getcurdata() const // получить данные текущего элемента
	{ 
		return (*(this->dt[curind])).data;
	};
	template <class typeK, class typeD>
	friend std::ostream& operator<<(std::ostream& os, const Table<typeK, typeD>&P);

protected:
	dataTable <typeK, typeD> ** dt; //массив указателей на записи
	int maxsize; //Размер таблицы
	virtual void realocate() = 0;//перераспределение памяти
	int curind; // текущий элемент
	int top; // вырхний элемент
};


template <class typeK, class typeD>
Table<typeK, typeD>::Table(int SizeTable)
{
	maxsize = SizeTable;
	dt = new dataTable<typeK, typeD> *[SizeTable];
	for (int i = 0; i < SizeTable; i++)
		dt[i] = NULL;
	top = 0;
	curind = 0;
};


template <class typeK, class typeD>
Table<typeK, typeD>::~Table()
{
	for (int i = 0; i < maxsize; i++)
		delete dt[i];
	delete[] dt;
};


template <class typeK, class typeD>
std::ostream& operator << (std::ostream& os, const Table<typeK, typeD>& P)
{
	for (int i = 0; i<P.maxsize; i++)
	{
		if (P.dt[i] != NULL)
			os << i << ":  " << (*(P.dt[i])).key << " --> " << " " << (*(P.dt[i])).data<<endl;
		else  os << i << ":  " << " NULL" << endl;
	}
	return os;
}

