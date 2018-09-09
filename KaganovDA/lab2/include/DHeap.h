#pragma once
#include <iostream> 
#include <algorithm>
#include "Graph.h"

#define maxSize 1000
typedef int dataType;

class Data {
public:
	float priorities;
};

class DHeap {
protected:
	Data **keys;
	int d;
	int idx;
public:
	DHeap(int d);
	DHeap(const DHeap &heap);
	~DHeap();

	void Add(Data *&key);
	void AddSet(Data **key, int num);
	Data* Delete();
	Data* Remove(int i);					//изъ€тие узла i

	void Transpose(int i, int j);			//перестаовка
	void Surfacing(int i);					//всплытие
	void Sinking(int i);					//погружение
	void Hilling();							//окучивание
	int IsFull()const;
	int IsEmpty()const;

private:
	int MinChild(int i);					//погружение узла i
};
