#pragma once
#include "Graph.h"
#include "DHeap.h"
#include "PriorityQueue.h"
#include <cfloat>

class DataFloat : public Data {
public:
	DataFloat(int s, float dist);
	int s;								//стартовый элемент
};

class Dejkstra {
public:
	static void dejkstra(Graph *&graph, int s, float *&distance, int *&up);
};
