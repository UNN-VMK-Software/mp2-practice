#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "edge.h"
#include "Graph.h"

class Dijkstra {
public:
	static VertexDist* DijkstraSearch(const Graph& graph);
};


#endif
