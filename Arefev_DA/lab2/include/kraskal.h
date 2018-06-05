#pragma once
#include "graph.h"
#include "priority_queue_based_dheap.h"

class AlgoritmKraskala
{
public:
	Edge* Kraskal(Graph*g,PriorityQueue<Edge>* q);
};