#pragma once

#include "table.h" 
#include <string>
#include <cstdlib> 

using namespace std;

#define free 0 //свободная
#define busy 1 //занятая
#define delet -1 //удаленная


template <class type_k, class type_d>//hash таблица
class HashTable : public Table <type_k, type_d>
{
private:
	int *flag; //Массив flag, определитель занятости
	void Realloc(); //переупаковка
	int Hashf(const type_k & k) const;//хэш функция
	//int freepos;
	int GetNextPos(int pos){return (pos + 5)% MaxSizeT;}
	
public:
	int freepos;
	HashTable(int size = 20); //конструктор
	~HashTable();//деструктор

	void Insert(const type_k & key, const type_d & Row);			//вставка
	void Delete(const type_k &key);									//удаление
	TableRec<type_k, type_d>* Search(const type_k & key) ;		//поиск

	virtual void Reset();	//установка в начало CurIndex = 0;
	virtual bool IsTabEnded() const;	//проверка на конец 
	
	virtual void gonext();	//устанавливает следующий CurIndex ++ 
	virtual type_d GetCur() const;	//получить текущую запись 

};
template<class type_k>
int NewKey(const type_k & k) 
{
	return 0; 
}

template<>
int NewKey<string>(const string & k)  // для хэш функции
{
	int a = 31; //?
	int b = 0;
	for (int i = 0; i < k.length(); i++)
		b = a * b + k[i];
	return b;
}

template <class type_k, class type_d>//конструктор
HashTable<type_k, type_d>::HashTable(int size) : Table<type_k, type_d>(size)
{
	flag = new int[size];
	for (int i = 0; i < size; i++)
		flag[i] = free;
}
template <class type_k, class type_d>//деструктор
HashTable<type_k, type_d>::~HashTable() 
{
}

template <class type_k, class type_d>  // хэш функция
int HashTable<type_k, type_d>::Hashf(const type_k & k) const
{
	int temp = abs(NewKey(k));
	return (temp % (this -> MaxSizeT));
}

template <class type_k, class type_d>//переупаковка
void HashTable<type_k, type_d>::Realloc()
{
	int i = 0;
	int MaxSizeT1 = MaxSizeT*2;
	//int MaxSizeT1 = (int)(this->MaxSizeT + 20)*1.65;
	TableRec<type_k, type_d> ** temp = new TableRec<type_k, type_d> *[MaxSizeT1];
	int * flag1 = new int[MaxSizeT1];
	for (int i = 0; i < this->MaxSizeT; i++)
		flag1[i] = flag[i];
	for (int i = this->MaxSizeT; i < MaxSizeT1; i++)
		flag1[i] = free;
	delete [] flag;
	flag = flag1;
	//
	for (int i = 0; i<this->MaxSizeT; i++)
		temp[i] = this->Rows[i];
	for (int i = this->MaxSizeT; i < MaxSizeT1; i++)
		temp[i] = NULL;
	
	delete[] this->Rows;
	this->Rows = temp;
	this->MaxSizeT = MaxSizeT1;
}

template <class type_k, class type_d>//поиск
TableRec<type_k, type_d>* HashTable<type_k, type_d>::Search(const type_k & key) 
{
	TableRec<string, polynom>* tmp = nullptr;
	int temp = Hashf(key);
	freepos = -1;
	int i;
	for ( i = 0; i<MaxSizeT; i++)
	{
		if ((this->Rows[i] == NULL) && (flag[temp] == 0))//если свободна
		{
			freepos = temp;
			return tmp;//?
		}
		else
			if ((this->Rows[temp] != NULL) && ((*(this->Rows[temp])).KEY) == key)
			{
				return this->Rows[temp];//Нашли ??? не идет в удаление
			}
		else 
			if (flag[temp] == -1)//если удалена
			{
				if (freepos == -1) 
					freepos = temp;//запоминаем первую свободную ячейку
			}
			temp = GetNextPos(temp);
	}
			throw "error: ne found";
}	
			
		

	//исходная реализация работает
	/*int temp = Hashf(key);//индекс занятости
	if (flag[temp] == 0) //если свободен
	{
		throw "error: ne found";
	}
	if ((this->Rows[temp] != NULL) && ((*(this->Rows[temp])).KEY) == key)//если ключи совпали
	{
		return this->Rows[temp];//Нашли
	}
	else
	{
		srand(temp);
		while ((flag[temp] == -1) || ((flag[temp] == 1) && ((*(this->Rows[temp])).KEY != key))) //пока удален или занят и ключи не совпадают
			temp = rand() % (this->MaxSizeT);//новый индекс
		if (flag[temp] == 1) // если занят
		{
			return this->Rows[temp];//нашли
		}
		else
			//cout << "error ne found" << endl;
			throw "error: ne found";
	}*/
	
	
/*srand(temp);//srand выполняет инициализацию генератора случайных чисел rand
		int temp1 = rand() % (this->MaxSizeT);//новый индекс
			while (flag[temp1] == busy) //пока занят
		{
			temp1 = rand() % (this->MaxSizeT);
			if ((this->Rows[temp1] != NULL) && ((*(this->Rows[temp1])).KEY == key))//если занят
			{
				throw "error: the same key";
			}
		}
		if (flag[temp1] == 0)//если свободен
			this->CurIndex++;
		flag[temp1] = busy;
		temp = temp1;*/
		//srand(temp);
		//temp = rand() % (this->MaxSizeT);//заново считаем индекс


template <class type_k, class type_d>//удаление
void HashTable<type_k, type_d>::Delete(const type_k & key)
{
	int temp = Hashf(key);//индекс занятости
	TableRec<string, polynom>* tmp = Search(key);//запись с искомым кючом
	if (tmp == (this->Rows[temp]))//нашли ключ
		{
		delete this->Rows[temp];
		this->Rows[temp] = NULL;
		flag[temp] = delet;
		//freepos = 
	}
	else 
			{
				throw "error: ne found";
			}

	

	//исходная реализация работает
	/*int temp = Hashf(key);
	if (flag[temp] == 0) //если свободен
	{
		throw "error: ne found";
	}
	if ((this->Rows[temp] != NULL) && ((*(this->Rows[temp])).KEY == key))//если нашли
	{
		delete this->Rows[temp];
		this->Rows[temp] = NULL;
		flag[temp] = delet;//обозначенме что он удален
	}
	else
	{
		srand(temp);
		while ((flag[temp] == -1) || ((flag[temp] == 1) && ((*(this->Rows[temp])).KEY != key))) //пока удален или занят и ключи не совпадают
			temp = rand() % (this->MaxSizeT);
		if (flag[temp] == 1) // если занят
		{
			delete this->Rows[temp];
			this->Rows[temp] = NULL;
			flag[temp] = delet;
		}
		else 
			{
				throw "error: ne found";
			}
	}*/

	//моя реализация неработает
	/*int temp = Hashf(key);//индекс занятости
	if ((this->Rows[temp]) == Search(key))//нашли ключ
	{
		delete this->Rows[temp];
		this->Rows[temp] = NULL;
		flag[temp] = delet;
	}
	else 
			{
				
				throw "error: ne found";
			}*/
}

template <class type_k, class type_d>//вставка
void HashTable<type_k, type_d>::Insert(const type_k & key, const type_d & Row)
{
	if ((double)this->CurIndex / (double)this->MaxSizeT > 0.7) 
		Realloc();
	int temp = Hashf(key);//индекс

	TableRec<string, polynom>* tmp = Search(key);
	//TableRec<string, polynom>* freepos = this -> Search(key);
	if(freepos < 0)
	{
		this->Rows[temp] = new TableRec<type_k, type_d>(key, Row); //вставка
		flag[temp] = busy; //обозначение что он занят
	}
	else
		if (freepos > -1)// найдена свободная или удаленная ячейка
	{
		this->Rows[freepos] = new TableRec<type_k, type_d>(key, Row); //вставка
		flag[freepos] = busy; //обозначение что он занят
	}
	
	


	
	/*int temp = Hashf(key);//индекс
	if ((double)this->CurIndex / (double)this->MaxSizeT > 0.7) 
		Realloc();
	//if (Search(key) == (this->Rows[temp]))//нашли ключ и он равен записи искомого индекса

		if (flag[temp] == free) //если свободный
	{
		this->Rows[temp] = new TableRec<type_k, type_d>(key, Row); //создание нового
		flag[temp] = busy; //обозначение что он занят
		this->CurIndex++;
	}
		else 
		if (flag[temp] == delet)//если удален
	{
		this->Rows[temp] = new TableRec<type_k, type_d>(key, Row); //вставка
		flag[temp] = busy; //обозначение что он занят
	}
	*/

	//исходная реализация работает
	/*if ((double)this->CurIndex / (double)this->MaxSizeT > 0.7) 
	//if (IsFull())
		Realloc();
	int temp = Hashf(key);//индекс
	
	
	if (flag[temp] == free) //если свободный
	{
		this->Rows[temp] = new TableRec<type_k, type_d>(key, Row); //создание нового
		flag[temp] = busy; //обозначение что он занят
		this->CurIndex++;
	}
	else 
		if (flag[temp] == delet)//если удален
	{
		this->Rows[temp] = new TableRec<type_k, type_d>(key, Row); //вставка
		flag[temp] = busy; //обозначение что он занят
	}
	else//если занят
	{
		if ((*(this->Rows[temp])).KEY == key)
		{
			throw "error: the same key";
		}
		srand(temp);//srand выполняет инициализацию генератора случайных чисел rand
		int temp1 = rand() % (this->MaxSizeT);//новый индекс
		while (flag[temp1] == busy) //пока занят
		{
			temp1 = rand() % (this->MaxSizeT);
			if ((this->Rows[temp1] != NULL) && ((*(this->Rows[temp1])).KEY == key))//если занят
			{
				throw "error: the same key";
			}
		}
		this->Rows[temp1] = new TableRec<type_k, type_d>(key, Row);
		if (flag[temp1] == 0)//если свободен
			this->CurIndex++;
		flag[temp1] = busy;
	}*/
}

template <class type_k, class type_d>
void HashTable<type_k, type_d>::Reset()//+
{
	if (CurSizeT == 0)
		CurIndex = 0;
	else 
	{
		CurIndex = 0;
		while (flag[CurIndex] != 1);
		CurIndex ++;
	}
}

template <class type_k, class type_d>
bool HashTable<type_k, type_d>::IsTabEnded() const//+
{
	
	int t = CurIndex;
	while (t < MaxSizeT && flag[t] != 1)
		t++;
	return t == MaxSizeT;
}



template <class type_k, class type_d>
void HashTable<type_k, type_d>::gonext()//+
{
	do 
	{
		CurIndex++;
	}
	while (CurIndex < MaxSizeT && flag[CurIndex] != 1);
		
	if (CurIndex == MaxSizeT)
			Reset();
}

template <class type_k, class type_d>
type_d HashTable<type_k, type_d>::GetCur() const//+
{
	if (flag[CurIndex] == 1)
		return (*(this->Rows[CurIndex])).Data;
	else 
		//cout << "error ne found" << endl;
		throw "error: ne found";
}

