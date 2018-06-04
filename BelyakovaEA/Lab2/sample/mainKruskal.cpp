#include "Kruskal.h"
#include <stdio.h>
#include "PriorituQueue.h"
#include "Graph.h"
#include "edge.h"
#include "dheap.h"

int main() {
	printf("Kruskal\n");

	int d = 4;
	int nVertex = 4;
	int nEdges = 5;
	if (nEdges <= 0 || nVertex <= 0)
	{
		printf("ERROR: Number of edges and verteces must be positive!\n");
		return 1;
	}

	Graph graph(nVertex, nEdges);
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