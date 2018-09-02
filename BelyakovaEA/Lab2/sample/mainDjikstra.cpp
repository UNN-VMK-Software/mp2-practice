#include "dheap.h"
#include "Graph.h"
#include "Dijkstra.h"

#include <stdio.h>

const int SIZE = 10;


int main()
{
	int d = 4;

	int nVertex = 4;

	int nEdges = 5;

	if (nEdges <= 0 || nVertex <= 0)
	{
		printf("ERROR: Number of edges and verteces must be positive!\n");
		return 1;
	}

	Graph graph(nVertex, nEdges);

	printf("Dijkstra\n");
	VertexDist *result = Dijkstra::DijkstraSearch(graph);

	printf("Result:\n");
	for (int i = 0; i < graph.GetVertexNum(); ++i)
	{
		printf("Vertex: %d, up: %d, ", result[i].vertex, result[i].upVertex);

		if (result[i].dist >= graph.GetSumOfWeights())
		{
			printf("UNREACHABLE\n");
		}

		else
		{
			printf("dist: %f\n", result[i].dist);
		}
	}

	delete[] result;

	return 0;
}