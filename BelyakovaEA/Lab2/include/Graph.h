#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <algorithm>

struct Neighboor  //для соседей графа 
{
	int vertex;  
	double edgeWeight;
};

typedef std::vector<Neighboor> NeighboorVector;

class Graph
{
public:
	Graph(int nVertex, int nEdges, bool doGenerateEdges = true);
	~Graph() {}

	int GetVertexNum() const;
	int GetEdgesNum() const;
	double Graph::GetSumOfWeights() const { return sumOfWeights; }

	Edge GetEdge(int idx) const {/* printf("n: %d, k: %d\n", edges[idx].Ne, edges[idx].Ke);*/  return edges[idx]; }

	void AddEdge(int start, int finish, double weight);

	NeighboorVector GetNeigboors(int vertex) const; //поиск сосед

	void Print();

private:
	double generateWeight(double minRangw = 0.01, double maxRange = 10.0);
	void GenerateEdges(int nEdges);

	int nVertex;
	std::vector<Edge> edges;

	double sumOfWeights;
};

#endif