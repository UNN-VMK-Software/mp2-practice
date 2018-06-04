#pragma once

#include "Graph.h"
#include "D-Heap.h"
#include "Priority-Queue.h"
#include <cfloat>

class DataFloat : public Data
{
public:
	DataFloat(int v, float dist);
	int v;
};

class Dijkstra
{
public:
	static void dijkstra(Graph *&graph, int s, float *&distance, int *&up);
};
