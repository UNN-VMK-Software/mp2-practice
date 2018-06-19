#pragma once
#include <iostream> 
#include <algorithm>

#define maxSize 1000
typedef int dataType;

class Data {
public:
	float priorities;
};
//============================================================||============================================================
class DHeap {
protected:
	Data** keys;	// Ключи (Приоритеты)
	int d;			// Д-арность кучи
	int lastIdx;	// Текущий размер кучи
public:
	/* Конструкторы */
	DHeap(int d);
	DHeap(const DHeap &heap);
	~DHeap();

	int isFull()const;
	int isEmpty()const;

	void add(Data *&key);				// Вставка элемента в кучу
	void addSet(Data **key, int num);	// Вставка группы элементов в кучу

	Data* erase();						// Стирание последнего элемента
	Data* erase(int i);					// ... i-го элемента

	void transposition(int i, int j);	// Обмен переданных значений 
	void surfacing(int i);				// Всплытие
	void immersion(int i);				// Погружение

	void hilling();						// Окучивание

private:
	int minChild(int i);				// Поиск минимального потомка
};

