
#pragma once

#include "table.h"


template <class type_k, class type_d>
class OrdTab : public Table<type_k, type_d>//упорядоченная таблица
{
private:
	virtual void Realloc(); //переупаковка
	int Search_bin(const type_k & KEY) const; //бинарный поиск
public:
	OrdTab(int size = 10);//конструктор по умолчанию
	virtual ~OrdTab();//деструктор

	virtual void Insert(const type_k & key, const type_d & Row); //вставка
	virtual void Delete(const type_k & key);					//удаление
	virtual TableRec<type_k, type_d>* Search(const type_k & key) ;	//поиск

};


template <class type_k, class type_d>//конструктор по умолчанию
OrdTab <type_k, type_d>::OrdTab(int size) : Table<type_k, type_d>(size) 
{
}
template <class type_k, class type_d>//деструктор
OrdTab <type_k, type_d>:: ~OrdTab() 
{
}

template <class type_k, class type_d>//бинарный поиск
int OrdTab <type_k, type_d> ::Search_bin(const type_k & KEY) const  
{	
	int left = 0;
	int right = this->CurSizeT - 1;
	int mid = 0;
	
	while (left <= right)
	{
		mid = (left + right) / 2;
		if ((*(this->Rows[mid])).KEY < KEY)
			left = mid + 1;
		else 
			if ((*(this->Rows[mid])).KEY > KEY)
			right = mid - 1;
		else 
			return mid; 
	}
	if (left > right)
		mid = left;
	return mid;

}


template <class type_k, class type_d>
void OrdTab <type_k, type_d>::Realloc()//переупаковка
{
	int MaxSizeT1 = MaxSizeT*2;
	//int MaxSizeT1 = (int)(this->MaxSizeT + 20)*1.65;//новый размер
	TableRec <type_k, type_d> ** temp = new TableRec <type_k, type_d>*[MaxSizeT1];
	for (int i = 0; i < this -> MaxSizeT; i++)
		temp[i] = this->Rows[i];
	for (int i = this->MaxSizeT; i<MaxSizeT1; i++)
		temp[i] = NULL;
	delete[] this -> Rows;
	this -> Rows = temp;
	this -> MaxSizeT = MaxSizeT1;
}


template <class type_k, class type_d>//вставка
void OrdTab <type_k, type_d> ::Insert(const type_k & key, const type_d & Row)
{
	int i;
	int temp = Search_bin(key);
	if ((double)this->CurSizeT / (double)this->MaxSizeT > 0.7) //проверка на полноту
		//if (IsFull())
			Realloc();
	if ((this->Rows[temp] == NULL) || ((*(this->Rows[temp])).KEY != key))
	{
		//if ((double)this->CurSizeT / (double)this->MaxSizeT > 0.7) //проверка на полноту
		//if (IsFull())
		//	Realloc();
		for (i = this->CurSizeT; i > temp; i--)
			this->Rows[i] = this->Rows[i - 1];
		this->Rows[i] = new TableRec<type_k, type_d>(key, Row);
		this->CurSizeT++;
	}
	else 
		//cout << "error the same key" << endl;
		throw "error the same key";
}


template <class type_k, class type_d>//поиск
TableRec<type_k, type_d>* OrdTab <type_k, type_d> ::Search(const type_k & key) 
{
	int temp = Search_bin(key);

	if ((this->Rows[temp] != NULL) &&((*(this->Rows[temp])).KEY == key))
		return this->Rows[temp];
	else
		throw "error ne found";
	
		
	

		/*int area = BinarSearch(KT_T);
	if ((*(this->DT[area])).Key == KT_T)
		//return (*(this->DT[area])).Data;
		return this->DT[area];
	else //throw "element doesn't exist";
	return NULL;*/
}


template <class type_k, class type_d>//удаление
void  OrdTab <type_k, type_d> ::Delete(const type_k & key)
{
	int temp = Search_bin(key);

	if ((this->Rows[temp] != NULL) && ((*(this -> Rows[temp])).KEY == key))
	{
		delete this->Rows[temp];
		for (int i = temp; i < this -> CurSizeT; i++)
			this -> Rows[i] = this -> Rows[i + 1];
		this -> CurSizeT = CurSizeT - 1;
	}
	else
		//cout << "error net key" << endl;
		throw "error net key";
}

