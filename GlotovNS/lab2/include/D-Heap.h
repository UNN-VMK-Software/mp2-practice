#pragma once

#include <iostream> 
#include <algorithm>

#define maxSize 1000
typedef int dataType;

class Data
{
public:
	float priorities;
};

class DHeap
{
protected:
	Data** keys;	// Ключи (Приоритеты)
	int d;			// Д-арность кучи
	int lastIdx;	// Текущий размер кучи
public:
	/* Конструкторы */
	DHeap(int d);
	DHeap(const DHeap &heap);
	~DHeap();
	int IsFull();
	int IsEmpty();
	void Add(Data *&key);				// Вставка элемента в кучу
	void AddSet(Data **key, int num);	// Вставка группы элементов в кучу
	Data* Erase();						// Стирание последнего элемента
	Data* Erase(int i);					// ... i-го элемента
	void Transposition(int i, int j);	// Обмен переданных значений 
	void Surfacing(int i);				// Всплытие
	void Immersion(int i);				// Погружение
	void Hilling();						// Окучивание
private:
	int MinChild(int i);				// Поиск минимального потомка
};


