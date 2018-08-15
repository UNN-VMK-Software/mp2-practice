#pragma once
#include <iostream> 
#include <algorithm>

#define maxSize 1000
typedef int dataType;

class Data {
public:
	float priorities;
};

class DHeap {
protected:
	Data** keys;	// Ключи (Приоритеты)
	int d;			// Д-арность кучи
	int lastIdx;	// Текущий размер кучи
public:
	
	DHeap(int d);                  //Конструкторы
	DHeap(const DHeap &heap);
	~DHeap();

	int isFull(); //Проверка на полноту
	int isEmpty();//Проверка на пустоту

	void add(Data *&key);				// Вставка элемента в кучу
	void addSet(Data **key, int num);	// Вставка массива элементов в кучу

	Data* erase();						// Изъятие элемента
	Data* erase(int i);					// Изъятие i-го элемента

	void transposition(int i, int j);	// Обмен значений 
	void surfacing(int i);				// Всплытие
	void immersion(int i);				// Погружение

	void hilling();						// Окучивание

private:
	int minChild(int i);				// Поиск минимального потомка
};

