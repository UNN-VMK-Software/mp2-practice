#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int nVertex, int nEdges, bool doGenerateEdges)
{
	this->nVertex = nVertex;
	this->sumOfWeights = 1.0;
	edges.reserve(nEdges);

	if (doGenerateEdges)
	{
		GenerateEdges(nEdges);
	}
}


int Graph::GetVertexNum() const { return nVertex; }
int Graph::GetEdgesNum() const { return edges.size(); }


void Graph::AddEdge(int start, int finish, double weight)
{
	sumOfWeights += weight;
	printf("AddEdge\n");
	edges.push_back(Edge(start, finish, weight));
}

double Graph::generateWeight(double minRange, double maxRange)
{
	double d = minRange;
	double c = (double)(maxRange - minRange) / RAND_MAX;
	double result = c * rand() + d;
	return result;
}

void Graph::Print()
{
	printf("Graph:\n");
	for (int i = 0; i < edges.size(); ++i)
	{
		printf("Edge %d: %d -> %d with %f\n", i, edges[i].Ne, edges[i].Ke, edges[i].W);
	}
}

NeighboorVector Graph::GetNeigboors(int vertex) const
{
	NeighboorVector result;
	for (int i = 0; i < edges.size(); ++i)
	{
		if (edges[i].Ke == vertex || edges[i].Ne == vertex)
		{
			Neighboor nv;
			nv.edgeWeight = edges[i].W;

			if (edges[i].Ke == vertex)
			{
				nv.vertex = edges[i].Ne;
			}

			else
			{
				nv.vertex = edges[i].Ke;
			}

			result.push_back(nv);
		}
	}

	return result;
}

void Graph::GenerateEdges(int nEdges) {
	int currentEdgesNum = 0;

	while (edges.size() < nEdges)
	{
		bool fail = false;
		int n = rand() % nVertex;
		int k = rand() % nVertex;

		//The same vertex - try again
		if (n == k)
		{
			continue;
		}

		//This edge already exists
		for (int i = 0; i < edges.size(); ++i)
		{
			if ((edges[i].Ke == n) && (edges[i].Ne == k) ||
				(edges[i].Ne == n) && (edges[i].Ke == k))
			{
				fail = true;
				break;
			}
		}

		if (fail)
		{
			continue;
		}

		//This is a new edge
		double W = generateWeight();
		sumOfWeights += W;
		edges.push_back(Edge(n, k, W));
	}

	//print graph
	Print();
	printf("\n\n");
}