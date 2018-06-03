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
	int lastIdx;			
public:
	DHeap(int d);
	DHeap(const DHeap &heap);
	~DHeap();
	void add(Data *&key);
	void addSet(Data **key, int num);
	Data* erase();
	Data* erase(int i);
	void transposition(int i, int j);
	void surfacing(int i);
	void immersion(int i);
	void spudding();
	int isFull();
	int isEmpty();
private:
	int minChild(int i);
};