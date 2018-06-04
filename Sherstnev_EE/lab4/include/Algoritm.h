#pragma once
#include "Graph.h"
#include "Dheap.h"
#include "priority_queue.h"

using namespace std;

class CompleteVertex : public VertexLabel
{
public:
	int v;
	CompleteVertex(int v, float dist);
};


class Algoritm
{
public:
	static void  Dijkstra(Graph*&, int, float*&,int*&);
};

