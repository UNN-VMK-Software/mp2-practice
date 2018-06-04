#pragma once
#include "graph.h"
#include "d-heap.h"
#include "priority-queue.h"
#include <cfloat>

class DataFloat : public Data {
public:
	DataFloat(int v, float dist);
	int v;
};

class Dijkstra {
public:
	static void dijkstra(Graph *&graph, int s, float *&distance, int *&up);
};