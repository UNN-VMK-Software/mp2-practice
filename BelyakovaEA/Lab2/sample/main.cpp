#include "dheap.h"
#include "PyrSort.h"
#include "Graph.h"
#include "Dijkstra.h"
#include "Kruskal.h"

#include <stdio.h>

const int SIZE = 10;


int main()
{
	//TODO: arnost
	int d = 4;
	//TODO: vertex num
	int nVertex = 4;

	//TODO: nEdges
	int nEdges = 5;

	if (nEdges <= 0 || nVertex <= 0)
	{
		printf("ERROR: Number of edges and verteces must be positive!\n");
		return 1;
	}

	//printf("Sort\n");
	int *arr = new int[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = i;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d; ", arr[i]);
	}
	printf("\n");

	DHeap<int> *heap = new DHeap<int>(arr, d, SIZE);
	printf("Sort\n");
	PyrSort(heap);

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d; ", arr[i]);
	}

	printf("\n");

	delete heap;
	delete[] arr;
	//

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

	printf("Kruskal\n");
	VertexDist* dheapValues = new VertexDist[graph.GetVertexNum()];
	PriorityQueueDHeap<VertexDist>* vdHeap = new PriorityQueueDHeap<VertexDist>(dheapValues, d, 0);
	Graph* tree = Algorithms<VertexDist>::Kruskal(graph, vdHeap);

	printf("Result:\n");
	tree->Print();
	//	delete tree;

	int c;
	getchar();
	return 0;
}