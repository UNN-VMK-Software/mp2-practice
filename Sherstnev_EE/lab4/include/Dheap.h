#pragma once

#include <iostream>
#include <cmath>

#define max_heap 10000

using namespace std;


class VertexLabel
{
public:

	float label;

};



class Dheap
{
private:

	VertexLabel** labels;
	int d; 
	int lastidx;
public:
	Dheap(int);
	~Dheap();
	void transpose(int, int);
	void add(VertexLabel*&);
	void addSet(VertexLabel **key, int num);
	VertexLabel* erase(int);
	void surfacing(int);
	void sinking(int);
	void spudding();
	int isFull();
	int isEmpty();
	int minChild(int);
};

